//
// Created by Roman Malkevych on 8/4/17.
//

#ifndef RENDER_MATRIX_H
#define RENDER_MATRIX_H

#include "Vec3d.h"

class Matrix
{
protected:
	Matrix() = default;
	virtual ~Matrix() = default;
	void    calculationRotationCoefficients(const Vec3d &angle3d);
	Vec3d	rotateVec3d(const Vec3d &v) const;
	Vec3d	rotateVec3d(const Vec3d &v, const Vec3d &angle3d);
	Vec3d	translateVec3d(const Vec3d &v, const Vec3d &translate3d) const;

private:
	double _cosX = 0;
	double _cosY = 0;
	double _cosZ = 0;
	double _sinX = 0;
	double _sinY = 0;
	double _sinZ = 0;

	double _cosY_cosZ = 0;
	double _sinY_sinX = 0;
	double _cosY_sinZ_cosX = 0;
	double _sum1 = 0;
	double _cosY_sinZ_sinX = 0;
	double _sinY_cosX = 0;
	double _sum2 = 0;
	double _cosZ_cosX = 0;
	double _cosZ_sinX = 0;
	double _sinY_cosZ = 0;
	double _sinY_sinZ_cosX = 0;
	double _cosY_cosX = 0;
	double _sinX_cosY = 0;
	double _sum3 = 0;
	double _sinX_sinY_sinZ = 0;
	double _sum4 = 0;
};
#endif //RENDER_MATRIX_H
