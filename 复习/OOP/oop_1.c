#include <stdio.h>


struct Good_Guy
{
    /* data */
    char *name;
    void (*constructor) (struct Good_Guy *self, char *name);
    void (*say_hello) (struct Good_Guy *self);
    void (*say_bey) (struct Good_Guy *self);
};


void Good_Guy_constructor(struct Good_Guy *self, char *name);
void Good_Guy_say_hello(struct Good_Guy *self);
void Good_Guy_say_bey(struct Good_Guy *self);

int main(void){

    struct Good_Guy p1 = 
    {
        .constructor = Good_Guy_constructor,
        .say_hello = Good_Guy_say_hello,
        .say_bey = Good_Guy_say_bey
    };
    p1.constructor(&p1,"Peter Duan");
    p1.say_hello(&p1);
    p1.say_bey(&p1);
    getchar();
}

void Good_Guy_constructor(struct Good_Guy *self, char *name){
    self->name = name;
}

void Good_Guy_say_hello(struct Good_Guy *self){
    printf("\nHello! %s!",self->name);
}

void Good_Guy_say_bey(struct Good_Guy *self){
    printf("\nBey! %s!",self->name);
}

// class 特性，面向对象特性
// 1，封装 属性，方法 -> 方法可以使用属性
// 2，继承 覆写，拓展，多继承
// 3，多态



// typedef struct 
// {
//     int type; //private, public
//     void *value;
// } oop_attributes;
