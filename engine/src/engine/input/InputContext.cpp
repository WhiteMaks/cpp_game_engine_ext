//
// Created by whitemaks on 15.11.2026.
//

#include <engine/input/InputContext.h>

namespace input {
	void InputContext::addAction(std::string name, const KeyboardButton button) {
		_actions[std::move(name)].emplace_back(
			KeyboardBinding{
				.button = button,
			}
		);
	}

	void InputContext::addAction(std::string name, const MouseButton button) {
		_actions[std::move(name)].emplace_back(
			MouseBinding{
				.button = button,
			}
		);
	}

	void InputContext::removeAction(const std::string &name) {
		_actions.erase(name);
	}

	void InputContext::destroy() {
		_actions.clear();
	}

	const std::vector<InputBinding>& InputContext::getActions(const std::string &name) {
		return _actions[name];
	}

	bool InputContext::hasAction(const std::string &name) const {
		return _actions.contains(name);
	}
}
