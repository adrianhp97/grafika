#include "Input.h"
//cr: Jauhar Arifin

pthread_t Input::inputThread;
bool Input::initiated = false;
char Input::__last_read_input = '\0';

Input::Input() {
    initiated = false;
}

void* inputThreadRun(void* dummy) {
            struct termios savedState, newState;

            if (-1 == tcgetattr(STDIN_FILENO, &savedState)) return NULL;
            newState = savedState;

            newState.c_lflag &= ~(ECHO | ICANON);
            newState.c_cc[VMIN] = 1;

            if (-1 == tcsetattr(STDIN_FILENO, TCSANOW, &newState)) return NULL;
            while (1) {
                tcsetattr(STDIN_FILENO, TCSANOW, &newState);
                Input::__last_read_input = getchar();
                tcsetattr(STDIN_FILENO, TCSANOW, &savedState);
            }
        }

char Input::getLastKey() {
    if (!initiated) {
        pthread_create(&inputThread, NULL, inputThreadRun, NULL);
        initiated = 1;
    }

    char temp = __last_read_input;
    __last_read_input = 0;
    return temp;
}