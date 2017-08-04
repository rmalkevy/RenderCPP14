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

int		my_key_funct(int keycode, void *mod)
{
    auto render = *static_cast<std::shared_ptr<Render>*>(mod);
//    mlx_destroy_image(render->window->GetMlx(), render->window->GetImage());
    if (keycode == 53)
    {
        mlx_destroy_window(render->window->GetMlx(), render->window->GetWin());
        exit(0);
    }
//	return (0);
//    addition_funct(keycode, mod);
//	TracingScreen(render); // TODO заторможує виконання програми, якщо відсутня умова про клавіші
    return (0);
}


void KeyboardMouseControl::KeyboardControl()
{
    //TODO зробити клас, який буде включати в себе Window, Camera, List

	if (_render != nullptr)
        mlx_hook(_render->window->GetWin(), 2, 5, (int (*)())my_key_funct, static_cast<void *>(&_render));
}