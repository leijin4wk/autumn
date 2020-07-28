//
// Created by leijin on 2020/7/17.
//
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

struct user{
    long id;
    char name[50];
    int age;
};
int main(int argc, char **argv) {
    size_t a=offsetof(struct user,age);
    printf("%ld\n",a);
    printf("%ld\n",sizeof(long));
    struct user * b=malloc(sizeof(struct user));
    char *c=(char *)(&(b->age)) - offsetof(struct user,age);
    printf("%d\n",b);
    printf("%d\n",c);
    return 0;
}