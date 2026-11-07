set(ENGINE_PROJECT_NAME engine)

set(ENGINE_PUBLIC_INCLUDES
		includes/engine/Window.h
		includes/engine/WindowFactory.h
		includes/engine/Application.h
		includes/engine/ApplicationHost.h
		includes/engine/ApplicationHostFactory.h

		includes/engine/event/Event.h
		includes/engine/event/KeyboardEvent.h
		includes/engine/event/MouseEvent.h
		includes/engine/event/WindowEvent.h
)

set(ENGINE_PRIVATE_INCLUDES
		""
)

set(ENGINE_PRIVATE_SOURCES
		src/engine/Window.cpp
		src/engine/WindowFactory.cpp
		src/engine/Application.cpp
		src/engine/ApplicationHost.cpp
		src/engine/ApplicationHostFactory.cpp

		src/engine/event/Event.cpp
		src/engine/event/KeyboardEvent.cpp
		src/engine/event/MouseEvent.cpp
		src/engine/event/WindowEvent.cpp
)

set(ENGINE_PRIVATE_PLATFORM_INCLUDES "")
set(ENGINE_PRIVATE_PLATFORM_SOURCES "")

if(ENGINE_BUILD_ALL_HOSTS)
	list(APPEND ENGINE_PRIVATE_PLATFORM_INCLUDES
			src/platform/desktop/DesktopApplicationHost.h
			src/platform/web/WebApplicationHost.h
	)
	list(APPEND ENGINE_PRIVATE_PLATFORM_SOURCES
			src/platform/desktop/DesktopApplicationHost.cpp
			src/platform/web/WebApplicationHost.cpp
	)
else()
	if(EMSCRIPTEN)
		list(APPEND ENGINE_PRIVATE_PLATFORM_INCLUDES
				src/platform/web/WebApplicationHost.h
		)
		list(APPEND ENGINE_PRIVATE_PLATFORM_SOURCES
				src/platform/web/WebApplicationHost.cpp
		)
	elseif(ANDROID)
		list(APPEND ENGINE_PRIVATE_PLATFORM_INCLUDES
				src/platform/android/AndroidApplicationHost.h
		)
		list(APPEND ENGINE_PRIVATE_PLATFORM_SOURCES
				src/platform/android/AndroidApplicationHost.cpp
		)
	elseif(CMAKE_SYSTEM_NAME STREQUAL "iOS")
		list(APPEND ENGINE_PRIVATE_PLATFORM_INCLUDES
				src/platform/ios/IOSApplicationHost.h
		)
		list(APPEND ENGINE_PRIVATE_PLATFORM_SOURCES
				src/platform/ios/IOSApplicationHost.cpp
		)
	elseif(WIN32 OR (APPLE AND NOT IOS) OR UNIX)
		list(APPEND ENGINE_PRIVATE_PLATFORM_INCLUDES
				src/platform/desktop/DesktopApplicationHost.h
		)
		list(APPEND ENGINE_PRIVATE_PLATFORM_SOURCES
				src/platform/desktop/DesktopApplicationHost.cpp
		)
	endif()
endif()

set(ENGINE_ALL_SOURCES
		${ENGINE_PUBLIC_INCLUDES}

		${ENGINE_PRIVATE_INCLUDES}
		${ENGINE_PRIVATE_SOURCES}

		${ENGINE_PRIVATE_PLATFORM_INCLUDES}
		${ENGINE_PRIVATE_PLATFORM_SOURCES}
)

add_library(${ENGINE_PROJECT_NAME} STATIC
		${ENGINE_ALL_SOURCES}
)

target_compile_features(engine PUBLIC cxx_std_23)

target_include_directories(${ENGINE_PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/includes)
target_include_directories(${ENGINE_PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src)