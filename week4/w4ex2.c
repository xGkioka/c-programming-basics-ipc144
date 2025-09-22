#include <stdio.h>
int getAge();
double calculateFare(int age);
void printResult(int age, double fare);

int main(void){
	int age = getAge();
	double fare = calculateFare(age);
	printResult(age,fare);
}

int getAge(){
	int age;
	printf("Please enter the age of the rider: ");
	scanf("%d", &age);
	return age;
}
void printResult(int age, double fare){
	printf("Rider of age %d must pay a fare of $%.2lf\n",age, fare);
}
double calculateFare(int age){
	double fare;
	if(age < 12){
		fare = 0;
	}
	else if (age >= 13 && age <= 19){
		fare = 2.40;
	}
	else if (age > 65){
		fare = 2.30;
	}
	else{
		fare = 3.35;
	}
	return fare;
}