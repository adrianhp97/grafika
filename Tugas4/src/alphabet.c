#include "alphabet.h"

void makeA(Alphabet *character) {
  
}

void makeE(Alphabet *character) {
    setLinePoints(&(*character).line[0],10,10,10,110);
    setLinePoints(&(*character).line[1],10,110,70,110);
    setLinePoints(&(*character).line[2],70,110,70,90);
    setLinePoints(&(*character).line[3],70,90,30,90);
    setLinePoints(&(*character).line[4],30,90,30,70);
    setLinePoints(&(*character).line[5],30,70,70,70);
    setLinePoints(&(*character).line[6],70,70,70,50);
    setLinePoints(&(*character).line[7],70,50,30,50);
    setLinePoints(&(*character).line[8],30,50,30,30);
    setLinePoints(&(*character).line[9],30,30,70,30);
    setLinePoints(&(*character).line[10],70,30,70,10);
    setLinePoints(&(*character).line[11],70,10,10,10);
    (*character).nLine = 12;
}