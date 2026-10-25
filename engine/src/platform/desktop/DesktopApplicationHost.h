//
// Created by whitemaks on 24.10.2026.
//

#pragma once

#include <engine/ApplicationHost.h>

namespace platform {
	class DesktopApplicationHost : public engine::ApplicationHost {
	public:
		explicit DesktopApplicationHost(engine::Application &application);

	public:
		void run() override;
	};
}
