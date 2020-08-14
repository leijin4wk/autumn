//
// Created by leijin on 2020/8/3.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ginkgo.h"

void g_hello(){
    char buf[PAGE_SIZE];

    printf("int %d\n",sizeof(int));
    printf("long %d\n",sizeof(long));
    printf("float %d\n",sizeof(float));
    printf("double %d\n",sizeof(double));

}