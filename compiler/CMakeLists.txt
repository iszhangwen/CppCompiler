file(GLOB SRC "*")

include_directories(&{CMAKE_SOURCE_DIR}/syntax)
link_directories(${CMAKE_BINARY_DIR}/syntax)

add_executable(CppCompiler ${SRC})
target_link_libraries(CppCompiler syntax)