#include <stdio.h>
#include <windows.h>

int main(void){
    short aim_year = 2021;
    short aim_month = 3;
    short aim_day = 2;

    printf("this is a timer\n");
    printf("this program can helps you to calculates\n");
    printf("how long of Peter's love with Dianna\n");
    printf("what is your year ");

}

int day_of_month(int month,int year){
    // year only two value, 0/1
    // 0 is normal year
    // 1 is a special year, the number of the year is more than the normal year for 1 day.

    if (month == 1){
        return 31;
    }
    if (month == 2){
        if (year == 1){
            return 29;
        } else {
            return 28;
        }
    }
    if (month == 3){
        return 31;
    }
    if (month == 4){
        return 30;
    }
    if (month == 5){
        return 31;
    }
    if (month == 6){
        return 30;
    }
    if (month == 7){
        return 31;
    }
    if (month == 8){
        return 31;
    }
    if (month == 9){
        return 30;
    }
    if (month == 10){
        return 31;
    }
    if (month == 11){
        return 30;
    }
    if (month == 12){
        return 31;
    }
}


