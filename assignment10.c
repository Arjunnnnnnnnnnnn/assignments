#include <stdio.h>


int isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int getFirstDayOfYear(int year) {
    int d = 1; 
    int m = 13; 
    int y = year - 1;
    
    int k = y % 100;
    int j = y / 100;
    
    int h = (d + (13 * (m + 1)) / 5 + k + (k / 4) + (j / 4) + (5 * j)) % 7;
    
    return (h + 6) % 7;
}

int main() {
    int year;
    
    printf("Enter the year: ");
    if (scanf("%d", &year) != 1 || year < 1) {
        printf("Invalid input. Please enter a positive year.\n");
        return 1;
    }

    char *months[] = {
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };


    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};


    if (isLeapYear(year)) {
        daysInMonth[1] = 29;
    }


    int currentDay = getFirstDayOfYear(year);

    printf("\n=================== CALENDAR - %d ===================\n", year);

    for (int i = 0; i < 12; i++) {
        printf("\n  ------------ %s ------------\n", months[i]);
        printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");

        for (int space = 0; space < currentDay; space++) {
            printf("     ");
        }


        for (int day = 1; day <= daysInMonth[i]; day++) {
            printf("%5d", day);

   
            currentDay++;
            if (currentDay > 6) {
                currentDay = 0;
                printf("\n");
            }
        }
        printf("\n");
    }

    return 0;
}