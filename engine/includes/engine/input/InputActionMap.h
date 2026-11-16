//
// Created by whitemaks on 16.11.2026.
//

#pragma once

#include <string>
#include <unordered_map>

#include <engine/input/InputContext.h>
#include <engine/input/Keyboard.h>
#include <engine/input/Mouse.h>

namespace input {
	enum class ButtonQuery {
		Down,
		Pressed,
		Released
	};

	class InputActionMap {
	private:
		std::unordered_map<std::string, InputContext> _contexts;
		std::string _activeContext;

	public:
		InputContext &addContext(std::string name);

		[[nodiscard]] bool removeContext(const std::string &name);

		[[nodiscard]] bool setActiveContext(const std::string &name);

		[[nodiscard]] bool isActionDown(const std::string &name, const Mouse &mouse, const Keyboard &keyboard);

		[[nodiscard]] bool wasActionPressed(const std::string &name, const Mouse &mouse, const Keyboard &keyboard);

		[[nodiscard]] bool wasActionReleased(const std::string &name, const Mouse &mouse, const Keyboard &keyboard);

	private:
		[[nodiscard]] bool evaluate(const std::string &name, const Keyboard &keyboard, const Mouse &mouse, ButtonQuery query);

		[[nodiscard]] static bool evaluateAction(const KeyboardBinding &binding, const Keyboard &keyboard, const Mouse &mouse, ButtonQuery query);

		[[nodiscard]] static bool evaluateAction(const MouseBinding &binding, const Keyboard &keyboard, const Mouse &mouse, ButtonQuery query);
	};
}
