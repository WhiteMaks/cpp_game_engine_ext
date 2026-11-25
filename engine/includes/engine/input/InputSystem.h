//
// Created by whitemaks on 14.11.2026.
//

#pragma once

#include <engine/event/KeyboardEvent.h>
#include <engine/event/MouseEvent.h>

#include "InputActionMap.h"

namespace input {
	class InputSystem {
	private:
		Keyboard _keyboard;
		Mouse _mouse;
		InputActionMap _inputActionMap;

	public:
		void beginFrame();

		void endFrame();

		void onEvent(const event::KeyboardButtonPressedEvent& event);

		void onEvent(const event::KeyboardButtonReleasedEvent& event);

		void onEvent(const event::MouseButtonPressedEvent& event);

		void onEvent(const event::MouseButtonReleasedEvent& event);

		void onEvent(const event::MouseScrolledEvent& event);

		void onEvent(const event::MouseMovedEvent& event);

		[[nodiscard]] bool isActionDown(const std::string &name);

		[[nodiscard]] bool wasActionPressed(const std::string &name);

		[[nodiscard]] bool wasActionReleased(const std::string &name);

		[[nodiscard]] Keyboard& getKeyboard() noexcept;

		[[nodiscard]] Mouse& getMouse() noexcept;

		[[nodiscard]] InputActionMap& getInputActionMap() noexcept;
	};
}
