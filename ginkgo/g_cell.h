//
// Created by Administrator on 2020/8/12.
//

#ifndef AUTUMN_G_CELL_H
#define AUTUMN_G_CELL_H
struct g_cell_key{
    short key_size; //关键字大小
    char key_type; //关键字类型
    char *key; //关键字
};
struct g_cell_column{
    char order;
    char column_type; //字段类型
    short  column_size; //字段大小
};

//存储结构
struct g_cell{
    short payload_size; // 纪录大小
    short key_size; //关键字大小
    char key_type; //关键字类型
    char* key; //关键字
    short head_size; // 头大小
    char* head;//记录头（类型+字段大小）
    char* data;//数据字段
};


#endif //AUTUMN_G_CELL_H
