//
// Created by Roman Malkevych on 7/20/17.
//

#include "includes/KeyboardMouseControl.h"
#include "includes/RenderFunctions.h"

KeyboardMouseControl::KeyboardMouseControl(std::shared_ptr<Render> &render)
{
    this->_render = render;
}

KeyboardMouseControl::~KeyboardMouseControl()
{
	std::cout << "destruct KeyboardKontrol" << std::endl;
}

//KeyboardMouseControl::~KeyboardMouseControl() {}

//int		addition_funct(int k, t_mod *mod)
//{
//	if (k == 126)
//		mod[0].rot.angl_x += ANGLE;
//	else if (k == 125)
//		mod[0].rot.angl_x -= ANGLE;
//	else if (k == 124)
//		mod[0].rot.angl_y += ANGLE;
//	else if (k == 123)
//		mod[0].rot.angl_y -= ANGLE;
//	else if (k == 83)
//		mod[0].rot.angl_z += ANGLE;
//	else if (k == 82)
//		mod[0].rot.angl_z -= ANGLE;
//	else if (k == 1)
//		mod[0].cam_distance += DISTANCE;
//	else if (k == 13)
//		mod[0].cam_distance -= DISTANCE;
//	change_cam(mod);
//	return (0);
//}

int rotateCamera(int keycode, std::shared_ptr<Render> &_render)
{
	if (keycode == 126)
		return _render->camera->setAngle(Vec3d(0, 0.01, 0));
	if (keycode == 125)
		return _render->camera->setAngle(Vec3d(0, -0.01, 0));
	if (keycode == 124)
		return _render->camera->setAngle(Vec3d(0.01, 0, 0));
	if (keycode == 123)
		return _render->camera->setAngle(Vec3d(-0.01, 0, 0));
	if (keycode == 83)
		return _render->camera->setAngle(Vec3d(0, 0, 0.01));
	if (keycode == 82)
		return _render->camera->setAngle(Vec3d(0, 0, -0.01));
	return ( 0 );
}

int		my_key_funct(int keycode, void *mod)
{
    auto render = *static_cast<std::shared_ptr<Render>*>(mod);
//    mlx_destroy_image(render->window->GetMlx(), render->window->GetImage());
	std::cout << keycode << std::endl;
	if (keycode == 53)
    {
        mlx_destroy_window(render->window->GetMlx(), render->window->GetWin());
        exit(0);
    }
	if (rotateCamera(keycode, render) == 1)
	{
		Vec3d vec3d = render->camera->getAngle();
		std::cout << "angleX = " << vec3d.GetX() << " angleY = " << vec3d.GetY() << " angleZ = " << vec3d.GetZ() << std::endl;
		render->camera->calculationRotationCoefficients(render->camera->getAngle());
		TracingScreen(render); // TODO заторможує виконання програми, якщо відсутня умова про клавіші
	}
    return (0);
}


void KeyboardMouseControl::KeyboardControl()
{
    //TODO зробити клас, який буде включати в себе Window, Camera, List

	if (_render != nullptr)
        mlx_hook(_render->window->GetWin(), 2, 5, (int (*)())my_key_funct, static_cast<void *>(&_render));
}

void KeyboardMouseControl::RotateCamera(int keycode)
{
	if (keycode == 126)
		_render->camera->setAngle(Vec3d(0, Angle, 0));
	else if (keycode == 125)
		_render->camera->setAngle(Vec3d(0, -Angle, 0));
	else if (keycode == 124)
		_render->camera->setAngle(Vec3d(Angle, 0, 0));
	else if (keycode == 123)
		_render->camera->setAngle(Vec3d(-Angle, 0, 0));
	else if (keycode == 83)
		_render->camera->setAngle(Vec3d(0, 0, Angle));
	else if (keycode == 82)
		_render->camera->setAngle(Vec3d(0, 0, -Angle));
}