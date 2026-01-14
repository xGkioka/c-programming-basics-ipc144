/***********************************************************************

    File: project.c

    Author: [Xenofon Gkioka]
    Seneca email: [xgkioka@myseneca.ca]

    To compile program in codespaces, in terminal pane type:
        gcc -Wall project.c projectmain.c
    To run program in codespaces, in terminal pane type:
        ./a.out

***********************************************************************/

#include "project.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>


/*
    This function makes a string all UPPERCASE so we can compare names easily
    It goes through each character and converts it if it's a letter
*/
void convertToUppercase(char* str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        str[i] = toupper((unsigned char)str[i]);
    }
}

/*
    Shows the menu and keeps asking until the user picks a valid option (1-4)
    Returns the option the user chose
*/
int displayMenu(void)
{
    int choice = 0;
    int status = 0;
    int valid = 0;

    while (!valid) {
        printf("\nBaby Name Data Viewer\n");
        printf("1. number of babies\n");
        printf("2. top 5 names\n");
        printf("3. histogram\n");
        printf("4. exit\n");
        printf("Enter your choice: ");
        status = scanf("%d", &choice);
        clearInputBuffer();

        if (status != 1) {
            printf("Invalid input. Please enter a number.\n");
            choice = 0;
        } else if (choice < 1 || choice > 4) {
            printf("Invalid input. Choice must be between 1 and 4.\n");
        } else {
            valid = 1;
        }
    }

    return choice;
}

/*
    Asks the user for a year and won't stop asking until they give one between 1914 and 2023
    Returns the valid year they entered
*/
int getValidYear(void)
{
    int year = 0;
    int status = 0;
    int valid = 0;

    while (!valid) {
        printf("Enter the Year: ");
        status = scanf("%d", &year);
        clearInputBuffer();

        if (status != 1) {
            printf("Invalid input. Please enter a number.\n");
            year = 0;
        } else if (year < START_YEAR || year > END_YEAR) {
            printf("Number entered was invalid. Number must be between %d to %d inclusive\n", START_YEAR, END_YEAR);
            printf("Please re-enter: ");
        } else {
            valid = 1;
        }
    }

    return year;
}

/*
    Cleans up the leftover newline character that scanf leaves in the buffer
    This prevents input problems on the next scanf call
*/
void clearInputBuffer(void)
{
    int c = 0;

    while ((c = getchar()) != '\n' && c != EOF) {
        ;
    }
}

/*
    Loads baby name data from a CSV file into our records array
    Also handles the file opening, parsing, and error checking
    Returns how many records we successfully loaded
*/
int loadData(struct BabyNameRecord records[], int maxRecords, const char* filename)
{
    FILE* file = NULL;
    int count = 0;
    int year = 0;
    char name[NAME_LEN];
    char header[256];
    int frequency = 0;
    int result = 0;
    int scanResult = 0;

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Could not open file %s\n", filename);
        count = 0;
    } else {
        fgets(header, sizeof(header), file);

        while (count < maxRecords) {
            scanResult = fscanf(file, "%d,%63[^,],%d\n", &year, name, &frequency);
            if (scanResult != 3) {
                break;
            }

            if (year >= START_YEAR && year <= END_YEAR) {
                records[count].year = year;
                strncpy(records[count].name, name, NAME_LEN - 1);
                records[count].name[NAME_LEN - 1] = '\0';
                convertToUppercase(records[count].name);
                records[count].frequency = frequency;
                count++;
            }
        }

        result = fclose(file);
        if (result != 0) {
            printf("Warning: Error closing file %s\n", filename);
        }
    }

    return count;
}

