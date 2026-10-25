//
// Created by whitemaks on 24.10.2026.
//

#include <engine/ApplicationHostFactory.h>

#if defined(__EMSCRIPTEN__)
#include <platform/web/WebApplicationHost.h>
#elif defined(__ANDROID__)
#include <platform/android/AndroidApplicationHost.h>
#elif defined(__APPLE__) && TARGET_OS_IPHONE
#include <platform/ios/IOSApplicationHost.h>
#elif defined(_WIN32) || defined(__linux__) || (defined(__APPLE__) && TARGET_OS_OSX)
#include <platform/desktop/DesktopApplicationHost.h>
#else
#error "Unsupported platform"
#endif

namespace engine {
	std::unique_ptr<ApplicationHost> ApplicationHostFactory::create(Application &application) {
#if defined(__EMSCRIPTEN__)
		return std::make_unique<platform::WebApplicationHost>(application);
#elif defined(__ANDROID__)
		return std::make_unique<platform::AndroidApplicationHost>(application);
#elif defined(__APPLE__) && TARGET_OS_IPHONE
		return std::make_unique<platform::IOSApplicationHost>(application);
#elif defined(_WIN32) || defined(__linux__) || (defined(__APPLE__) && TARGET_OS_OSX)
		return std::make_unique<platform::DesktopApplicationHost>(application);
#endif
	}
}
