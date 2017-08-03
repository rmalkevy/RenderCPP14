//
// Created by Mac on 27.07.17.
//

#include "includes/Cylinder.h"
#include "includes/RenderFunctions.h"

Cylinder::Cylinder(Vec3d &&position, Vec3d &&direction,
                   Vec3d &&color, double &&radius)
{
    this->_position = position;
    this->_direction = direction;
    this->_color = color;
    this->_sqRadius = radius * radius;
}

bool Cylinder::Intersection(const Vec3d &rOrigin,
                            const Vec3d &rDir,
                            std::shared_ptr<Camera> &camera)
{
    double	dot;
    Vec3d	mult;
    Vec3d	sub1;
    Vec3d	sub2;
    Vec3d	delta_p;

    dot = this->_direction.Dot(rDir);
    mult = this->_direction * dot;
    sub1 = rDir - mult;

    // TODO тут можна скоротити розрахунки за рахунок попереднього підрахування sub2
    delta_p = rOrigin - this->_position;
    dot = this->_direction.Dot(delta_p);
    mult = this->_direction * dot;
    sub2 = delta_p - mult;

    double a = sub1.Dot(sub1);
    double b = 2 * sub1.Dot(sub2);
    double c = sub2.Dot(sub2) - _sqRadius;

    double discr = b * b - 4 * a * c;
    if (discr < 0)
        return (false);

    double sqrtDiscr = sqrt(discr);
    double t0 = (-b + sqrtDiscr) / 2;
    double t1 = (-b - sqrtDiscr) / 2;

    t0 = MinDistance(t0, t1);
    if (t0 < camera->getMaxDistance() && t0 > 0.00001)
    {
        camera->setMaxDistance(t0);
        return (true);
    }
    return (false);
}

Vec3d Cylinder::FindNormal(const Vec3d &intersectionPoint)
{
    Vec3d b = intersectionPoint - this->_position;
    Vec3d a = this->_direction * b.Dot(this->_direction);
    Vec3d rv = b - a;
    return rv.Normalize();
}

Vec3d Cylinder::GetColor()
{
    return this->_color;
}