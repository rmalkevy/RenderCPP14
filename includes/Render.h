//
// Created by Roman Malkevych on 7/14/17.
//

#ifndef RENDERCPP_RENDER_H
#define RENDERCPP_RENDER_H

#include <iostream>
#include <list>
#include "Camera.h"
#include "Window.h"
#include "IPrimitive.h"

class Render final
{
public:
    Render(std::unique_ptr<Window> &window,
           std::unique_ptr<Camera> &camera,
           std::list<std::shared_ptr<IPrimitive>> &listPrimitives);

    ~Render();
	std::unique_ptr<Window> window;
	std::unique_ptr<Camera> camera;
	std::list<std::shared_ptr<IPrimitive>> listPrimitives;
// TODO зробити клас, який зберігатиме проміжні результати роботи інших класів і функцій
};

#endif //RENDERCPP_RENDER_H
