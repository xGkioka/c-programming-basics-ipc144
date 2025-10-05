project.c       // input + print helpers
project.h       // prototypes + constants
projectmain.c   // main()

Build & Run
gcc -Wall project.c projectmain.c -o train
./train

Goal: zero warnings with -Wall.

Usage

Program asks: Enter number of cars (0-5):

Accepts integers only. Out-of-range or non-numeric → prints message and reprompts.

Example
Enter number of cars (0-5): 3


_______      _________     _________     _________
__/ ____  \_  |[O][O][O]   |   |[O][O]   |   |[O][O]
|<  ENGINE  |  |________|  |________|    |________|
 o--o--o--o     o--o--o       o--o--o       o--o--o

(Your ASCII can differ; keep it consistent.)

Public functions (in project.h)
int  getNumTrainCars(void);     // read & validate [0..MAX_CARS]
void printEngine(void);         // print engine
void printCar(void);            // print one car
void printTrain(int cars);      // engine + cars
Config
#define MIN_CARS 0
#define MAX_CARS 5

Change here if the range updates.

Notes

Keep main() thin: cars = getNumTrainCars(); printTrain(cars);

No magic numbers; use the #defines above.

Handle bad input cleanly (check scanf return, flush buffer).

License

MIT — © 2025 Xenofon Gkioka
