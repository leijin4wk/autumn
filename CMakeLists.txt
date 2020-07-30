cmake_minimum_required(VERSION 3.10)
project(autumn C)

set(CMAKE_C_STANDARD 99)

# 查找当前目录下的所有源文件
aux_source_directory(. DIR_SRCS)

# 添加解析器
add_subdirectory(maple)

include_directories(${CMAKE_CURRENT_BINARY_DIR}/maple)

# 指定生成目标
add_executable(autumn src/autumn.c)

## 添加链接库
target_link_libraries(autumn maple)

#dl 动态链接库
target_link_libraries(autumn dl)

