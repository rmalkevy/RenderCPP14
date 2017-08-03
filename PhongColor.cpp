//
// Created by Mac on 27.07.17.
//

#include <algorithm>
#include <complex>
#include "includes/Vec3d.h"
#include "includes/Camera.h"

static const float kInfinity = std::numeric_limits<float>::max();
static const float kEpsilon = 1e-8;
static const Vec3d kDefaultBackgroundColor = Vec3d(0.235294, 0.67451, 0.843137);
static const double bias = 0.0001;

Vec3d reflect(const Vec3d &I, const Vec3d &N)
{
    return I - N * 2 * I.Dot(N);
}

Vec3d calulatePhongColor(Camera &camera, Vec3d hitColor, Light *lights)
{
    Vec3d diffuse(0);
    Vec3d specular(0);
    Vec3d hitPoint = camera.hitPoint;
    Vec3d hitNormal = camera.hitNormal;

    for (uint32_t i = 0; i < 1; ++i) // TODO i < lights.size()
    {
        Vec3d lightDir;
        Vec3d lightIntensity;
        IsectInfo isectShad;
	    lights[i].Illuminate(hitPoint, lightDir, lightIntensity, isectShad.tNear);

        bool vis = !trace(hitPoint + (hitNormal * bias), -lightDir, objects, isectShad, kShadowRay);

        // compute the diffuse component
        diffuse += vis * isect.hitObject->albedo * lightIntensity * std::max(0.f, hitNormal.Dot(-lightDir));

        // compute the specular component
        // what would be the ideal reflection direction for this light ray
        Vec3d R = reflect(lightDir, hitNormal);
        specular += lightIntensity * vis * std::pow(std::max(0.f, R.Dot(-camera.getDirection())), isect.hitObject->n);
    }
    hitColor = diffuse * isect.hitObject->Kd + specular * isect.hitObject->Ks;


    return hitColor;
}