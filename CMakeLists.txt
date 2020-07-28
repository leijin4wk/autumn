cmake_minimum_required(VERSION 3.10)
project(oct C)

set(CMAKE_C_STANDARD 99)

include_directories(include)
# 查找当前目录下的所有源文件
# 并将名称保存到 DIR_SRCS 变量
aux_source_directory(. DIR_SRCS)

# 添加 math 子目录
add_subdirectory(lib)

# 指定生成目标
add_executable(oct test/test1.c include/autumn_linked_list.h)

# 添加链接库
target_link_libraries(oct autumn)

# 启用测试
enable_testing()

# 测试程序是否成功运行
add_test (test1 oct)
