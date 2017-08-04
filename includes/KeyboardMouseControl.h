//
// Created by Roman Malkevych on 7/20/17.
//

#ifndef RENDERCPP_KEYBOARDMOUSECONTROL_H
#define RENDERCPP_KEYBOARDMOUSECONTROL_H

#include "Window.h"
#include "Camera.h"
#include "Render.h"

class KeyboardMouseControl
{
public:
    explicit KeyboardMouseControl(std::shared_ptr<Render> &render);
	KeyboardMouseControl(KeyboardMouseControl &control) : _render(control._render){}
    ~KeyboardMouseControl();
//	KeyboardMouseControl &operator = (const KeyboardMouseControl &control);

    void KeyboardControl();
	void RotateCamera(int keycode);

	constexpr static const double Angle = 0.01;

private:
	std::shared_ptr<Render> _render = nullptr;
};

#endif //RENDERCPP_KEYBOARDMOUSECONTROL_H
