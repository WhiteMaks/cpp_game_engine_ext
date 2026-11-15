//
// Created by whitemaks on 15.11.2026.
//

#pragma once

#include <string>
#include <unordered_map>
#include <variant>
#include <vector>

#include <engine/input/Keyboard.h>
#include <engine/input/Mouse.h>

namespace input {
	struct KeyboardBinding {
		KeyboardButton button;
	};

	struct MouseBinding {
		MouseButton button;
	};

	using InputBinding = std::variant<
		KeyboardBinding,
		MouseBinding
	>;

	class InputContex {
	private:
		std::unordered_map<std::string, std::vector<InputBinding>> _bindings;

	public:
		void addBinding(std::string name, KeyboardButton button);

		void addBinding(std::string name, MouseButton button);

		void removeBinding(const std::string &name);

		void destroy();
	};
}
