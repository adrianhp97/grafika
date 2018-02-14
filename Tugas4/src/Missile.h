#ifndef MISSILE_H
#define MISSILE_H

#include <iostream>
#include "Shape.h"
#include "FrameBuffer.h"

using namespace std;

class Missile : public Shape {
	public:
		Missile(float , float, float);
		bool CheckCollision(FrameBuffer*);
};

#endif
