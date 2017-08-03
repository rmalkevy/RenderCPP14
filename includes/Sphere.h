//
// Created by Mac on 12.07.17.
//

#ifndef RENDERCPP_SPHERE_H
#define RENDERCPP_SPHERE_H

//#include "Vec3d.h"
//#include "Camera.h"
#include "Primitive.h"

class Sphere : public IPrimitive
{
public:
	Sphere(Vec3d position, Vec3d color, double radius); // TODO додати аргумент direction
	~Sphere() = default;
	bool	Intersection(const Vec3d &rOrigin, const Vec3d &rDir,
	                     std::shared_ptr<Camera> &camera) override ;
	Vec3d	FindNormal(const Vec3d &intersectionPoint) override ;
	double	getIntersectDistance() ;
	Vec3d	GetColor() override ;

private:
	Vec3d _pos;
    Vec3d _direction;
	Vec3d _color;
	double _radius; // TODO зробити за допомогою цієї змінної пульсуючу кулю
	double _sqRadius;
	double _t;
};

#endif
