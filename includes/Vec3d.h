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

	inline Vec3d&	Normalize();
	inline double	Dot(Vec3d const &v) const;
	inline Vec3d	Cross(Vec3d const &v) const;
	inline double	Length() const;
	inline double	Length2() const;
	inline double	Cos(Vec3d const &v) const;
//	Vec3d	rotationVector(Vec3d &v);
//	Vec3d	translateVector(Vec3d &v);

	inline double  GetX() const;
	inline double  GetY() const;
	inline double  GetZ() const;

	inline void    SetX(const double &xx);
	inline void    SetY(const double &yy);
	inline void    SetZ(const double &zz);

	inline Vec3d operator * (const double &f) const;
	inline Vec3d operator * (const Vec3d &v) const;
	inline Vec3d operator + (const Vec3d &v) const;
	inline Vec3d operator - (const Vec3d &v) const;
	inline Vec3d operator - () const;
	inline Vec3d&operator += (const Vec3d &v);
	inline Vec3d&operator *= (const Vec3d &v);

	inline Vec3d &operator = (const Vec3d &vec3d) = default;

private:
	double x = 0;
	double y = 0;
	double z = 0;
};

/*
 * Functions for work with vectors
 */

inline Vec3d& Vec3d::Normalize()
{
	double nor2 = Length2();
	if (nor2 > 0)
	{
		double invNor = 1 / sqrt(nor2);
		x *= invNor;
		y *= invNor;
		z *= invNor;
	}
	return *this;
}

inline double Vec3d::Length2() const
{
	return (x * x + y * y + z * z);
}

inline double Vec3d::Length() const
{
	return (sqrt(Length2()));
}

inline double Vec3d::Dot(Vec3d const &v) const
{
	return (x * v.x + y * v.y + z * v.z);
}

inline Vec3d Vec3d::Cross(Vec3d const &v) const
{
	return (Vec3d(y * v.z - z * v.y,
				  z * v.x - x * v.z,
				  x * v.y - y * v.x));
}

inline double Vec3d::Cos(Vec3d const &v) const
{
	return (this->Dot(v) / (this->Dot(*this) * v.Dot(v)));
}


/*
 * Getters
 */

inline double Vec3d::GetX() const { return x; }
inline double Vec3d::GetY() const { return y; }
inline double Vec3d::GetZ() const { return z; }


/*
 * Setters
 */

inline void Vec3d::SetX(const double &xx) { x = xx; }
inline void Vec3d::SetY(const double &yy) { y = yy; }
inline void Vec3d::SetZ(const double &zz) { z = zz; }


/*
 * Implementation of overload operators
 */

inline Vec3d Vec3d::operator*( const double &f ) const
{
	return (Vec3d(x * f, y * f, z * f));
}

inline Vec3d Vec3d::operator*( const Vec3d &v ) const
{
	return (Vec3d(x * v.x, y * v.y, z * v.z));
}

inline Vec3d& Vec3d::operator*=( const Vec3d &v )
{
	x *= v.x;
	y *= v.y;
	z *= v.z;
	return (*this);
}

inline Vec3d Vec3d::operator+( const Vec3d &v ) const
{
	return (Vec3d(x + v.x, y + v.y, z + v.z));
}

inline Vec3d& Vec3d::operator+=( const Vec3d &v )
{
	x += v.x;
	y += v.y;
	z += v.z;
	return (*this);
}

inline Vec3d Vec3d::operator-( const Vec3d &v ) const
{
	return (Vec3d(x - v.x, y - v.y, z - v.z));
}

inline Vec3d Vec3d::operator-() const
{
	return (Vec3d(-x, -y, -z));
}

//Vec3d& Vec3d::operator=(const Vec3d &vec3d)
//{
//	x = vec3d.x;
//	y = vec3d.y;
//	z = vec3d.z;
//	return *this;
//}

#endif
