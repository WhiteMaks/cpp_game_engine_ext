//
// Created by whitemaks on 26.09.2026.
//

#include <engine/Application.h>
#include <engine/ApplicationHost.h>

int main()
{
	engine::Application application;
	engine::ApplicationHost application_host(application);
	application_host.run();

	return 0;
}