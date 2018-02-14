#include "Plane.h"

Plane::Plane(int x, int y, float size) : x(x), y(y), size(size){
  pilot = new Pilot(x,y,size);
  wing = new Wing(x,y,size);
  rightPropeller = new Propeller(x+(size*100),y+(size*5),size);
  leftPropeller = new Propeller(x-(size*100),y+(size*5),size);
  rightWheel = new Wheel(x+(size*40),y+(size*31),size);
  leftWheel = new Wheel(x-(size*40),y+(size*31),size);
  people = new People(x-(size*100),y-(size*100),size*2);
  wheelDetached = false;
  animationState = 0;
}

Plane::~Plane(){
  delete pilot;
  delete wing;
  delete rightPropeller;
}

void Plane::detachWheel() {
  wheelDetached = true;
}

void Plane::animateWheel(FrameBuffer* fb, Wheel* rightWheel) {
  if(!animationState) {
    fb->translate(rightWheel, 0, 5);
    fb->rotate(rightWheel,10);
  } else {
    if(animationState <= 3) {
      fb->rotate(rightWheel,5);
    } else {
      rightWheel->getDots()[0].setColor(0,0,0);
    }
  }

  if(rightWheel->getDot(0).getY() > fb->getScreenHeight()-100) {
    animationState++;
    rightWheel->setCenterCoordinate(rightWheel->getDot(0).getX()+(100),rightWheel->getDot(0).getY());
    fb->translate(rightWheel, 0, -10);
  }
}

void Plane::draw(FrameBuffer* fb){
  fb->scale(wing, 1.005f);
  fb->scale(pilot, 1.005f);
  fb->scale(leftWheel, 1.005f, x, y);
  fb->scale(leftPropeller, 1.005f, x, y);
  fb->scale(rightPropeller, 1.005f, x, y);
  if(!wheelDetached){
    fb->scale(rightWheel, 1.005f, x, y);
  } else {
    animateWheel(fb,rightWheel);
  }
  fb->rotate(rightPropeller, 20);
  fb->rotate(leftPropeller, 20);

  fb->draw(wing);
  fb->draw(pilot);
  fb->draw(leftWheel);
  fb->draw(rightWheel);
  fb->draw(rightPropeller);
  fb->draw(leftPropeller);
  drawPeople(fb, people);
}

void Plane::drawPeople(FrameBuffer* fb, People* people) {
  if(animationState) {
    fb->translate(people, 0, 3);
    fb->draw(people);
  }
}
