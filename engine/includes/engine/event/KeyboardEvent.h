//
// Created by whitemaks on 08.11.2026.
//

#pragma once

#include <engine/input/Keyboard.h>

namespace event {
	struct KeyboardButtonPressedEvent
	{
		input::KeyboardButton button = input::KeyboardButton::Unknown;
		bool repeat = false;
	};

	struct KeyboardButtonReleasedEvent
	{
		input::KeyboardButton button = input::KeyboardButton::Unknown;
	};
}
