//
// Created by whitemaks on 08.11.2026.
//

#pragma once

#include <variant>

#include <engine/event/KeyboardEvent.h>
#include <engine/event/MouseEvent.h>
#include <engine/event/WindowEvent.h>

namespace event {
	using Event = std::variant<
		KeyboardButtonPressedEvent,
		KeyboardButtonReleasedEvent,

		MouseMovedEvent,
		MouseButtonPressedEvent,
		MouseButtonReleasedEvent,
		MouseScrolledEvent,

		WindowResizedEvent,
		WindowFramebufferResizedEvent,
		WindowClosedEvent,
		WindowFocusedEvent,
		WindowUnfocusedEvent
	>;
}
