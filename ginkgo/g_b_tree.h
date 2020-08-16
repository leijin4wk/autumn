//
// Created by leijin on 2020/8/6.
//

#ifndef AUTUMN_G_B_TREE_H
#define AUTUMN_G_B_TREE_H
#include "g_page.h"

struct g_b_tree {
    char *caches;
    int used[MIN_CACHE_NUM];
    char filename[1024];
    int fd;
    int level;
    off_t root;
    off_t file_size;
    struct list_head free_blocks;
};


long bplus_tree_get(struct bplus_tree *tree, key_t key);

int bplus_tree_add(struct bplus_tree *tree, key_t key, long data);



struct bplus_tree *b_tree_init(char *filename, int block_size);
void bplus_tree_deinit(struct bplus_tree *tree);

#endif //AUTUMN_G_B_TREE_H
