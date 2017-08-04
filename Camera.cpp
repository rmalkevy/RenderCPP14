//
// Created by Mac on 15.07.17.
//

#include "includes/Camera.h"

Camera::Camera(Vec3d const &origin, const Light &light)
{
	_position = origin;
	_direction = Vec3d(0, 0, 1);
	_angle3d = Vec3d(0, 0, 0);
	_maxDistance = 100000;
	this->light = light;
}

Camera::~Camera()
{
	std::cout << "Destructor Camera" << std::endl;
}

void Camera::findDirection(const Vec3d &pixel)
{
	Vec3d dir = pixel - getPosition();
	setDirection(dir.Normalize());
}

void Camera::setDirection(const Vec3d &dir)
{
	_direction = dir;
}

void Camera::setPosition(const Vec3d &orig)
{
	_position = orig;
}

int Camera::setAngle(const Vec3d &angle)
{
	_angle3d += angle;
	return ( 1 );
}

void Camera::setMaxDistance(const double &dist)
{
	_maxDistance = dist;
}

Vec3d Camera::getDirection() const
{
	return _direction;
}

Vec3d Camera::getPosition() const
{
	return  _position;
}

Vec3d Camera::getAngle() const
{
	return _angle3d;
}

double Camera::getMaxDistance() const
{
	return _maxDistance;
}