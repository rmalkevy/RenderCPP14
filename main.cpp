//
// Created by Roman Malkevych on 7/13/17.
//

#include "includes/Triangle.h"
#include "includes/Render.h"
#include "includes/Sphere.h"
#include "includes/Plane.h"
#include "includes/Cylinder.h"
#include "includes/Cone.h"
#include "includes/RenderFunctions.h"
#include "includes/KeyboardMouseControl.h"

void    putColorToPixel(std::unique_ptr<Window> &window, const Vec3d &color, const double &x, const double &y)
{
    int			pixel;

    pixel = (int)(((x + window->GetWidth() / 2) + (y + window->GetHeight() / 2) * window->GetWidth()) * 4);
    window->line[pixel + 0] = (unsigned char)(color.GetZ() * 255);
    window->line[pixel + 1] = (unsigned char)(color.GetY() * 255);
    window->line[pixel + 2] = (unsigned char)(color.GetX() * 255);
}

Vec3d	makePixelColor(std::unique_ptr<Camera> &camera, const double &intensity)
{
//    std::cout << "x = " << camera.normal.x << " y = " << camera.normal.y << " z = " << camera.normal.x << std::endl;
    double lambert = camera->light._rayDirection.Dot(camera->hitNormal);
    double red = camera->color.GetX() * lambert * intensity;
    double green = camera->color.GetY() * lambert * intensity;
    double blue =  camera->color.GetZ() * lambert * intensity;
    return Vec3d(red, green, blue);
}

bool   findShadow(std::unique_ptr<Camera> &camera,
                  std::list<std::shared_ptr<IPrimitive>> &listPrimitives,
                  const Vec3d &rayOrig,
                  const Vec3d &rayDir )
{
    for (auto &it : listPrimitives)
    {
        if ((*it).Intersection(rayOrig, rayDir, camera) )
            return true;
    }
    return false;
}

Vec3d	tracingLight( std::unique_ptr<Camera> &camera,
                      std::list<std::shared_ptr<IPrimitive>> &listPrimitives )
{
    Vec3d distance = camera->light._position - camera->hitPoint;
    camera->setMaxDistance(distance.Length());
    if (distance.Dot(camera->hitNormal) <= 0 )
    {
        return Vec3d(0);
    }

    camera->light._rayOrigin = camera->hitPoint;
    camera->light._rayDirection = distance.Normalize();

    bool shadow = findShadow(camera, listPrimitives, camera->light._rayOrigin, camera->light._rayDirection);
	if (!shadow)
	{
        return makePixelColor(camera, 1);
	}
	return makePixelColor(camera, 0.5);
}

void	RenderPixel(std::unique_ptr<Camera> &camera,
                    std::list<std::shared_ptr<IPrimitive>> &listPrimitives,
                    Vec3d rayOrig,
                    Vec3d rayDir)
{
    //for ( std::list<IPrimitive *>::iterator it = listObjects.begin(); it != listObjects.end(); it++ )
    for (auto &it : listPrimitives)
    {
        if ((*it).Intersection(rayOrig, rayDir, camera) )
        {
            camera->hitPoint = camera->getDirection() * camera->getMaxDistance();
            camera->hitPoint += camera->getPosition();
            camera->hitNormal = (*it).FindNormal(camera->hitPoint);
            camera->color = (*it).GetColor();
            camera->intersect = true;
        }
    }

}

//void	TracingScreen(Window &window, Camera &camera, std::list<IPrimitive *> &listObjects)
void	TracingScreen(std::shared_ptr<Render> &render)
{
    int halfHeight = render->window->GetHeight() / 2;
    int halfWidth = render->window->GetWidth() / 2;

    for (int y = -halfHeight; y < halfHeight; y++)
    {
        for (int x = -halfWidth; x < halfWidth; x++)
        {
            // TODO потім дописати поворот pixel
	        Vec3d pixel = render->camera->rotateVec3d(Vec3d(x, y, 0), Vec3d(0, 0, 0.5));
//	        std::cout << "pixel X = " << pixel.GetX() << " Y = " << pixel.GetY() << " Z = " << pixel.GetZ() << std::endl;
            render->camera->intersect = false;
	        render->camera->color = Vec3d(0);
	        render->camera->findDirection(pixel);
//	        Vec3d dir = render->camera->getDirection();
//	        std::cout << "dir X = " << dir.GetX() << " Y = " << dir.GetY() << " Z = " << dir.GetZ() << std::endl;
	        render->camera->setMaxDistance(1000000);
	        RenderPixel(render->camera, render->listPrimitives,
	                    render->camera->getPosition(), render->camera->getDirection());
            if (render->camera->intersect)
            {
                putColorToPixel(render->window, tracingLight(render->camera, render->listPrimitives), x, y);
            }
        }
    }
}

static int a = -1;

void	RenderImage(std::shared_ptr<Render> &render)
{
    KeyboardMouseControl keyboardMouseControl(render);
    a++;
    std::cout << "break point " << a << std::endl;
	render->window->ClearWindow();
	render->window->CreateImage();

	TracingScreen(render);

	render->window->PutImageToWindow();

// TODO погано пам'ять фрішиться коли різні клавіші нажимаю. Перевірити що там і як

	keyboardMouseControl.KeyboardControl(); // TODO написати функцію з обробки клавіш
   // std::cout << "break point " << a << std::endl;
	render->window->InfinityShowingImage();
   // std::cout << "break point " << a << std::endl;
}

// TODO для оптимізації роботи програми необхідно додати в list id,
// за допомогою якого я буду вираховувати тільки один раз нормаль.
// Тобто я пройдусь по всіх об'єктах і визначу, який найближчий, а потім уже буду
// шукати нормаль

int main()
{
	// Create window
	auto window = std::make_unique<Window>(800, 600);

	// Create light
	Light light(Vec3d(500, -400, -500), Vec3d(1, 1, 1));

	// Create camera
	auto camera = std::make_unique<Camera>(Vec3d(0, 0, -2000), light);

	// Create list of objects
	std::list<std::shared_ptr<IPrimitive>> listPrimitives;
    listPrimitives.push_back(std::make_unique<Sphere>(Vec3d(0, 0, -100), Vec3d(1, 0, 0), 80));
    listPrimitives.push_back(std::make_unique<Sphere>(Vec3d(0, -100, -200), Vec3d(0, 1, 0), 100));
    listPrimitives.push_back(std::make_unique<Sphere>(Vec3d(100, 0, -100), Vec3d(0, 0, 1), 90));
	listPrimitives.push_back(std::make_unique<Plane>(Vec3d(0, 200, 0), Vec3d(0, -1, 0), Vec3d(0.5, 0.9, 0)));
    listPrimitives.push_back(std::make_unique<Cylinder>(Vec3d(200, 0, 0), Vec3d(0, 1, 0), Vec3d(1, 0, 0), 100));
	listPrimitives.push_back(std::make_unique<Cone>(Vec3d(-200, 0, -200), Vec3d(0, 1, 0), Vec3d(0.9, 0.5, 0.4), 20));
//	listPrimitives.push_back(std::make_unique<Triangle>(Vec3d(-200, 0, -500), Vec3d(200, 0, 500), Vec3d(-50, -300, 300), Vec3d(1, 0, 0)));

    auto render = std::make_shared<Render>(window, camera, listPrimitives);
	RenderImage(render);
	//TODO list with 3 spheres
	return 0;
}