/***************************************************************** 

    File: projectmain.c

     Author: [Xenofon Gkioka]
    Seneca email: [xgkioka@myseneca.ca]

    To compile program in codespaces, in terminal pane type:
        gcc -Wall project.c projectmain.c
    To run program in codespaces, in terminal pane type:
        ./a.out
        
***************************************************************/
//your main for the project goes into this file
//Uncomment the next line if you are using Visual Studio
//#define _CRT_SECURE_NO_WARNING

#include <stdio.h>
#include "project.h"

int main(void) {
    int cars = getNumTrainCars();
    char dir = getDirection();
    drawTrain(cars, dir);
    return 0;
}