//
// Created by Mac on 27.07.17.
//

#ifndef RENDERCPP_CONE_H
#define RENDERCPP_CONE_H

#include "Primitive.h"

class Cone : public IPrimitive
{
public:
    Cone(Vec3d position, Vec3d direction, Vec3d color, double angle);
    ~Cone() = default;
    bool	Intersection(const Vec3d &rOrigin, const Vec3d &rDir,
                         std::shared_ptr<Camera> &camera) override ;
    Vec3d	FindNormal(const Vec3d &intersectionPoint) override ;
    Vec3d	GetColor() override ;

private:
    Vec3d position;
    Vec3d direction;
    Vec3d color;
    double angle;
    double sqCos;
    double sqSin;
};
#endif //RENDERCPP_CONE_H
