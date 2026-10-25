//
// Created by whitemaks on 26.09.2026.
//

#include <memory>

#include <engine/Application.h>
#include <engine/ApplicationHost.h>
#include <engine/ApplicationHostFactory.h>

int main()
{
	engine::Application application;
	const std::unique_ptr<engine::ApplicationHost> application_host = engine::ApplicationHostFactory::create(application);
	application_host->run();

	return 0;
}