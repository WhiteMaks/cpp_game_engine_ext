//
// Created by whitemaks on 24.10.2026.
//

#include <platform/desktop/DesktopApplicationHost.h>

namespace platform {
	DesktopApplicationHost::DesktopApplicationHost(engine::Application &application)
		: ApplicationHost(application) {
	}

	void DesktopApplicationHost::run() {
		_application.init();

		//window !should close
		while (true) {
			_application.input();
			_application.update();
			_application.render();
		}

		_application.shutdown();
	}
}