/*
    Searches for a baby name and shows how popular it was each year
    Separates the data into female and male counts, and shows totals
*/
void findNameCount(struct BabyNameRecord records[], int totalRecords, int femaleCount)
{
    char searchName[NAME_LEN];
    char upperSearchName[NAME_LEN];
    int i = 0;
    int femaleTotal = 0;
    int maleTotal = 0;
    int foundAny = 0;
    int scanResult = 0;

    printf("Enter the Name: ");
    fflush(stdout);
    scanResult = scanf("%63[^\n]", searchName);
    clearInputBuffer();

    if (scanResult != 1) {
        printf("Invalid input.\n");
        searchName[0] = '\0';
    }

    strncpy(upperSearchName, searchName, NAME_LEN - 1);
    upperSearchName[NAME_LEN - 1] = '\0';
    convertToUppercase(upperSearchName);

    printf("%s\n", searchName);
    printf("Results for %s\n", searchName);

    for (i = 0; i < totalRecords; i++) {
        if (strcmp(records[i].name, upperSearchName) == 0) {
            printf("%d: %d\n", records[i].year, records[i].frequency);
            foundAny = 1;

            if (i < femaleCount) {
                femaleTotal += records[i].frequency;
            } else {
                maleTotal += records[i].frequency;
            }
        }
    }

    if (!foundAny) {
        printf("No records found for %s\n", upperSearchName);
    } else {
        printf("Female total: %d\n", femaleTotal);
        printf("Male total: %d\n", maleTotal);
        printf("Total: %d\n", femaleTotal + maleTotal);
    }
}

/*
    Finds the 5 most popular baby names for a specific year
    Shows separate top 5 lists for girls, boys, and all names combined
*/
void findTop5(struct BabyNameRecord records[], int totalRecords, int femaleCount)
{
    int year = 0;
    int i = 0;
    int j = 0;
    int minIdx = 0;
    struct BabyNameRecord top5Female[TOP_NAMES];
    struct BabyNameRecord top5Male[TOP_NAMES];
    struct BabyNameRecord top5Overall[TOP_NAMES * 2];
    struct BabyNameRecord tempRec;
    int femaleCount5 = 0;
    int maleCount5 = 0;
    int overallCount = 0;

    for (i = 0; i < TOP_NAMES; i++) {
        top5Female[i].frequency = 0;
        top5Female[i].year = 0;
        top5Female[i].name[0] = '\0';
        top5Male[i].frequency = 0;
        top5Male[i].year = 0;
        top5Male[i].name[0] = '\0';
    }

    for (i = 0; i < TOP_NAMES * 2; i++) {
        top5Overall[i].frequency = 0;
        top5Overall[i].year = 0;
        top5Overall[i].name[0] = '\0';
    }

    year = getValidYear();

    for (i = 0; i < totalRecords; i++) {
        if (records[i].year == year) {
            if (i < femaleCount) {
                if (femaleCount5 < TOP_NAMES) {
                    top5Female[femaleCount5] = records[i];
                    femaleCount5++;
                } else {
                    minIdx = 0;
                    for (j = 1; j < TOP_NAMES; j++) {
                        if (top5Female[j].frequency < top5Female[minIdx].frequency) {
                            minIdx = j;
                        }
                    }
                    if (records[i].frequency > top5Female[minIdx].frequency) {
                        top5Female[minIdx] = records[i];
                    }
                }
            } else {
                if (maleCount5 < TOP_NAMES) {
                    top5Male[maleCount5] = records[i];
                    maleCount5++;
                } else {
                    minIdx = 0;
                    for (j = 1; j < TOP_NAMES; j++) {
                        if (top5Male[j].frequency < top5Male[minIdx].frequency) {
                            minIdx = j;
                        }
                    }
                    if (records[i].frequency > top5Male[minIdx].frequency) {
                        top5Male[minIdx] = records[i];
                    }
                }
            }
        }
    }

    for (i = 0; i < femaleCount5; i++) {
        for (j = i + 1; j < femaleCount5; j++) {
            if (top5Female[i].frequency < top5Female[j].frequency) {
                tempRec = top5Female[i];
                top5Female[i] = top5Female[j];
                top5Female[j] = tempRec;
            }
        }
    }

    for (i = 0; i < maleCount5; i++) {
        for (j = i + 1; j < maleCount5; j++) {
            if (top5Male[i].frequency < top5Male[j].frequency) {
                tempRec = top5Male[i];
                top5Male[i] = top5Male[j];
                top5Male[j] = tempRec;
            }
        }
    }

    printf("Results for %d\n", year);
    printf("\nFemale Top 5:\n");
    for (i = 0; i < femaleCount5 && i < TOP_NAMES; i++) {
        printf("%d. %s: %d\n", i + 1, top5Female[i].name, top5Female[i].frequency);
    }

    printf("\nMale Top 5:\n");
    for (i = 0; i < maleCount5 && i < TOP_NAMES; i++) {
        printf("%d. %s: %d\n", i + 1, top5Male[i].name, top5Male[i].frequency);
    }

    for (i = 0; i < femaleCount5; i++) {
        top5Overall[overallCount] = top5Female[i];
        overallCount++;
    }

    for (i = 0; i < maleCount5; i++) {
        top5Overall[overallCount] = top5Male[i];
        overallCount++;
    }

    for (i = 0; i < overallCount; i++) {
        for (j = i + 1; j < overallCount; j++) {
            if (top5Overall[i].frequency < top5Overall[j].frequency) {
                tempRec = top5Overall[i];
                top5Overall[i] = top5Overall[j];
                top5Overall[j] = tempRec;
            }
        }
    }

    printf("\nOverall Top 5:\n");
    for (i = 0; i < overallCount && i < TOP_NAMES; i++) {
        printf("%d. %s: %d\n", i + 1, top5Overall[i].name, top5Overall[i].frequency);
    }
}

