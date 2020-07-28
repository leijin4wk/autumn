//
// Created by leijin on 2020/7/27.
//

#include <sys/types.h>

#ifndef AUTUMN_LINKED_LIST_H
#define AUTUMN_LINKED_LIST_H
struct list_head {
    struct list_head *prev, *next;
    off_t offset;
    off_t data;
};
#endif //AUTUMN_LINKED_LIST_H
