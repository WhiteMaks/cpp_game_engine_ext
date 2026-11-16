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

	class InputContext {
	private:
		std::unordered_map<std::string, std::vector<InputBinding>> _actions;

	public:
		void addAction(std::string name, KeyboardButton button);

		void addAction(std::string name, MouseButton button);

		void removeAction(const std::string &name);

		void destroy();

		[[nodiscard]] bool hasAction(const std::string &name) const;

		[[nodiscard]] const std::vector<InputBinding>& getActions(const std::string &name);
	};
}
