## 银杏是秋天的主题之一
message(STATUS "build ginkgo start!")
#添加共有头文件
include_directories(../include)

add_library(ginkgo  ginkgo.c g_b_tree.c g_b_tree.h g_os.h g_os.c g_page.h g_record.h)

message(STATUS "build ginkgo end!")