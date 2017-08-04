//
// Created by Roman Malkevych on 7/14/17.
//

#include "includes/Window.h"

Window::Window(int width, int height)
{
	// TODO зробити три режими екрану.
	// TODO Там можна буде показати вказівники на функції
	// TODO Зробити перевірку на вхідні ширину і висоту екрану не в конструктрі

	SetWidth(width);
	SetHeight(height);
	PrepareWindowAndImage();
}

Window::~Window()
{}

void Window::PrepareWindowAndImage()
{
    const char *nameWindow;

    nameWindow = "RenderCPP";
	SetMlx(mlx_init());
	SetWin(mlx_new_window(GetMlx(), _width, _height, (char *) nameWindow));
}

void Window::ClearWindow()
{
	mlx_clear_window(GetMlx(), GetWin());
}

void Window::CreateImage()
{
	int a[3];

	SetImage(mlx_new_image(GetMlx(), GetWidth(), GetHeight()));
	SetLine(mlx_get_data_addr(GetImage(), &a[0], &a[1], &a[2]));
}

void Window::PutImageToWindow()
{
	mlx_put_image_to_window(GetMlx(), GetWin(), GetImage(), 0, 0);
}

void Window::KeyboardControl()
{
	//TODO зробити клас, який буде включати в себе Window, Camera, List
//	mlx_hook(mod->w->win, 2, 5, my_key_funct, mod);
}

void Window::InfinityShowingImage()
{
	mlx_loop(GetMlx());
}

void* Window::GetMlx()
{
	return this->_mlx;
}

void* Window::GetWin()
{
	return this->_win;
}

void* Window::GetImage()
{
	return this->_image;
}

char* Window::GetLine()
{
	return this->line;
}

int Window::GetWidth() const
{
	return this->_width;
}

int Window::GetHeight() const
{
	return this->_height;
}

void Window::SetMlx(void *mlx)
{
	this->_mlx = mlx;
}

void Window::SetWin(void *win)
{
	this->_win = win;
}

void Window::SetImage(void *image)
{
	this->_image = image;
}

void Window::SetLine(char *line)
{
	this->line = line;
}

void Window::SetWidth(int width)
{
	if (width >= 120 && width <= 1200)
		this->_width = width;
	else
	{
		std::cout << "Width must be in range from 120 to 1200!";
		exit(0);
	}
}

void Window::SetHeight(int height)
{
	if (height >= 80 && height <= 800)
		this->_height = height;
	else
	{
		std::cout << "Height must be in range from 80 to 800!";
		exit(0);
	}
}