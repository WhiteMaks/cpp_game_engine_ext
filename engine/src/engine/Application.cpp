//
// Created by whitemaks on 26.09.2026.
//

#include <engine/Application.h>

namespace engine
{
	Application::Application(std::unique_ptr<Window> window) : _window(std::move(window)) {
		_shouldClose = false;
	}

	Application::~Application() {
	}

	void Application::init() {
		_window->init();
	}

	void Application::input() {
		_window->input();
		_shouldClose = true;
	}

	void Application::update() {
	}

	void Application::render() {
	}

	void Application::destroy() {
		_window->destroy();
	}

	bool Application::shouldClose() const {
		return _shouldClose;
	}
}
