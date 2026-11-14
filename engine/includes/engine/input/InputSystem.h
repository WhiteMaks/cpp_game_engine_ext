//
// Created by whitemaks on 14.11.2026.
//

#pragma once

#include <engine/input/Keyboard.h>
#include <engine/input/Mouse.h>

namespace input {
	class InputSystem {
	public:
		static bool isKeyboardButtonPressed(const KeyboardButton &button);
	};
}
