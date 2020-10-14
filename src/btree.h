//
// Created by leijin on 2020/10/14.
//

#ifndef AUTUMN_BTREE_H
#define AUTUMN_BTREE_H

struct b_tree_node_key_item{
    char * key;
    char * data;
    struct b_tree_node_key_item* next;
};

struct b_tree_node{
    char is_leaf;
    short key_size;
    struct b_tree_node_key_item key_list;
};

struct b_tree{
    int key_type;
    struct b_tree_node * root;
};

#endif //AUTUMN_BTREE_H
