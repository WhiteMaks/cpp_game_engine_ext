//
// Created by whitemaks on 15.11.2026.
//

#include <engine/input/InputContex.h>

namespace input {
	void InputContex::addBinding(std::string name, const KeyboardButton button) {
		_bindings[std::move(name)].emplace_back(
			KeyboardBinding{
				.button = button,
			}
		);
	}

	void InputContex::addBinding(std::string name, const MouseButton button) {
		_bindings[std::move(name)].emplace_back(
			MouseBinding{
				.button = button,
			}
		);
	}

	void InputContex::removeBinding(const std::string &name) {
		_bindings.erase(name);
	}

	void InputContex::destroy() {
		_bindings.clear();
	}
}
