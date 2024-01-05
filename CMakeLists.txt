cmake_minimum_required(VERSION 3.17)

project(RenderingEngine)

add_subdirectory(extern)

file(GLOB_RECURSE PROJECT_SOURCE src/*.cpp src/*.h)

add_executable(FirstRenderingEngine App.cpp ${PROJECT_SOURCE})

target_link_libraries(FirstRenderingEngine PRIVATE glfw libglew_static glm::glm stb::image)