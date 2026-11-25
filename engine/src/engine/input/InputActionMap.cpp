//
// Created by whitemaks on 16.11.2026.
//

#include <engine/input/InputActionMap.h>

namespace input {
	InputContext &InputActionMap::addContext(std::string name) {
		return _contexts.try_emplace(std::move(name)).first->second;
	}

	bool InputActionMap::removeContext(const std::string &name) {
		if (_activeContext == name) {
			_activeContext.clear();
		}

		return _contexts.erase(name) > 0;
	}

	bool InputActionMap::setActiveContext(const std::string &name) {
		if (!_contexts.contains(name)) {
			return false;
		}

		_activeContext = name;
		return true;
	}

	bool InputActionMap::isActionDown(const std::string &name, const Mouse &mouse, const Keyboard &keyboard) {
		return evaluate(name, keyboard, mouse, ButtonQuery::Down);
	}

	bool InputActionMap::wasActionPressed(const std::string &name, const Mouse &mouse, const Keyboard &keyboard) {
		return evaluate(name, keyboard, mouse, ButtonQuery::Pressed);
	}

	bool InputActionMap::wasActionReleased(const std::string &name, const Mouse &mouse, const Keyboard &keyboard) {
		return evaluate(name, keyboard, mouse, ButtonQuery::Released);
	}

	bool InputActionMap::evaluate(const std::string &name, const Keyboard &keyboard, const Mouse &mouse,
	                              ButtonQuery query) {
		const auto inputs = _contexts.find(_activeContext);

		if (inputs == _contexts.end()) {
			return false;
		}

		if (!inputs->second.hasAction(name)) {
			return false;
		}

		for (const auto &action: inputs->second.getActions(name)) {
			const bool active = std::visit(
				[&keyboard, &mouse, query](const auto &value) {
					return evaluateAction(
						value, keyboard, mouse, query
					);
				},
				action
			);

			if (active) {
				return true;
			}
		}

		return false;
	}

	bool InputActionMap::evaluateAction(const KeyboardBinding &binding, const Keyboard &keyboard, const Mouse &mouse, const ButtonQuery query) {
		switch (query) {
			case ButtonQuery::Down:
				return keyboard.isButtonDown(binding.button);

			case ButtonQuery::Pressed:
				return keyboard.wasButtonPressed(binding.button);

			case ButtonQuery::Released:
				return keyboard.wasButtonReleased(binding.button);
		}

		return false;
	}

	bool InputActionMap::evaluateAction(const MouseBinding &binding, const Keyboard &keyboard, const Mouse &mouse, ButtonQuery query) {
		switch (query) {
			case ButtonQuery::Down:
				return mouse.isButtonDown(binding.button);

			case ButtonQuery::Pressed:
				return mouse.wasButtonPressed(binding.button);

			case ButtonQuery::Released:
				return mouse.wasButtonReleased(binding.button);
		}

		return false;
	}
}
