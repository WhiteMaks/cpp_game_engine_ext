add_executable(sandbox main.cpp)

target_link_libraries(sandbox PRIVATE engine)

install(TARGETS sandbox RUNTIME DESTINATION bin)