cmake_minimum_required(VERSION 3.28)

project(ImGui_Template)

find_package(imgui CONFIG REQUIRED)
find_package(glfw3 CONFIG REQUIRED)
find_package(OpenGL REQUIRED)

add_executable(ImGui_Template main.cpp)

target_link_libraries(ImGui_Template PRIVATE 
    imgui::imgui 
    glfw 
    OpenGL::GL
)

target_compile_features(ImGui_Template PRIVATE cxx_std_23)