add_library(engine STATIC src/Engine.cpp)

target_compile_features(engine PUBLIC cxx_std_23)

target_include_directories(engine PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)