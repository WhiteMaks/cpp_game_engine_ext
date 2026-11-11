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

		onInit();
	}

	void Application::input() {
		_window->input();
	}

	void Application::update() {
		onUpdate();
	}

	void Application::render() {
		onRender();
	}

	void Application::destroy() {
		_window->destroy();

		onDestroy();
	}

	bool Application::shouldClose() const {
		return _shouldClose;
	}

	void Application::onInit() {
	}

	void Application::onUpdate() {
	}

	void Application::onRender() {
	}

	void Application::onDestroy() {
	}

	void Application::onEvent(const event::Event &event) {
		std::visit([this](const auto& e) {
			onEvent(e);
		}, event);
	}

	void Application::onEvent(const event::WindowClosedEvent &event) {
		_shouldClose = true;
	}

	void Application::onEvent(const event::WindowResizedEvent &event) {
	}

	void Application::onEvent(const event::WindowFramebufferResizedEvent &event) {
	}

	void Application::onEvent(const event::WindowFocusedEvent &event) {
	}

	void Application::onEvent(const event::WindowUnfocusedEvent &event) {
	}

	void Application::onEvent(const event::KeyboardButtonPressedEvent &event) {
	}

	void Application::onEvent(const event::KeyboardButtonReleasedEvent &event) {
	}

	void Application::onEvent(const event::MouseMovedEvent &event) {
	}

	void Application::onEvent(const event::MouseButtonPressedEvent &event) {
	}

	void Application::onEvent(const event::MouseButtonReleasedEvent &event) {
	}

	void Application::onEvent(const event::MouseScrolledEvent &event) {
	}
}
