//
// Created by whitemaks on 08.11.2026.
//

#include <stdexcept>

#include <platform/sdl3/Sdl3Window.h>

namespace platform {
	Sdl3Window::Sdl3Window(const engine::WindowDesc &desc) : Window(desc), _window(nullptr) {
	}

	void Sdl3Window::init() {
		SDL_SetHint(SDL_HINT_VIDEO_DRIVER, "x11");

		if (!SDL_Init(SDL_INIT_VIDEO)) {
			throw std::runtime_error(SDL_GetError());
		}

		_window = SDL_CreateWindow(
			_desc.title.c_str(),
			static_cast<int>(_desc.size.width),
			static_cast<int>(_desc.size.height),
			SDL_WINDOW_RESIZABLE
		);

		if (!_window) {
			SDL_QuitSubSystem(SDL_INIT_VIDEO);
			throw std::runtime_error(SDL_GetError());
		}
	}

	void Sdl3Window::input() {
		SDL_Event event;

		while (SDL_PollEvent(&event)) {
			switch (event.type) {
				case SDL_EVENT_QUIT:
					_eventCallback(event::WindowClosedEvent{});
					break;

				case SDL_EVENT_WINDOW_CLOSE_REQUESTED:
					if (event.window.windowID == SDL_GetWindowID(_window)) {
						_eventCallback(event::WindowClosedEvent{});
					}
					break;

				case SDL_EVENT_WINDOW_RESIZED:
					_eventCallback(event::WindowResizedEvent{
						static_cast<std::uint32_t>(event.window.data1),
						static_cast<std::uint32_t>(event.window.data2)
					});
					break;

				case SDL_EVENT_WINDOW_FOCUS_GAINED:
					_eventCallback(event::WindowFocusedEvent{});
					break;

				case SDL_EVENT_WINDOW_FOCUS_LOST:
					_eventCallback(event::WindowUnfocusedEvent{});
					break;

				default:
					break;
			}
		}
	}

	void Sdl3Window::destroy() {
		if (_window) {
			SDL_DestroyWindow(_window);
			_window = nullptr;
		}

		SDL_QuitSubSystem(SDL_INIT_VIDEO);
	}
}
