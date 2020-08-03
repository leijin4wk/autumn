//
// Created by Administrator on 2020/7/28.
//
#include "maple.h"
#include "ginkgo.h"
#include "poplar.h"
int main(int argc, char **argv) {
    char* string = "aa=1bb=2cc=33";
    m_parser(string);
    g_hello();
    p_hello();
    return 0;
}