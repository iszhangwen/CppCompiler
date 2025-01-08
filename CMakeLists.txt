cmake_minimum_required(VERSION 3.12)
project(LoxCompiler LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
add_compile_options("-g")

add_subdirectory(syntax)
add_subdirectory(compiler)

add_subdirectory(test)