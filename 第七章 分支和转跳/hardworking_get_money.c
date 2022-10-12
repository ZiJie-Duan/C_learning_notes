#include <stdio.h>

#define BASE_WAGE 100
#define RATE_ADD_WORK 1.5
#define ADD_WORK_PER_WEEK 40


int main(void){

    int working_time;
    int total_wage;
    int wage = 0;
    int gst = 0;

    printf("how many hours do you want to work? >>");
    scanf("%d",&working_time);

    if (working_time > ADD_WORK_PER_WEEK){
        wage += 40*10;
        working_time -= 40;
        wage += working_time*RATE_ADD_WORK;
    } else {
        wage += working_time*10;
    }

    total_wage = wage;

    if (wage>300){
        gst += 300 * 0.15;
        wage -= 300;
        if (wage >150){
            gst += 150*0.2;
            wage -= 150;
            gst += wage*0.25;
        } else {
            gst += wage * 0.2;
        }
    } else {
        gst += wage * 0.15;
    }

    printf("total wages is %d, GST is %d, your earn %d",\
    total_wage,gst,(total_wage-gst));

    getchar();
    getchar();

}