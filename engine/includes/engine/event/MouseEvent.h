//
// Created by whitemaks on 08.11.2026.
//

#pragma once

#include <cstdint>

namespace event {
	enum class MouseButton : std::uint8_t
	{
		Unknown = 0,

		Left,
		Right,
		Middle,

		Button4,
		Button5,
		Button6,
		Button7,
		Button8
	};

	struct MouseMovedEvent
	{
		float x = 0.0f;
		float y = 0.0f;
	};

	struct MouseButtonPressedEvent
	{
		MouseButton button = MouseButton::Unknown;
	};

	struct MouseButtonReleasedEvent
	{
		MouseButton button = MouseButton::Unknown;
	};

	struct MouseScrolledEvent
	{
		float xOffset = 0.0f;
		float yOffset = 0.0f;
	};
}
