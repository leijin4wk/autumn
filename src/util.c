//
// Created by Administrator on 2020/8/16.
//
#include <stdlib.h>
char* substring(const char* ch,int pos,int length)
{
    //定义字符指针 指向传递进来的ch地址
    char* pch=ch;
    //通过calloc来分配一个length长度的字符数组，返回的是字符指针。
    char* subch=(char*)calloc(sizeof(char),length+1);
    int i;
    pch=pch+pos;
    //是pch指针指向pos位置。
    for(i=0;i<length;i++)
    {
        subch[i]=*(pch++);
        //循环遍历赋值数组。
    }
    subch[length]='\0';//加上字符串结束符。
    return subch;  //返回分配的字符数组地址。
}