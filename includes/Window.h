//
// Created by Roman Malkevych on 7/14/17.
//

#ifndef RENDERCPP_WINDOW_H
#define RENDERCPP_WINDOW_H

#include <iostream>
#include "Vec3d.h"

extern "C" {
#include "../minilibx/mlx.h"
}

class Window final
{
public:
	Window(int width, int height);
	~Window();

	void	PrepareWindowAndImage();
	void	ClearWindow();
	void	CreateImage();
	void	PutImageToWindow();
	void	KeyboardControl();
	void	InfinityShowingImage();

	void    PutColorToPixel(const Vec3d &color, const int &x, const int &y);

	void	*GetMlx();
	void	*GetWin();
	void	*GetImage();
	char	*GetLine();
	int 	GetWidth() const;
	int		GetHeight() const;

	void	SetMlx(void *mlx);
	void	SetWin(void *win);
	void	SetImage(void *image);
	void	SetLine(char *line);
	void	SetWidth(int width);
	void	SetHeight(int height);

private:
	int		_width;
	int     _halfWidth;
	int		_height;
	int     _halfHeight;
	void	*_mlx;
	void	*_win;
	void	*_image;
	char	*_line;
};

#endif //RENDERCPP_WINDOW_H
