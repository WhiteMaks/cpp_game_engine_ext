//
// Created by whitemaks on 24.10.2026.
//

#include <engine/ApplicationHost.h>

namespace engine {

	ApplicationHost::ApplicationHost(Application &application)
		: _application(application) {
	}

	void ApplicationHost::run() {
		_application.init();
		_application.beginFrame();
		_application.update();
		_application.render();
		_application.endFrame();
		_application.destroy();
	}
}
