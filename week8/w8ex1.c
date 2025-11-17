// INTRODUTION TO STRUCTS 
#include<stdio.h>
struct Student // we declare it before the main and the first letter is always CAPITAL
{
  int id;
  double grade;
};

struct Date 
{
    int day;
    int month;
    int year;
};

int main() {
     printf("Week 8\n");
     int a; // Variable is just a container to hold value in the memmory
    int arr[5]={6,2,5,10,5}; // arrays holds multyvalues of the same data type, 
 // struct we use it to store values of different data types
     int s1_id = 1234;   
     double s1_grade = 85.5;
        printf("The student id is %d and the grade is %.2lf\n", s1_id, s1_grade);
  // struct we use it to store values of different data types
     int s2_id = 4567;  
     double s2_grade = 90.4;
         printf("The student id is %d and the grade is %.2lf\n", s2_id, s2_grade);

// store multivalue and different data types at the same time
/*we use the key word struct struct_name { 
datatype member1;
datatype member2;
}
*/
 printf("*******USING STREUCT*******\n");

 struct Student s1={1111,65.9};
 struct Student s2;
 s2.id=2222;
 s2.grade=75.9;

 printf("The student ID: %d Grade: %.2lf\n", s1.id, s1.grade);
 printf("The student ID: %d Grade: %.2lf\n", s2.id, s2.grade);

  struct Student s3;
 printf("Enter the ID: ");
 scanf("%d", &s3.id);
 printf("Enter the Grade: ");
 scanf("%lf", &s3.grade);
 printf("The student ID: %d Grade: %.2lf\n", s3.id, s3.grade);

 // if we have like 20 students we need to use arraay

 printf("*******Array of  Structs*******\n");
 struct Student students[3]={{1111,85.9}, {2222,90.4}, {3333,56}};
 for (int i=0; i<3; i++){
     printf("student(%d) ID= %d grade= %.2lf\n", i+1, students[i].id, students[i].grade);
 }
 printf("<<<<<<other>>>>>>>");
 struct Student section2[3]={111,72,222,84};
 for (int i=0; i<3; i++){
      printf("student(%d) ID= %d grade= %.2lf\n", i+1, section2[i].id, section2[i].grade);
 }


struct Date date1={19,7,2005};
printf("%d-%d-%d", date1.day, date1.month, date1.year);





    return 0;
}


 





