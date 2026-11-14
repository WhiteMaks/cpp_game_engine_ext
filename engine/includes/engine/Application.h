//
// Created by whitemaks on 26.09.2026.
//

#pragma once

#include <memory>

#include <engine/Window.h>

namespace engine {
	class Application {
	private:
		const std::unique_ptr<Window> _window;

		bool _shouldClose;

	public:
		explicit Application(std::unique_ptr<Window> window);

		virtual ~Application();

	public:
		void init();

		void input();

		void update();

		void render();

		void destroy();

		bool shouldClose() const;

	protected:
		void virtual onInit();

		void virtual onUpdate();

		void virtual onRender();

		void virtual onDestroy();

	private:
		void onEvent(const event::Event& event);

		void onEvent(const event::WindowClosedEvent& event);

		void onEvent(const event::WindowResizedEvent& event);

		void onEvent(const event::WindowFramebufferResizedEvent& event);

		void onEvent(const event::WindowFocusedEvent& event);

		void onEvent(const event::WindowUnfocusedEvent& event);

		void onEvent(const event::KeyboardButtonPressedEvent& event);

		void onEvent(const event::KeyboardButtonReleasedEvent& event);

		void onEvent(const event::MouseMovedEvent& event);

		void onEvent(const event::MouseButtonPressedEvent& event);

		void onEvent(const event::MouseButtonReleasedEvent& event);

		void onEvent(const event::MouseScrolledEvent& event);
	};
}
