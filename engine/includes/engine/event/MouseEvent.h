//
// Created by whitemaks on 08.11.2026.
//

#pragma once

#include <engine/input/Mouse.h>

namespace event {
	struct MouseMovedEvent
	{
		float x = 0.0f;
		float y = 0.0f;
		float deltaX = 0.0f;
		float deltaY = 0.0f;
	};

	struct MouseButtonPressedEvent
	{
		input::MouseButton button = input::MouseButton::Unknown;
	};

	struct MouseButtonReleasedEvent
	{
		input::MouseButton button = input::MouseButton::Unknown;
	};

	struct MouseScrolledEvent
	{
		float xOffset = 0.0f;
		float yOffset = 0.0f;
	};
}
