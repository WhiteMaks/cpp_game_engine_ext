//
// Created by whitemaks on 26.09.2026.
//

#include <memory>

#include <engine/WindowFactory.h>
#include <engine/Application.h>
#include <engine/ApplicationHost.h>
#include <engine/ApplicationHostFactory.h>

namespace {
	class SandboxApplication : public engine::Application {
	public:
		using Application::Application;

	protected:
		void onInit() override {

		}

		void onUpdate() override {

		}

		void onRender() override {

		}

		void onDestroy() override {

		}
	};
}


int main() {
	engine::WindowDesc window_desc = {
		.title = "First window",
		.size = {
			.width = 1280,
			.height = 720
		}
	};

	SandboxApplication application(engine::WindowFactory::create(window_desc));

	auto application_host =
		engine::ApplicationHostFactory::create(application);

	application_host->run();

	return 0;
}
