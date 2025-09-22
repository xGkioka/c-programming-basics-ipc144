#include<stdio.h>

float TOURate(int dayOfWeek, int hour, int min);

int main() {    
    int dayOfWeek, hour, min;
    float rate;

    printf("Enter the day of the week (1=Mon, 2=Tue, ..., 7=Sun): ");
    scanf("%d", &dayOfWeek);
    printf("Enter the time (hour and minute) in 24-hour format (e.g., 13 30 for 1:30 PM): ");
    scanf("%d %d", &hour, &min);

    rate = TOURate(dayOfWeek, hour, min);

    if (rate < 0) {
        printf("Invalid input! Please check the day and time.\n");
    } else {
        printf("The toll rate is: $%.2f\n", rate);
    }

    return 0;
}
float TOURate(int dayOfWeek, int hour, int min) {
    int totalMins = hour * 60 + min;

    // If you want 0=Sunday…6=Saturday, uncomment this:
    // if (dayOfWeek == 0 || dayOfWeek == 6) return 7.6;

    // Since you used 1=Mon…7=Sun:
    if (dayOfWeek == 7 || dayOfWeek == 6) {
        return 7.6;  // weekend = off-peak
    } else if (dayOfWeek >= 1 && dayOfWeek <= 5) {
        if (totalMins < 420 || totalMins >= 1140) {
            return 7.6;  // off-peak
        } else if ((totalMins >= 421 && totalMins <= 659) ||
                   (totalMins >= 1021 && totalMins <= 1139)) {
            return 12.2; // mid-peak
        } else if (totalMins >= 660 && totalMins <= 1020) {
            return 15.8; // on-peak
        }
    }
    return -1.0; // invalid input
}
