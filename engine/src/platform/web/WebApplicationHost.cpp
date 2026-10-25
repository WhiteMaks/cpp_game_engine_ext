//
// Created by whitemaks on 25.10.2026.
//

#include <emscripten.h>

#include <platform/web/WebApplicationHost.h>

namespace platform {
	WebApplicationHost::WebApplicationHost(engine::Application &application)
		: ApplicationHost(application) {
	}

	void WebApplicationHost::run() {
		_application.init();

		emscripten_set_main_loop_arg(
			&WebApplicationHost::frame,
			this,
			0,
			false
		);
	}

	void WebApplicationHost::frame(void* arg) {
		const auto* instance = static_cast<WebApplicationHost*>(arg);

		if (instance->_application.shouldClose())
		{
			emscripten_cancel_main_loop();
			instance->_application.shutdown();
			return;
		}

		instance->_application.input();
		instance->_application.update();
		instance->_application.render();
	}
}
