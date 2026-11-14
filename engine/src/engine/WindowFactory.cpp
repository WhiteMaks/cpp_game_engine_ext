//
// Created by whitemaks on 07.11.2026.
//

#include <engine/WindowFactory.h>

#ifdef ENGINE_WINDOW_BACKEND_SDL3
#include <platform/sdl3/Sdl3Window.h>
#endif

namespace engine {
	std::unique_ptr<Window> WindowFactory::create(const WindowDesc& desc) {
#ifdef ENGINE_WINDOW_BACKEND_SDL3
		return std::make_unique<platform::Sdl3Window>(desc);
#else
		return std::make_unique<Window>(desc);
#endif
	}
}
