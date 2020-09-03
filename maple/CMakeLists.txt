## 枫树
message(STATUS "build maple start!")
#条件编译
option (DEBUG  "DEBUG" ON)
if (DEBUG)
    message(STATUS "DEBUG OPEN")
    add_definitions(-DYYDEBUG)
endif()

find_package(BISON)

find_package(FLEX)
## lex 生成文件命名并保存
FLEX_TARGET(LEXER test.l ${CMAKE_CURRENT_BINARY_DIR}/lexer.c)
## yacc 生成文件命名并保存
BISON_TARGET(PARSER ./test.y ${CMAKE_CURRENT_BINARY_DIR}/yacc.c
        DEFINES_FILE  ${CMAKE_CURRENT_BINARY_DIR}/yacc.h
        )
include_directories(${CMAKE_CURRENT_BINARY_DIR})
message(STATUS ${CMAKE_CURRENT_SOURCE_DIR})
##包含父项目的头文件，使用全局变量传递解析结果
include_directories(../include)
#添加共有头文件
include_directories(${CMAKE_CURRENT_BINARY_DIR}/include)
add_library(maple ${BISON_PARSER_OUTPUTS}
        ${FLEX_LEXER_OUTPUTS}
        maple.c)

message(STATUS "build maple end!")