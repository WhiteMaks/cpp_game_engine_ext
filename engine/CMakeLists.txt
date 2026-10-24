set(ENGINE_PROJECT_NAME engine)

set(ENGINE_PUBLIC_INCLUDES
		includes/engine/Application.h
		includes/engine/ApplicationHost.h
		includes/engine/ApplicationHostFactory.h
)

set(ENGINE_PRIVATE_INCLUDES
		includes/platform/desktop/DesktopApplicationHost.h
)

set(ENGINE_PRIVATE_SOURCES
		src/engine/Application.cpp
		src/engine/ApplicationHost.cpp
		src/engine/ApplicationHostFactory.cpp
)

set(ENGINE_ALL_SOURCES
		${ENGINE_PUBLIC_INCLUDES}

		${ENGINE_PRIVATE_INCLUDES}
		${ENGINE_PRIVATE_SOURCES}
)

add_library(${ENGINE_PROJECT_NAME} STATIC
		${ENGINE_ALL_SOURCES}
)

target_compile_features(engine PUBLIC cxx_std_23)

target_include_directories(${ENGINE_PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/includes)
target_include_directories(${ENGINE_PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src)