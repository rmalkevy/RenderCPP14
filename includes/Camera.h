//
// Created by Roman Malkevych on 7/14/17.
//

#ifndef RENDERCPP_CAMERA_H
#define RENDERCPP_CAMERA_H

#include "Vec3d.h"
#include "Light.h"
#include "Matrix.h"

class Camera : public Matrix
{
public:
	Camera(const Vec3d &origin, const Light &light);
	~Camera();

	void	findDirection(Vec3d const &pixel);
	void	setDirection(Vec3d const &dir);
	void	setPosition(Vec3d const &orig);
	void	setAngle(Vec3d const &angle);
	void	setMaxDistance(double const &dist);
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
	Vec3d	direction;
	Vec3d	position;
	Vec3d	angle3d;
	double	maxDistance;

};
#endif //RENDERCPP_CAMERA_H
