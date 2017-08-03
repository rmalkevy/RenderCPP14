//
// Created by Mac on 16.07.17.
//

#ifndef RENDERCPP_LIGHT_H
#define RENDERCPP_LIGHT_H

#include "Vec3d.h"

class Light final
{
public:
    Light();
	Light(const Vec3d &position, const Vec3d &color);
	~Light() = default;
	void Illuminate(const Vec3d &P, Vec3d &lightDir, Vec3d &lightIntensity, double &distance) const;

//private:
	Vec3d	_position;
	Vec3d	_rayDirection;
	Vec3d	_rayOrigin;
	Vec3d	_color;
	double	_intensity;

};
#endif //RENDERCPP_LIGHT_H
