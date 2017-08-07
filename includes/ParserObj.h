//
// Created by Roman Malkevych on 8/7/17.
//

#ifndef RENDER_PARSEROBJ_H
#define RENDER_PARSEROBJ_H

#include <iostream>
#include <vector>
#include <list>
#include "Vec3d.h"
#include "IPrimitive.h"

class ParserObj
{
public:
	ParserObj(int argc, char **argv);
	~ParserObj(); // TODO: close file after finishing all operations
	std::string ReadFileToBuffer();
	void PutPrimitivesToList(std::list<std::shared_ptr<IPrimitive>> listPrimitives);

	struct Face { int v1, v2, v3; };

	// TODO: zooming objects. Decide this problem
	// TODO: do reading normals and texture (in the future)
private:
	std::vector<Vec3d> _vertices;
	std::vector<Face> _faces;
};
#endif //RENDER_PARSEROBJ_H
