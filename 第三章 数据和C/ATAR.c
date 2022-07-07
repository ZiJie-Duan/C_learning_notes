#include <stdio.h>

int main(void){
    // this is a ATAR calculator

    float chinese = 0.05;
    float eal = 0.012;
    float acc = 0.0231;
    float math = 0.0523;
    float phy = 0.31834;

    // input data from users
    float chinese_i;
    float eal_i;
    float acc_i;
    float math_i;
    float phy_i;

    float total = 0;
    float calculate(float score, float add);

    printf("Welcome ATAR-PETIO calculator!\n");
    printf("This calculator can help you to pridict your REAL-ATAR\n");
    printf("\n  now please input your chinese score:");
    scanf("%f",&chinese_i);
    printf("\n  now please input your eal score:");
    scanf("%f",&eal_i);
    printf("\n  now please input your acc score:");
    scanf("%f",&acc_i);
    printf("\n  now please input your math score:");
    scanf("%f",&math_i);
    printf("\n  now please input your phy score:");
    scanf("%f",&phy_i);
    
    total = total + calculate(chinese_i,chinese);
    total = total + calculate(eal_i,eal);
    total = total + calculate(acc_i,acc);
    total = total + calculate(math_i,math);
    total = total + calculate(phy_i,phy);
    printf("your total score is: %f",total);

    scanf("%f",&chinese_i);


}

float calculate(float score, float add){
    float singal_mark;
    float add_mark = score * add;
    singal_mark = score + add_mark;
    return singal_mark;
}