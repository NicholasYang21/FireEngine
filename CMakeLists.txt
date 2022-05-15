cmake_minimum_required(VERSION 3.20)
project(FireEngine)

include_directories(dependence)
link_directories(lib)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_CXX_FLAGS -static)

add_executable(FireEngine glad.c main.cpp include/Window.hpp source/Window.cc include/Color.hpp include/Type-Macros.hpp dependence/stb_image.h)

target_link_libraries(FireEngine glfw3 opengl32)