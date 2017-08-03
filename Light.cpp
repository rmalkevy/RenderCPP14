//
// Created by Mac on 16.07.17.
//

#include "includes/Light.h"

Light::Light() {
    this->_position = Vec3d(0, 0, -1000);
    this->_color = Vec3d(255, 255, 255);
}

Light::Light(const Vec3d &position, const Vec3d &color)
{
	this->_position = position;
	this->_color = color;
}

void Light::Illuminate(const Vec3d &P, Vec3d &lightDir, Vec3d &lightIntensity, double &distance) const
{
	lightDir = (P - _position);
	double r2 = lightDir.Dot(lightDir);
	distance = sqrt(r2);
	lightDir = lightDir * (1 / distance);
	//lightDir.x /= distance, lightDir.y /= distance, lightDir.z /= distance;
	// avoid division by 0
	lightIntensity = _color * (_intensity / (4 * M_PI * r2));
}
