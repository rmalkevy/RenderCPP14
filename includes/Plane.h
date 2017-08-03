//
// Created by Roman Malkevych on 7/22/17.
//

#ifndef RENDERCPP_PLANE_H
#define RENDERCPP_PLANE_H

#include "Vec3d.h"
#include "Camera.h"
#include "IPrimitive.h"

class Plane : public IPrimitive
{
public:
    Plane(Vec3d position, Vec3d direction, Vec3d color);
    ~Plane() = default;
    bool	Intersection(const Vec3d &rOrigin, const Vec3d &rDir,
                         std::shared_ptr<Camera> &camera) override ;
	Vec3d	FindNormal(const Vec3d &intersectionPoint) override ;
    double	getIntersectDistance() ;
    Vec3d	GetColor() override ;


private:
    Vec3d _position;
    Vec3d _direction;
    Vec3d _color;
    double t;
};

#endif //RENDERCPP_PLANE_H
