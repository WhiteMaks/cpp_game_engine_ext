//
// Created by whitemaks on 07.11.2026.
//

#include <engine/WindowFactory.h>

namespace engine {
	std::unique_ptr<Window> WindowFactory::create(const WindowDesc& desc) {
		return std::make_unique<Window>(desc);
	}
}
