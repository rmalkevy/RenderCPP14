//
// Created by Roman Malkevych on 7/14/17.
//

#ifndef RENDERCPP_CAMERA_H
#define RENDERCPP_CAMERA_H

#include "Vec3d.h"
#include "Light.h"
#include "Matrix.h"

static const double MaxDistance = 1000000;

class Camera : public Matrix
{
public:
	Camera(const Vec3d &origin, const Light &light);
	~Camera();

	void	findDirection(const Vec3d &pixel);
	void    findHitPoint();
	void	setDirection(const Vec3d &dir);
	void	setPosition(const Vec3d &orig);
	int     setAngle(const Vec3d &angle);
	void	setMaxDistance(const double &dist);
	Vec3d	getDirection() const;
	Vec3d	getPosition() const;
	Vec3d	getAngle() const;
	double	getMaxDistance() const;
	Vec3d	color;
	bool	intersect;
	Vec3d	hitNormal;
	Vec3d	hitPoint;
	Light	light;

private:
	Vec3d	_direction;
	Vec3d	_position;
	Vec3d	_angle3d;
	double	_maxDistance;

};
#endif //RENDERCPP_CAMERA_H
