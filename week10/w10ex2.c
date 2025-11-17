#include<stdio.h>

double weightedAvg(int key,int st[],double mid[], double fin[], int used);
void printStudents(int st[],double mid[], double fin[],int used);
void sortStudents(int st[],double mid[], double fin[],int used);


int main() {
                // PARALEL ARRAYS 
    int studentNumber[3]={1111,2222,3333};
    double midterm[3]={42,29,29};
    double finals[3]={47,35,37};

    printf("Student Number:%d \n Midterm:%.2lf\n Final:%.2lf\n", studentNumber[1], midterm[1], finals[1]);

            //Write a function to pass the index of the elements and passing 3 arrays and calculate the average for midterm and final exam
        double average=weightedAvg(2222,studentNumber,midterm,finals,3);
        printf("The weighted average of %d is %.2lf\n", 2222, average);
    
        printStudents(studentNumber,midterm,finals,3);
        sortStudents(studentNumber,midterm,finals,3);
        printStudents(studentNumber,midterm,finals,3);


    return 0;
}
        // how to searcch for the 2222 student 

double weightedAvg(int key,int st[],double mid[], double fin[], int used) {
    int index = -1;
    for (int i = 0; i < used && index == -1 ; i++){
        if (key = st[i]){
            index = i;
        }

    }
    return mid[index]*0.40+fin[index]*0.60;
}

void printStudents(int st[],double mid[], double fin[],int used) {
printf("%6s%-8s%6s\n","ID","Midterm","final");
    for (int i = 0; i < used; i++){
        printf("%-6d%-8.2lf%6.2lf\n",st[i],mid[i],fin[i]);
    }
}

void sortStudents(int st[],double mid[], double fin[],int used){
for (int i=0;i<used-1;i++){
    for (int j=0; j<used-1; j++){
        if (fin[j+1]>fin[j]){
            double temp = fin[j];
            fin[j]=fin[j+1];
            fin[j+1]=temp;

          temp = mid[j];
            mid[j]=mid[j+1];
            mid[j+1]=temp;


            int tempst = st[j];
            st[j]=st[j+1];
            st[j+1]=tempst;
        }
    }
}
}