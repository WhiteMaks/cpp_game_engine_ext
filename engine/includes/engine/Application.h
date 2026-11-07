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

	public:
		explicit Application(std::unique_ptr<Window> window);

		~Application();

	private:
		bool _shouldClose;

	public:
		void init();

		void input();

		void update();

		void render();

		void destroy();

		bool shouldClose() const;
	};
}
