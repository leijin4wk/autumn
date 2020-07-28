#ifndef AUTUMN_B_PILUS_TREE_H
#define AUTUMN_B_PILUS_TREE_H
#include "autumn_linked_list.h"
//预读的节点数
#define MIN_CACHE_NUM 5

typedef struct free_block {
    struct list_head link;
    off_t offset;
} free_block;


struct autumn_bplustree {
    char *caches;
    int used[MIN_CACHE_NUM];
    char filename[1024];
    int fd;
    off_t root;
    off_t file_size;
    struct list_head free_blocks;
};



int hello(void);

#endif //AUTUMN_B_PILUS_TREE_H
