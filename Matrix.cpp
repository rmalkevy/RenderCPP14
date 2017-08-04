//
// Created by Roman Malkevych on 8/4/17.
//

#include "includes/Matrix.h"

void Matrix::calculationRotationCoefficients(const Vec3d &angle3d)
{
	_cosX = cos(angle3d.GetX());
	_cosY = cos(angle3d.GetY());
	_cosZ = cos(angle3d.GetZ());

	_sinX = sin(angle3d.GetX());
	_sinY = sin(angle3d.GetY());
	_sinZ = sin(angle3d.GetZ());

	_cosY_cosZ = _cosY * _cosZ;
	_sinY_sinX = _sinY * _sinX;
	_cosY_sinZ_cosX = _cosY * _sinZ * _cosX;
	_sum1 = _sinY_sinX - _cosY_sinZ_cosX;

	_cosY_sinZ_sinX = _cosY * _sinZ * _sinX;
	_sinY_cosX = _sinY * _cosX;
	_sum2 = _cosY_sinZ_sinX + _sinY_cosX;

	_sinY_sinZ_cosX = _sinY * _sinZ * _cosX;
	_sinX_cosY = _sinX * _cosY;
	_sum3 = _sinY_sinZ_cosX + _sinX_cosY;

	_cosY_cosX = _cosY * _cosX;
	_sinX_sinY_sinZ = _sinX * _sinY * _sinZ;
	_sum4 = _cosY_cosX - _sinX_sinY_sinZ;

	_cosZ_cosX = _cosZ * _cosX;
	_cosZ_sinX = - (_cosZ * _sinX);
	_sinY_cosZ = - (_sinY * _cosZ);
}

Vec3d Matrix::rotateVec3d(const Vec3d &v) const
{
	Vec3d vec3d(v);

	vec3d.SetX(vec3d.GetX() * _cosY_cosZ + vec3d.GetY() * _sum1 + vec3d.GetZ() * _sum2);
	vec3d.SetY(vec3d.GetX() * _sinZ + vec3d.GetY() * _cosZ_cosX + vec3d.GetZ() * _cosZ_sinX);
	vec3d.SetZ(vec3d.GetX() * _sinY_cosZ + vec3d.GetY() * _sum3 + vec3d.GetZ() * _sum4);
	return ( vec3d );
}

Vec3d Matrix::rotateVec3d(const Vec3d &v, const Vec3d &angle3d)
{
	calculationRotationCoefficients(angle3d);

	return ( rotateVec3d(v) );
}

Vec3d Matrix::translateVec3d(const Vec3d &v, const Vec3d &translate3d) const
{
	return ( v + translate3d );
}