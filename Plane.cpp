//
// Created by Roman Malkevych on 7/22/17.
//

#include "includes/Plane.h"

Plane::Plane(Vec3d position, Vec3d direction, Vec3d color)
{
    this->position = position;
    this->direction = direction;
    this->color = color;
}

bool Plane::Intersection(const Vec3d &rOrigin, const Vec3d &rDir, std::shared_ptr<Camera> &camera)
{
    double a = this->direction.Dot(rDir);
    double b = this->direction.Dot(rOrigin);
    double c = this->position.Dot(this->direction);

	double t0 = (fabs(a) > 0.00001) ? (-(b - c) / a) : -1;
    if (t0 < camera->getMaxDistance() && t0 > 0.00001)
    {
	    camera->setMaxDistance(t0);
	    return (true);
    }
	return (false);
}

Vec3d Plane::FindNormal(const Vec3d &intersectionPoint)
{
	Vec3d a;
	a = intersectionPoint;
	return this->direction;
}

Vec3d Plane::GetColor()
{
	return this->color;
}

double Plane::getIntersectDistance()
{
	return this->t;
}