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
		_window->setEventCallback(
			[this](const event::Event& event) {
				onEvent(event);
			}
		);

		_window->init();
	}

	void Application::input() {
		_window->input();
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

	void Application::onEvent(const event::Event &event) {
		std::visit([this]<typename T0>(const T0& e) {
			using T = std::decay_t<T0>;

			if constexpr (std::is_same_v<T, event::WindowClosedEvent>) {
				_shouldClose = true;
			}
			else if constexpr (std::is_same_v<T, event::WindowResizedEvent>) {
			}
			else if constexpr (std::is_same_v<T, event::WindowFocusedEvent>) {
			}
			else if constexpr (std::is_same_v<T, event::WindowUnfocusedEvent>) {
			}

		}, event);
	}
}
