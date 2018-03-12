MenuBox::MenuBox(int x, int y, float r, int color) : Shape(4) {
  dots[0]->setCoordinate(x-(r*20), y-(r*10));
  dots[1]->setCoordinate(x+(r*20), y+(r*10));
  dots[2]->setCoordinate(x-(r*20), y+(r*10));
  dots[3]->setCoordinate(x+(r*20), y-(r*10));
  switch(color) {
    case 1:
      dots[0]->setColor(0, 0, 150);
      break;
    case 2:
      dots[0]->setColor(0, 150, 0);
      break;
    case 3:
      dots[0]->setColor(150, 0, 0);
      break;
    case 4:
      dots[0]->setColor(200, 200, 200);
      break;
  }
  xCenter = x;
  yCenter = y;
  radius = r;
}
