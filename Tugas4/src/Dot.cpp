#include "Dot.h"

Dot::Dot() {
	x = 0;
	y = 0;
}

Dot::Dot(int x, int y, Color c) : color(c) {
	this->x = x;
	this->y = y;
}

void Dot::setCoordinate(int _x, int _y) {
	x = _x;
	y = _y;
}

void Dot::setX(int _x) {
	x = _x;
}

int Dot::getX() {
	return x;
}

void Dot::setY(int _y) {
	y = _y;
}

int Dot::getY() {
	return y;
}

void Dot::setColor(int r, int g, int b) {
	color.r = r;
	color.g = g;
	color.b = b;
}

Color Dot::getColor() {
	return color;
}
