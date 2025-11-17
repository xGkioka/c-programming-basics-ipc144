#include <stdio.h>

struct Scores 
{
    int StudentNumber;
    double quizes[6];
    double labs[9];
    double projects[2];
    double test[2];
};

void printStudentsV1(struct Scores st);
void printStudentsV2(struct Scores *st);

int main (){

struct Scores st1={12345,
                {9,10,8.5,7,8,7.5}, // nested curly brackets 
                {1,2,3,4,5,6,7,8,9},
                {10,13},
                {26,24}};

printf("The first quiz %2.lf\n", st1.quizes[0]);
    
st1.quizes[0]=10;
printf("The upgraded value of first quiz %.2lf", st1.quizes[0]);

printf("\n-----------------------------------\n");

//Version 1 print the info of st1
printStudentsV1(st1);

printf("\n-----------------------------------\n");

// Version 2 
printStudentsV2(&st1); // 

    return 0; 
}

void printStudentsV1(struct Scores st) {
        printf("student number %d\n", st.StudentNumber);
       printf("Quzes:");
       for (int i=0; i<6; i++){
        printf("%.2lf,", st.quizes[i]);
       };
       printf("\nLabs:");
       for (int i=0; i<9; i++){
        printf("%.2lf,", st.labs[i]);
       };
       printf("\nProjects:");
       for (int i=0; i<2; i++){
        printf("%.2lf,", st.projects[i]);
       };
       printf("\nTests:");
       for (int i=0; i<2; i++){
        printf("%.2lf,", st.test[i]);
       };

}
void printStudentsV2(struct Scores *st){
   printf("student number %d\n", st->StudentNumber);
       printf("Quzes:");
       for (int i=0; i<6; i++){
        printf("%.2lf,", st->quizes[i]);
       };
       printf("\nLabs:");
       for (int i=0; i<9; i++){
        printf("%.2lf,", st->labs[i]);
       };
       printf("\nProjects:");
       for (int i=0; i<2; i++){
        printf("%.2lf,", st->projects[i]);
       };
       printf("\nTests:");
       for (int i=0; i<2; i++){
        printf("%.2lf,", st->test[i]);
       };

}