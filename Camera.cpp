//
// Created by Mac on 15.07.17.
//

#include "includes/Camera.h"

Camera::Camera(Vec3d const &origin, const Light &light)
{
	setPosition(origin);
	setDirection(Vec3d(0, 0, 1));
	setAngle(Vec3d(0, 0, 0));
	this->maxDistance = 100000;
	this->light = light;
}

Camera::~Camera()
{
	std::cout << "Destructor Camera" << std::endl;
}

void Camera::findDirection(Vec3d const &pixel)
{
	Vec3d dir = pixel - getPosition();
	setDirection(dir.Normalize());
}

void Camera::setDirection(Vec3d const &dir)
{
	this->direction = dir;
}

void Camera::setPosition(Vec3d const &orig)
{
	this->position = orig;
}

void Camera::setAngle(Vec3d const &angle)
{
	this->angle3d = angle;
}

void Camera::setMaxDistance(double const &dist)
{
	this->maxDistance = dist;
}

Vec3d Camera::getDirection() const
{
	return this->direction;
}

Vec3d Camera::getPosition() const
{
	return  this->position;
}

Vec3d Camera::getAngle() const
{
	return this->angle3d;
}

double Camera::getMaxDistance() const
{
	return this->maxDistance;
}