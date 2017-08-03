//
// Created by Roman Malkevych on 7/13/17.
//

#include "includes/Render.h"

Render::Render(std::unique_ptr<Window> &window,
               std::shared_ptr<Camera> &camera,
               std::list<std::shared_ptr<IPrimitive>> &listPrimitives)
{
	this->window = std::move(window);
	this->camera = std::move(camera);
	this->listPrimitives = std::move(listPrimitives);
}
