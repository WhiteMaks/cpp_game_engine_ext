//
// Created by whitemaks on 24.10.2026.
//

#pragma once

#include <memory>

#include <engine/Application.h>
#include <engine/ApplicationHost.h>

namespace engine {
	class ApplicationHostFactory {
	public:
		static std::unique_ptr<ApplicationHost> create(Application &application);
	};
}
