//
// Created by Roman Malkevych on 7/18/17.
//

#ifndef RENDERCPP_PRIMITIVE_H
#define RENDERCPP_PRIMITIVE_H

#include "Vec3d.h"
#include "Camera.h"

class IPrimitive
{
public:
    IPrimitive() = default;
    virtual ~IPrimitive() = default;
    virtual bool	Intersection(const Vec3d &rOrigin, const Vec3d &rDir,
                                 std::unique_ptr<Camera> &camera) = 0;
    virtual Vec3d	FindNormal(const Vec3d &intersectionPoint) = 0;
    virtual Vec3d	GetColor() = 0;

    // TODO Можливо варто додати getters and setters?
};
#endif //RENDERCPP_PRIMITIVE_H
