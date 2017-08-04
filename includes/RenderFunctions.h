//
// Created by Mac on 22.07.17.
//

#ifndef RENDERCPP_RENDERFUNCTIONS_H
#define RENDERCPP_RENDERFUNCTIONS_H

#include "Render.h"
#include "Vec3d.h"


void	RenderPixel(std::unique_ptr<Camera> &camera,
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
