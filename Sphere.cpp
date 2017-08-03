//
// Created by Mac on 12.07.17.
//

#include "includes/Sphere.h"
#include "includes/RenderFunctions.h"

Sphere::Sphere( Vec3d position, Vec3d color, double radius )
{
	this->_pos = position;
	this->_color = color;
	this->_radius = radius;
	this->_sqRadius = radius * radius;
	_t = 100000;
}

bool Sphere::Intersection(const Vec3d &rOrigin,
                          const Vec3d &rDir,
                          std::shared_ptr<Camera> &camera)
{
	Vec3d len = rOrigin - _pos;

	double a = rDir.Dot(rDir);
	double b = 2 * rDir.Dot(len);
	double c = len.Dot(len) - _sqRadius;

	double discr = b * b - 4 * a * c;
	if (discr < 0)
		return (false);

	double sqrtDiscr = sqrt(discr);
	double t0 = (-b + sqrtDiscr) / 2;
	double t1 = (-b - sqrtDiscr) / 2;

	t0 = MinDistance(t0, t1);
	if (t0 < camera->getMaxDistance() && t0 > 0.00001)
	{
		camera->setMaxDistance(t0);
		return (true);
	}
	return (false);
}

Vec3d Sphere::FindNormal(const Vec3d &intersectionPoint)
{
	Vec3d normal = intersectionPoint - this->_pos;
	return (normal.Normalize() );
}

double Sphere::getIntersectDistance()
{
	return this->_t;
}

Vec3d Sphere::GetColor()
{
	return this->_color;
}