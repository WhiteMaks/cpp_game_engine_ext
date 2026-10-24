//
// Created by whitemaks on 24.10.2026.
//

#pragma once

#include <engine/Application.h>

namespace engine {
	class ApplicationHost {
	public:
		explicit ApplicationHost(Application &application);

		virtual ~ApplicationHost() = default;

	protected:
		Application &_application;

	public:
		virtual void run();
	};
}
