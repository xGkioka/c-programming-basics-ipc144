/***********************************************************************

    File: project.h

    Author: [Xenofon Gkioka]
    Seneca email: [xgkioka@myseneca.ca]

    To compile program in codespaces, in terminal pane type:
        gcc -Wall project.c projectmain.c
    To run program in codespaces, in terminal pane type:
        ./a.out

***********************************************************************/

#define START_YEAR 1914
#define END_YEAR 2023
#define NUM_YEARS (END_YEAR - START_YEAR + 1)
#define MAX_RECORDS 180000
#define NAME_LEN 64
#define HISTOGRAM_WIDTH 80
#define TOP_NAMES 5
#define COHORT_SIZE 5

/*
    BabyNameRecord - This struct holds info about a baby name
    Members:
        year - what year was this name popular (between 1914-2023)
        name - the actual baby name (we'll convert it to uppercase for matching)
        frequency - how many babies had this name that year
*/
struct BabyNameRecord {
    int year;
    char name[NAME_LEN];
    int frequency;
};

/*
    This function makes a string all UPPERCASE so we can compare names easily
    Parameters:
        str - the string we want to convert to uppercase
    Returns: nothing (void) - we just modify the string in place
*/
void convertToUppercase(char* str);

/*
    Shows the menu and makes sure the user picks a valid option
    Parameters: none needed
    Returns: the menu choice the user picked (1, 2, 3, or 4)
*/
int displayMenu(void);

/*
    Asks the user for a year and keeps asking until they give a valid one (1914-2023)
    Parameters: none needed
    Returns: the valid year the user entered
*/
int getValidYear(void);

/*
    Cleans up leftover characters in the input buffer after scanf
    (this prevents weird input errors)
    Parameters: none needed
    Returns: nothing (void)
*/
void clearInputBuffer(void);

/*
    Searches for a baby name and shows how many babies had that name each year
    Also calculates totals for female, male, and combined
    Parameters:
        records - the array of baby name records
        totalRecords - how many records we have total
        femaleCount - where the female names end and male names begin in the array
    Returns: nothing (void)
*/
void findNameCount(struct BabyNameRecord records[], int totalRecords, int femaleCount);

/*
    Finds the 5 most popular baby names for a specific year
    Shows separate lists for girls, boys, and all names combined
    Parameters:
        records - the array of baby name records
        totalRecords - how many records we have total
        femaleCount - where the female names end and male names begin in the array
    Returns: nothing (void)
*/
void findTop5(struct BabyNameRecord records[], int totalRecords, int femaleCount);

/*
    Creates a cool ASCII histogram showing how a name's popularity changed over time
    Uses 5-year time periods (cohorts) to group the data
    Parameters:
        records - the array of baby name records
        totalRecords - how many records we have total
        femaleCount - where the female names end and male names begin in the array
    Returns: nothing (void)
*/
void drawHistogram(struct BabyNameRecord records[], int totalRecords, int femaleCount);

/*
    Reads a CSV file (like femalebabynames.csv) and loads all the baby names into our array
    Parameters:
        records - where we're storing the baby name records
        maxRecords - the maximum number of records we can hold
        filename - the name of the CSV file to read from
    Returns: how many records we successfully loaded
*/
int loadData(struct BabyNameRecord records[], int maxRecords, const char* filename);

/*
    Takes all the baby name data from both files and writes it to combined.txt
    This creates one big file with all the girls and boys names together
    Parameters:
        records - the array of baby name records
        totalRecords - how many records we have total
    Returns: nothing (void)
*/
void writeCombinedFile(struct BabyNameRecord records[], int totalRecords);

