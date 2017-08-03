//
// Created by Mac on 27.07.17.
//

#include "includes/Cone.h"
#include "includes/RenderFunctions.h"

Cone::Cone(Vec3d position, Vec3d direction, Vec3d color, double angle)
{
    this->position = position;
    this->direction = direction;
    this->color = color;
    this->angle = angle * (M_PI / 180);
    this->sqCos = cos(this->angle) * cos(this->angle);
    this->sqSin = sin(this->angle) * sin(this->angle);
}

bool Cone::Intersection(const Vec3d &rOrigin, const Vec3d &rDir, std::shared_ptr<Camera> &camera)
{
    int     A = 0;
    int     B = 1;
    double	dot[2];
    Vec3d	mult[2];
    Vec3d	sub[2];
    Vec3d	delta_p;

    delta_p = rOrigin - position;

	dot[A] = direction.Dot(rDir);
    mult[A] = direction * dot[A];
    sub[A] = rDir - mult[A];

	dot[B] = delta_p.Dot(direction);
    mult[B] = direction * dot[B];
    sub[B] = delta_p - mult[B];

	double a = sqCos * sub[A].Dot(sub[A]) - ( sqSin * dot[A] * dot[A] );

	double b = 2 * sqCos * sub[A].Dot(sub[B]);
    b -= ( 2 * sqSin * dot[A] * dot[B] );

	double c = sqCos * sub[B].Dot(sub[B]);
    c -= ( sqSin * dot[B] * dot[B] );

    double discr = b * b - 4 * a * c;

    if (discr < 0)
        return (false);
    double sqrtDiscr = sqrt(discr);
    double t0 = (-b + sqrtDiscr) / (2 * a);
    double t1 = (-b - sqrtDiscr) / (2 * a);

    t0 = MinDistance(t0, t1);
    if (t0 < camera->getMaxDistance() && t0 > 0.00001)
    {
//	    std::cout << "cone"<< std::endl;
        camera->setMaxDistance(t0);
        return (true);
    }
//	std::cout << "cone"<< std::endl;
    return (false);
}

Vec3d Cone::FindNormal(const Vec3d &intersectionPoint)
{
    Vec3d b = intersectionPoint - position;
    Vec3d a = direction * b.Cos(direction);
    Vec3d n = b - a;
	Vec3d scaled = b.Cross(n);
    n = scaled.Cross(b);
    return n.Normalize();
}

Vec3d Cone::GetColor()
{
    return this->color;
}