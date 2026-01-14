    /***********************************************************************

    File: projectmain.c

    Author: [Xenofon Gkioka]
    Seneca email: [xgkioka@myseneca.ca]

    To compile program in codespaces, in terminal pane type:
        gcc -Wall project.c projectmain.c
    To run program in codespaces, in terminal pane type:
        ./a.out

***********************************************************************/

#include "project.h"
#include <stdio.h>

/*
    This is the main program! It loads the baby name data, shows the menu,
    lets the user pick what they want to do, and then saves everything to a file
*/
int main(void)
{
    static struct BabyNameRecord database[180000];
    int femaleCount = 0;
    int maleCount = 0;
    int totalRecords = 0;
    int userChoice = 0;

    femaleCount = loadData(database, 180000, "femalebabynames.csv");
    maleCount = loadData(database + femaleCount, 180000 - femaleCount, "malebabynames.csv");
    totalRecords = femaleCount + maleCount;

    if (femaleCount == 0 && maleCount == 0) {
        printf("Error: No data was loaded from the files.\n");
        return 0;
    }

    do {
        userChoice = displayMenu();

        if (userChoice == 1) {
            findNameCount(database, totalRecords, femaleCount);
        } else if (userChoice == 2) {
            findTop5(database, totalRecords, femaleCount);
        } else if (userChoice == 3) {
            drawHistogram(database, totalRecords, femaleCount);
        } else if (userChoice == 4) {
            printf("Exiting program.\n");
        }
    } while (userChoice != 4);

    printf("Finished, writing data to combined.txt\n");
    writeCombinedFile(database, totalRecords);

    return 0;
}
