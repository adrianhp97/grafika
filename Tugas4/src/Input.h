#ifndef INPUT_H
#define INPUT_H
//credit: Jauhar Arifin

#include <pthread.h>
#include <termios.h>
#include <unistd.h>
#include <stdio.h>

class Input {
  public:
    Input();
    char getLastKey();

    static pthread_t inputThread;
    static bool initiated;
    static char __last_read_input;
};

#endif