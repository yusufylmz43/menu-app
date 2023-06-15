#include "clear_screen.h"
#include <iostream>

void clearScreen(){
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}