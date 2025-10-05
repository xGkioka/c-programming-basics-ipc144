/***************************************************************** 

    File: project.c

    Author: [Xenofon Gkioka]
    Seneca email: [xgkioka@myseneca.ca]

    To compile program in codespaces, in terminal pane type:
        gcc -Wall project.c projectmain.c
    To run program in codespaces, in terminal pane type:
        ./a.out
        
    ASCII Train art inspired by public domain ASCII trains from:
     https://asciiart.website/index.php?art=transportation/trains
    Modified and adapted by <Xenofon> for this assignment.
***************************************************************/
//Uncomment the next line if you are using Visual Studio
//#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "project.h"

/* ========== INPUT ========== */

int getNumTrainCars(void)  // asks for number of cars
{
    int cars = -1;
    while (cars < 0 || cars > 5) {
        printf("Enter number of cars (0-5): ");
        scanf("%d", &cars);
        if (cars < 0 || cars > 5) {
            printf("Invalid input. Please try again.\n");
        }
    }
    return cars;
}

char getDirection(void)  // asks for direction of travel
{
    char dir = ' ';
    while (dir != 'L' && dir != 'l' && dir != 'R' && dir != 'r') {
        printf("Enter direction of travel (L|l|R|r): ");
        scanf(" %c", &dir);
        if (dir != 'L' && dir != 'l' && dir != 'R' && dir != 'r') {
            printf("Invalid input. Please try again.\n");
        }
        if (dir == 'l') dir = 'L';
        if (dir == 'r') dir = 'R';
    }
    return dir;
}

/* ========== OUTPUT ========== */

void drawTrain(int cars, char dir) //  draws the train
 {
    int i, row;

     /* --- smoke just once, above the engine --- */
    if (dir == 'R') {
        printf("      ");                 /* match engine left padding */
        for (i = 0; i < cars + 3; i++) printf("~ ");
        printf("\n");
    } else { /* L */
        int lead = cars * 13 + 5;         /* 13 per car + 5 engine lead */
        for (i = 0; i < lead; i++) putchar(' ');
        for (i = 0; i < cars + 3; i++) printf("~ ");
        printf("\n");
    }

    /* 4 rows total */
    for (row = 0; row < 4; row++) 
    {
        if (dir == 'R')
         {
            /* engine (right-facing), then cars */
            if (row == 0)      printf("      ______     ");
            else if (row == 1) printf("__|__|__|___T_  ");
            else if (row == 2) printf("|  ENGINE  __|>>");
            else               printf("  O-OO-OO-O     ");

            for (i = 0; i < cars; i++) 
            {
                if (row == 0)      printf("  ________   ");
                else if (row == 1) printf(" |[][]    |  ");
                else if (row == 2) printf("-|________|-");
                else               printf("   o-oo-o    ");
            }
        } 
        else 
        {
            /* cars first, then engine (left-facing) */
            for (i = 0; i < cars; i++)
            {
                if (row == 0)      printf("  ________  ");
                else if (row == 1) printf(" |    [][]| ");
                else if (row == 2) printf("-|________|-");
                else               printf("  o-oo-o    ");
            }

            if (row == 0)      printf("     ______      ");
            else if (row == 1) printf("  _T___|__|__|__ ");
            else if (row == 2) printf("<<|__  ENGINE  | ");
            else               printf("     O-OO-OO-O  ");
        }
        printf("\n");
    }
}