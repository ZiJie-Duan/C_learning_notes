#include <stdio.h>
#include <windows.h>

short day_of_month(short month,short year);
short date_to_day(short aim_year, short aim_month, short aim_day,\
short now_year, short now_month, short now_day);
short if_normal_year(short year);

int main(void){
    short aim_year = 2021;
    short aim_month = 3;
    short aim_day = 2;

    short now_year;
    short now_month;
    short now_day;

    short days_total=0;

    printf("LOVE Timer... \nPlease input the date of today.\n");
    printf("year month day ex:[2022 7 13] >>");
    scanf("%hd",&now_year);
    scanf("%hd",&now_month);
    scanf("%hd",&now_day);

    days_total = date_to_day(aim_year,aim_month,aim_day,now_year,now_month,now_day);
    printf("\n\n I have been with Dianna for %d days", days_total);
    getchar();
    getchar();
}

short date_to_day(short aim_year, short aim_month, short aim_day,\
short now_year, short now_month, short now_day){

    int total_days_old = 0;
    short cont_year = 2000;
    short cont_month = 0; 
    short cont_day = 0;

    while (++cont_year < aim_year){
        cont_month = 0;
        while (++cont_month <= 12){
            total_days_old += day_of_month(cont_month,if_normal_year(cont_year));
        }
    }
    cont_month = 0;
    while (++cont_month < aim_month){
        total_days_old += day_of_month(cont_month,cont_year);
    }
    cont_day = 0;
    while (++cont_day <= aim_day){
        total_days_old++;
    }
    if (if_normal_year(aim_year)==1){
        if (aim_month <= 2){
            if (aim_day <= 29){
                total_days_old += 1;
            }
        }
    }
    
    int total_days_now = 0;
    cont_year = 2000;
    cont_month = 0; 
    cont_day = 0;

    while (++cont_year < now_year){
        cont_month = 0;
        while (++cont_month <= 12){
            total_days_now += day_of_month(cont_month,if_normal_year(cont_year));
        }
    }
    cont_month = 0;
    while (++cont_month < now_month){
        total_days_now += day_of_month(cont_month,cont_year);
    }
    cont_day = 0;
    while (++cont_day <= now_day){
        total_days_now++;
    }
    if (if_normal_year(now_year)==1){
        if (now_month > 2){
            total_days_now += 1;
        } else {
            if (now_month == 2){
                if (now_day = 29){
                    total_days_now += 1;
                }
            }
        }
    }

    return total_days_now - total_days_old;
}

short if_normal_year(short year){
    if ((year % 4) == 0){
        return 1; //special year
    } else {
        return 0; //a normal year
    }
}

short day_of_month(short month,short year){
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


