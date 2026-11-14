//
// Created by whitemaks on 07.11.2026.
//

#pragma once

#include <functional>
#include <string>

#include <engine/event/Event.h>

namespace engine {
	struct WindowSize {
		unsigned int width;
		unsigned int height;
	};

	struct WindowDesc {
		std::string title;
		WindowSize size;
	};

	using EventCallback = std::function<void(const event::Event&)>;

	class Window {
	protected:
		const WindowDesc _desc;
		EventCallback _eventCallback;

	public:
		explicit Window(WindowDesc desc);

		virtual ~Window() = default;

	public:
		virtual void init();

		virtual void input();

		virtual void destroy();

		void setEventCallback(EventCallback callback);
	};
}
