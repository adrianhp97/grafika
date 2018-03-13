#ifndef MENUACTIVITIES_H
#define MENUACTIVITIES_H

#include <iostream>
#include "../Shape.h"
#include "../CustomShape.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <linux/fb.h>
#include <sys/mman.h>
#include <sys/ioctl.h>

using namespace std;

int StartCredit();
int StartMap();
int StartPlane();
CustomShape* readFile(string fileName);

class Credits {
public :
    Credits();
    int MAX_MTX = 100;
    int LETTER_SPACING = 51;
    int LINE_SPACING = 70;
    int X_POS = 200;

    int ShowCredits();
};

#endif
