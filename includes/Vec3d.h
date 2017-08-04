//
// Created by Mac on 12.07.17.
//

#ifndef RENDERCPP_VEC3_H
#define RENDERCPP_VEC3_H

#include <iostream>
#include <cmath>

class Vec3d final
{
public:
	Vec3d() = default;
	explicit Vec3d(double xx) : x(xx), y(xx), z(xx) {}
	Vec3d(double xx, double yy, double zz) : x(xx), y(yy), z(zz) {}
	Vec3d(const Vec3d &v) : x(v.x), y(v.y), z(v.z) {}
	~Vec3d() = default;

	Vec3d&	Normalize();
	double	Dot(Vec3d const &v) const;
	Vec3d	Cross(Vec3d const &v) const;
	double	Length() const;
	double	Length2() const;
	double	Cos(Vec3d const &v) const;
//	Vec3d	rotationVector(Vec3d &v);
//	Vec3d	translateVector(Vec3d &v);

	double &GetX() const;
	double &GetY() const;
	double &GetZ() const;

	void    SetX(const double &xx);
	void    SetY(const double &yy);
	void    SetZ(const double &zz);

	Vec3d operator * (const double &f) const;
	Vec3d operator * (const Vec3d &v) const;
	Vec3d operator + (const Vec3d &v) const;
	Vec3d operator - (const Vec3d &v) const;
	Vec3d operator - () const;
	Vec3d&operator += (const Vec3d &v);
	Vec3d&operator *= (const Vec3d &v);

	Vec3d &operator = (const Vec3d &vec3d) = default;

private:
	double x = 0;
	double y = 0;
	double z = 0;
};


#endif
