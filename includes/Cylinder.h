//
// Created by Mac on 24.07.17.
//

#ifndef RENDERCPP_CYLINDER_H
#define RENDERCPP_CYLINDER_H

#include "Primitive.h"

class Cylinder : public IPrimitive
{
public:
    Cylinder(Vec3d position, Vec3d direction, Vec3d color, double radius);
    ~Cylinder() = default;
    bool	Intersection(const Vec3d &rOrigin, const Vec3d &rDir,
                         std::shared_ptr<Camera> &camera) override ;
    Vec3d	FindNormal(const Vec3d &intersectionPoint) override ;
    Vec3d	GetColor() override ;

private:
    Vec3d   _position;
    Vec3d   _direction;
    Vec3d   _color;
    double  _sqRadius;
};

#endif //RENDERCPP_CYLINDER_H
