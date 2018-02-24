#include "Missile.h"

Missile::Missile(float x, float y, float r) : Shape(5) {
	dots[0]->setCoordinate(x-(r*6), y-(r*1));
	dots[1]->setCoordinate(x, y-(r*15));
	dots[2]->setCoordinate(x+(r*6), y-(r*1));
	dots[3]->setCoordinate(x+(r*6), y+(r*15));
	dots[4]->setCoordinate(x-(r*6), y+(r*15));
	dots[0]->setColor(255, 255, 255);
	xCenter = x;
	yCenter = y;
	radius = r;
}

Missile::Missile() : Missile(0,0,1) {}

bool Missile::CheckCollision(FrameBuffer* fb){
	int i;
	bool clear = true;
	for(i = 0;i < 5;i++){
		clear = clear && fb->isPixelClear(*dots[i]);
	}
	return !clear;
}
