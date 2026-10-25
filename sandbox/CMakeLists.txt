add_executable(sandbox main.cpp)

target_link_libraries(sandbox PRIVATE engine)

if(EMSCRIPTEN)
	set_target_properties(sandbox PROPERTIES SUFFIX ".html")
endif()

install(TARGETS sandbox RUNTIME DESTINATION bin)