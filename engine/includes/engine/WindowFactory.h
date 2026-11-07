//
// Created by whitemaks on 07.11.2026.
//

#pragma once

#include <memory>

#include <engine/Window.h>

namespace engine {
	class WindowFactory {
	public:
		static std::unique_ptr<Window> create(const WindowDesc& desc);
	};
}
