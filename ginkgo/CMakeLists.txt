## 银杏是秋天的主题之一
message(STATUS "build ginkgo start!")
#添加共有头文件
include_directories(../${CMAKE_CURRENT_SOURCE_DIR}/include)

add_library(ginkgo  ginkgo.c)

message(STATUS "build ginkgo end!")