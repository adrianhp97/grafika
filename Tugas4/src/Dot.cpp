#include "Dot.h"

Dot::Dot() {
	x = 0;
	y = 0;
}

Dot::Dot(float x, float y, Color c) : color(c) {
	this->x = x;
	this->y = y;
}

void Dot::setCoordinate(float _x, float _y) {
	x = _x;
	y = _y;
}

void Dot::setX(float _x) {
	x = _x;
}

float Dot::getX() {
	return x;
}

void Dot::setY(float _y) {
	y = _y;
}

float Dot::getY() {
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
