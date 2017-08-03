//
// Created by Roman Malkevych on 8/3/17.
//

#ifndef RENDER_TRIANGLE_H
#define RENDER_TRIANGLE_H

#include "IPrimitive.h"

class Triangle : public IPrimitive
{
public:
	Triangle(const Vec3d &&a, const Vec3d &&b, const Vec3d &&c,
	         const Vec3d &&color);
	Triangle(const Vec3d &&a, const Vec3d &&b, const Vec3d &&c,
	         const Vec3d &&color, const Vec3d &&direction);
	~Triangle() = default;
	bool	Intersection(const Vec3d &rOrigin, const Vec3d &rDir,
	                     std::shared_ptr<Camera> &camera) override ;
	Vec3d	FindNormal(const Vec3d &intersectionPoint) override ;
	Vec3d	GetColor() override ;

private:
	Vec3d   _posA;
	Vec3d   _posB;
	Vec3d   _posC;
	Vec3d   _direction;
	Vec3d   _color;
	Vec3d   _edge1;
	Vec3d   _edge2;
};

#endif //RENDER_TRIANGLE_H
