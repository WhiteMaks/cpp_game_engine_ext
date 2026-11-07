//
// Created by whitemaks on 07.11.2026.
//

#include <engine/Window.h>

#include <utility>

namespace engine {
	Window::Window(WindowDesc desc) : _desc(std::move(desc)) {
	}

	void Window::init() {
	}

	void Window::input() {
	}

	void Window::destroy() {
	}
}
