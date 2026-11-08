//
// Created by whitemaks on 08.11.2026.
//

#pragma once

#include <SDL3/SDL.h>

#include <engine/Window.h>

namespace platform {
	class Sdl3Window final : public engine::Window {
	private:
		SDL_Window* _window;

	public:
		explicit Sdl3Window(const engine::WindowDesc &desc);

	public:
		void init() override;

		void input() override;

		void destroy() override;
	};
}
