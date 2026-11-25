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

	void Application::beginFrame() {
		_inputSystem.beginFrame();
	}

	void Application::endFrame() {
		_inputSystem.endFrame();
	}

	bool Application::shouldClose() const {
		return _shouldClose;
	}

	input::InputSystem & Application::getInputSystem() noexcept {
		return _inputSystem;
	}

	const input::InputSystem & Application::getInputSystem() const noexcept {
		return _inputSystem;
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
		_inputSystem.onEvent(event);
	}

	void Application::onEvent(const event::KeyboardButtonReleasedEvent &event) {
		_inputSystem.onEvent(event);
	}

	void Application::onEvent(const event::MouseMovedEvent &event) {
		_inputSystem.onEvent(event);
	}

	void Application::onEvent(const event::MouseButtonPressedEvent &event) {
		_inputSystem.onEvent(event);
	}

	void Application::onEvent(const event::MouseButtonReleasedEvent &event) {
		_inputSystem.onEvent(event);
	}

	void Application::onEvent(const event::MouseScrolledEvent &event) {
		_inputSystem.onEvent(event);
	}
}
