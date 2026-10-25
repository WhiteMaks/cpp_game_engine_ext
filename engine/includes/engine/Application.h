//
// Created by whitemaks on 26.09.2026.
//

#pragma once

namespace engine {
	class Application {
	public:
		Application();

		~Application();

	private:
		bool _shouldClose;

	public:
		void init();

		void input();

		void update();

		void render();

		void shutdown();

		bool shouldClose() const;
	};
}
