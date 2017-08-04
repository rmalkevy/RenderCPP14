//
// Created by Roman Malkevych on 8/3/17.
//

#include "includes/Triangle.h"

Triangle::Triangle(const Vec3d &&a, const Vec3d &&b, const Vec3d &&c,
                   const Vec3d &&color)
{
	_posA = a;
	_posB = b;
	_posC = c;
	_color = color;

	_edge1 = _posB - _posA;
	_edge2 = _posC - _posA;
	_direction = _edge1.Cross(_edge2);
	_direction.Normalize();
}

Triangle::Triangle(const Vec3d &&a, const Vec3d &&b, const Vec3d &&c,
                   const Vec3d &&color, const Vec3d &&direction)
{
	_posA = a;
	_posB = b;
	_posC = c;
	_color = color;
	_direction = direction;

	_edge1 = _posB - _posA;
	_edge2 = _posC - _posA;
}

bool Triangle::Intersection(const Vec3d &rOrigin, const Vec3d &rDir,
                            std::unique_ptr<Camera> &camera)
{
	Vec3d pVec = rDir.Cross(_edge2);
	double det = _edge1.Dot(pVec);
	if (fabs(det) < 0.0000001 || det < 0)
		return ( false );
	double invDet = 1 / det;

	Vec3d tVec = rOrigin - _posA;
	double u = tVec.Dot(pVec) * invDet;
	if (u < 0 || u > 1)
		return ( false );

	Vec3d qVec = tVec.Cross(_edge1);
	double v = rDir.Dot(qVec) * invDet;
	if (v < 0 || u + v > 1)
		return ( false );
	camera->setMaxDistance(_edge2.Dot(qVec) * invDet);
	return ( true );
}

Vec3d Triangle::FindNormal(const Vec3d &intersectionPoint)
{
	Vec3d a; // TODO - clean this kostyl !!
	a = intersectionPoint;
	return ( _direction );
}

Vec3d Triangle::GetColor()
{
	return ( _color );
}
