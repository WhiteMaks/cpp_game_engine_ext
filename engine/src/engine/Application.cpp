//
// Created by whitemaks on 26.09.2026.
//

#include <engine/Application.h>

namespace engine
{
	Application::Application() {
		_shouldClose = false;
	}

	Application::~Application() {
	}

	void Application::init() {
	}

	void Application::input() {
		_shouldClose = true;
	}

	void Application::update() {
	}

	void Application::render() {
	}

	void Application::shutdown() {
	}

	bool Application::shouldClose() const {
		return _shouldClose;
	}
}
