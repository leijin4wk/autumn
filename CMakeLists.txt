cmake_minimum_required(VERSION 3.10)
project(autumn C)

set(CMAKE_C_STANDARD 99)

# 查找当前目录下的所有源文件
aux_source_directory(. DIR_SRCS)

# 添加解析器
add_subdirectory(maple)
# 添加执行器
add_subdirectory(ginkgo)

# 添加存储
add_subdirectory(poplar)

#添加头文件目录
include_directories(maple)

include_directories(ginkgo)

include_directories(poplar)

# 指定生成目标
add_executable(autumn src/autumn.c)

## 添加链接库
target_link_libraries(autumn maple ginkgo poplar)

#dl 动态链接库
target_link_libraries(autumn dl)



