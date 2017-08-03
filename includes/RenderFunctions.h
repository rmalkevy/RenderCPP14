//
// Created by Mac on 22.07.17.
//

#ifndef RENDERCPP_RENDERFUNCTIONS_H
#define RENDERCPP_RENDERFUNCTIONS_H

#include "Render.h"
#include "Vec3d.h"

void	RenderImage(Render &render);

void	RenderPixel(std::shared_ptr<Camera> &camera,
                    std::list<std::shared_ptr<IPrimitive>> &listPrimitives,
                    Vec3d rayOrig,
                    Vec3d rayDir);

void	TracingScreen(std::shared_ptr<Render> &render);

inline double MinDistance(double t0, double t1)
{
    if (t0 < 0)
        t0 = t1;
    if (t0 > t1)
        t0 = t1;
    return ( t0 );
}

#endif //RENDERCPP_RENDERFUNCTIONS_H


//cmake_minimum_required(VERSION 3.7)
//project(RTv1_new)
//
//set(CMAKE_C_STANDARD 99)
//include_directories(inc libft/includes minilibx)
//link_directories(libft minilibx)
//set(SOURCE_FILES main.c rtv1.h get_next_line.c get_next_line.h parse.c
//		alloc_sph.c alloc_scene.c alloc_plane.c alloc_cylinder.c alloc_cone.c alloc_camera.c alloc_light.c)
//add_executable(RTv1_new ${SOURCE_FILES})
//
//target_link_libraries(RTv1_new libft.a libmlx.a "-framework OpenGL" "-framework AppKit")