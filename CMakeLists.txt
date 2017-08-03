cmake_minimum_required(VERSION 3.8)
project(Render)

set(CMAKE_CXX_STANDARD 14)

include_directories(inc includes minilibx)
link_directories(minilibx)

set(SOURCE_FILES main.cpp
        includes
        Render.cpp
        Vec3d.cpp Window.cpp Camera.cpp KeyboardMouseControl.cpp
        Light.cpp
        Plane.cpp Cylinder.cpp Cone.cpp Sphere.cpp Triangle.cpp includes/Triangle.h)

add_executable(Render ${SOURCE_FILES})

target_link_libraries(Render libmlx.a "-framework OpenGL" "-framework AppKit")