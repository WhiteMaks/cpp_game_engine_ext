//
// Created by whitemaks on 08.11.2026.
//

#pragma once

#include <cstdint>

namespace event {
	struct WindowResizedEvent {
		std::uint32_t width = 0;
		std::uint32_t height = 0;
	};

	struct WindowFramebufferResizedEvent {
		std::uint32_t width = 0;
		std::uint32_t height = 0;
	};

	struct WindowClosedEvent {
	};

	struct WindowFocusedEvent {
	};

	struct WindowUnfocusedEvent {
	};
}
