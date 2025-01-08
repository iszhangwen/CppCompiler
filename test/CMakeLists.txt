include_directories(${CMAKE_SOURCE_DIR}/syntax)
link_directories(${CMAKE_BINARY_DIR}/syntax)
add_executable(source source_test.cpp)
target_link_libraries(source syntax)