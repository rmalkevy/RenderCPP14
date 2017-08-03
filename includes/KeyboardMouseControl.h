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
    ~KeyboardMouseControl() = default;
//	KeyboardMouseControl &operator = (const KeyboardMouseControl &control);

    void KeyboardControl();

private:
	std::shared_ptr<Render> _render = nullptr;
};

#endif //RENDERCPP_KEYBOARDMOUSECONTROL_H