/*
    Creates an ASCII histogram that shows how a name's popularity changed over time
    Groups the data into 5-year time periods to make it easier to see the trends
*/
void drawHistogram(struct BabyNameRecord records[], int totalRecords, int femaleCount)
{
    char searchName[NAME_LEN];
    char upperSearchName[NAME_LEN];
    int i, j, cohortStart, cohortEnd, yearIndex;
    int nameFreq[NUM_YEARS] = {0};
    int maxNameFreq = 0;
    int nameCohortFreq = 0;
    int numStars = 0;
    int scanResult;

    // Ask user for the name
    printf("Enter the Name: ");
    fflush(stdout);
    scanResult = scanf("%63[^\n]", searchName);
    clearInputBuffer();

    if (scanResult != 1 || searchName[0] == '\0') {
        printf("Invalid input.\n");
        return;
    }

    // Convert name to uppercase
    strncpy(upperSearchName, searchName, NAME_LEN - 1);
    upperSearchName[NAME_LEN - 1] = '\0';
    convertToUppercase(upperSearchName);

    // Count occurrences for each year
    for (i = 0; i < totalRecords; i++) {
        yearIndex = records[i].year - START_YEAR;
        if (strcmp(records[i].name, upperSearchName) == 0) {
            nameFreq[yearIndex] += records[i].frequency;
        }
    }

    // Find maximum frequency across all cohorts
    for (i = 0; i < NUM_YEARS; i += COHORT_SIZE) {
        int cohortSum = 0;
        for (j = 0; j < COHORT_SIZE && (i + j) < NUM_YEARS; j++)
            cohortSum += nameFreq[i + j];
        if (cohortSum > maxNameFreq)
            maxNameFreq = cohortSum;
    }

    // Print histogram
    printf("Histogram for %s\n", searchName);
    cohortStart = START_YEAR;
    while (cohortStart <= END_YEAR) {
        cohortEnd = cohortStart + COHORT_SIZE - 1;
        if (cohortEnd > END_YEAR) cohortEnd = END_YEAR;

        nameCohortFreq = 0;
        for (i = cohortStart; i <= cohortEnd; i++)
            nameCohortFreq += nameFreq[i - START_YEAR];

        // Scale stars relative to max frequency
        numStars = (int)((double)nameCohortFreq / maxNameFreq * HISTOGRAM_WIDTH);
        if (numStars == 0 && nameCohortFreq > 0) numStars = 1;

        printf("%d-%d |", cohortStart, cohortEnd);
        for (i = 0; i < numStars; i++)
            printf("*");
        printf("\n");

        cohortStart = cohortEnd + 1;
    }
}

/*
    Takes all the baby name data from both the female and male files
    Writes everything to combined.txt so we have one complete dataset
*/
void writeCombinedFile(struct BabyNameRecord records[], int totalRecords)
{
    FILE* file = NULL;
    int i = 0;
    int result = 0;

    file = fopen("combined.txt", "w");
    if (file == NULL) {
        printf("Error: Could not create combined.txt\n");
    } else {
        for (i = 0; i < totalRecords; i++) {
            fprintf(file, "%d,%s,%d\n", records[i].year, records[i].name, records[i].frequency);
        }

        result = fclose(file);
        if (result != 0) {
            printf("Warning: Error closing combined.txt\n");
        }
    }
}