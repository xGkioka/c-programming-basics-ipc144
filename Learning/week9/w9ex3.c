#include <stdio.h>

//STRUCT AND POINTERS 
struct Student{
    int id;
    double grade;
};
void printStudent1(struct Student st);
void printStudent2(const struct Student *p);
int main () {
  struct Student s ={111,89.5};
    printStudent1(s);
     printStudent2(&s);



    return 0;
}

void printStudent1(struct Student st) {

    printf("Student info:\n");
    printf("\tID:%d\n", st.id);
    printf("\tGrade:%.2lf\n", st.grade);

}
void printStudent2(const struct Student *p) {
 printf("Student info:\n");
    printf("\tID:%d\n", p->id);   //WE USE -> to show the value stores at there | (*p).id
    printf("\tGrade:%.2lf\n", p->grade); // (*p).grade


}