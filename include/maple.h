//
// Created by leijin on 2020/8/3.
//

#ifndef AUTUMN_MAPLE_H
#define AUTUMN_MAPLE_H

#include <stdlib.h>

struct statement {
    char* name;
    int age;
    struct statement *next;
};

struct statement*  m_parser(const char * text);

#endif //AUTUMN_MAPLE_H
