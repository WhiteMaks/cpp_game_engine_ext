//
// Created by whitemaks on 26.09.2026.
//

#include <memory>

#include <engine/WindowFactory.h>
#include <engine/Application.h>
#include <engine/ApplicationHost.h>
#include <engine/ApplicationHostFactory.h>

int main() {
	engine::WindowDesc window_desc = {
		.title = "First window",
		.size = {
			.width = 1280,
			.height = 730
		}
	};
	std::unique_ptr<engine::Window> window = engine::WindowFactory::create(window_desc);

	engine::Application application(std::move(window));
	const std::unique_ptr<engine::ApplicationHost> application_host =
			engine::ApplicationHostFactory::create(application);
	application_host->run();

	return 0;
}
