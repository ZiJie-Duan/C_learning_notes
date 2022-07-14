#include <stdio.h>
#include <windows.h>

short day_of_month(short month,short year);

int main(void){
    short aim_year = 2021;
    short aim_month = 3;
    short aim_day = 2;

    short now_year;
    short now_month;
    short now_day;

    short days_total=0;

    printf("LOVE Timer... \nPlease input date now.\n");
    printf("year month day:");
    scanf("%d",&now_year);
    scanf("%d",&now_month);
    scanf("%d",&now_day);

}

short date_to_day(short aim_year, short aim_month, short aim_day,\
short now_year, short now_month, short now_day){

    short total_days = 0;
    short cont_year = aim_year;
    short cont_month = aim_month;
    short cont_day = aim_day;

    if (if_date_bigger_1_year(aim_year,aim_month,aim_day,now_year,now_month,now_day) == 1){
        //the difference of two years is bigger than 1
        //so, program uses fast calculation in the next
        
        //complete the days in first half year
        total_days = total_days + (day_of_month(aim_year,if_normal_year(aim_year)) - aim_day);
        while (++cont_month < 13){
            total_days = total_days + day_of_month(cont_month,if_normal_year(cont_year));
        }
        
        //fast calculate days by years.

    } else {
        return "pass";
    }
}


short if_date_bigger_1_year(short aim_year, short aim_month, short aim_day,\
short now_year, short now_month, short now_day){
    if ((now_year - aim_year) > 1){
        return 1;
    } else {
        if ((now_year - aim_year) == 1){
            if (now_month > aim_month){
                return 1;
            } else {
                if (now_month = aim_month){
                    if (now_day > aim_day){
                        return 1;
                    } else {
                        return 0;
                    }
                } else {
                    return 0;
                }
            }
        } else {
            return 0;
        }
    }

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


