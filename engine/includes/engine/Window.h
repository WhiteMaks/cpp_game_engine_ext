//
// Created by whitemaks on 07.11.2026.
//

#pragma once

#include <string>

namespace engine {
	struct WindowSize {
		unsigned int width;
		unsigned int height;
	};

	struct WindowDesc {
		std::string title;
		WindowSize size;
	};

	class Window {
	private:
		const WindowDesc _desc;

	public:
		explicit Window(WindowDesc desc);

		virtual ~Window() = default;

	public:
		virtual void init();

		virtual void input();

		virtual void destroy();
	};
}
