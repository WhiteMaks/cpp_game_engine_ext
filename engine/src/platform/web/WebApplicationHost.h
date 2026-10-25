//
// Created by whitemaks on 25.10.2026.
//

#pragma once

#include <engine/ApplicationHost.h>

namespace platform {
	class WebApplicationHost : public engine::ApplicationHost {
	public:
		explicit WebApplicationHost(engine::Application &application);

	public:
		void run() override;

		static void frame(void* arg);
	};
}