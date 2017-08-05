////
//// Created by Roman Malkevych on 7/13/17.
////
//
//#include "includes/Vec3d.h"
//
///*
// * Functions for work with vectors
// */
//
//inline Vec3d& Vec3d::Normalize()
//{
//	double nor2 = Length2();
//	if (nor2 > 0)
//	{
//		double invNor = 1 / sqrt(nor2);
//		x *= invNor;
//		y *= invNor;
//		z *= invNor;
//	}
//	return *this;
//}
//
//inline double Vec3d::Length2() const
//{
//	return (x * x + y * y + z * z);
//}
//
//inline double Vec3d::Length() const
//{
//	return (sqrt(Length2()));
//}
//
//inline double Vec3d::Dot(Vec3d const &v) const
//{
//	return (x * v.x + y * v.y + z * v.z);
//}
//
//inline Vec3d Vec3d::Cross(Vec3d const &v) const
//{
//	return (Vec3d(y * v.z - z * v.y,
//					z * v.x - x * v.z,
//					x * v.y - y * v.x));
//}
//
//inline double Vec3d::Cos(Vec3d const &v) const
//{
//	return (this->Dot(v) / (this->Dot(*this) * v.Dot(v)));
//}
//
//
///*
// * Getters
// */
//
//inline double Vec3d::GetX() const { return x; }
//inline double Vec3d::GetY() const { return y; }
//inline double Vec3d::GetZ() const { return z; }
//
//
///*
// * Setters
// */
//
//inline void Vec3d::SetX(const double &xx) { x = xx; }
//inline void Vec3d::SetY(const double &yy) { y = yy; }
//inline void Vec3d::SetZ(const double &zz) { z = zz; }
//
//
///*
// * Implementation of overload operators
// */
//
//inline Vec3d Vec3d::operator*( const double &f ) const
//{
//	return (Vec3d(x * f, y * f, z * f));
//}
//
//inline Vec3d Vec3d::operator*( const Vec3d &v ) const
//{
//	return (Vec3d(x * v.x, y * v.y, z * v.z));
//}
//
//inline Vec3d& Vec3d::operator*=( const Vec3d &v )
//{
//	x *= v.x;
//	y *= v.y;
//	z *= v.z;
//	return (*this);
//}
//
//inline Vec3d Vec3d::operator+( const Vec3d &v ) const
//{
//	return (Vec3d(x + v.x, y + v.y, z + v.z));
//}
//
//inline Vec3d& Vec3d::operator+=( const Vec3d &v )
//{
//	x += v.x;
//	y += v.y;
//	z += v.z;
//	return (*this);
//}
//
//inline Vec3d Vec3d::operator-( const Vec3d &v ) const
//{
//	return (Vec3d(x - v.x, y - v.y, z - v.z));
//}
//
//inline Vec3d Vec3d::operator-() const
//{
//	return (Vec3d(-x, -y, -z));
//}
//
////Vec3d& Vec3d::operator=(const Vec3d &vec3d)
////{
////	x = vec3d.x;
////	y = vec3d.y;
////	z = vec3d.z;
////	return *this;
////}
