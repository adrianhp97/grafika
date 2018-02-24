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
    rightWheel->translate(0, 5);
    rightWheel->rotate(10);
  } else {
    if(animationState <= 3) {
      rightWheel->rotate(5);
    } else {
      rightWheel->getDot(0)->setColor(0,0,0);
    }
  }

  if(rightWheel->getDot(0)->getY() > fb->getScreenHeight()-100) {
    animationState++;
    rightWheel->setCenterCoordinate(rightWheel->getDot(0)->getX()+(100),rightWheel->getDot(0)->getY());
    rightWheel->translate( 0, -10);
  }
}

void Plane::draw(FrameBuffer* fb){
  wing->scale( 1.005f);
  pilot->scale( 1.005f);
  leftWheel->scale(1.005f, x, y);
  leftPropeller->scale( 1.005f, x, y);
  rightPropeller->scale( 1.005f, x, y);
  if(!wheelDetached){
    rightWheel->scale( 1.005f, x, y);
  } else {
    animateWheel(fb,rightWheel);
  }
  rightPropeller->rotate(20);
  leftPropeller->rotate(20);

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
    people->translate(0, 3);
    fb->draw(people);
  }
}
