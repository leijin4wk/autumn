## 枫树是秋天的主题之一
message(STATUS "build maple start!")
#条件编译
option (DEBUG  "DEBUG" ON)
if (DEBUG)
    message(STATUS "DEBUG OPEN")
    add_definitions(-DYYDEBUG)
endif()

find_package(BISON)

find_package(FLEX)

FLEX_TARGET(LEXER test.lex ${CMAKE_CURRENT_BINARY_DIR}/lexer.c)

message(STATUS ${FLEX_LEXER_OUTPUTS})

BISON_TARGET(PARSER ./test.y ${CMAKE_CURRENT_BINARY_DIR}/yacc.c
        DEFINES_FILE  ${CMAKE_CURRENT_BINARY_DIR}/yacc.h
        )
message(STATUS ${BISON_PARSER_OUTPUTS})


include_directories(${CMAKE_CURRENT_BINARY_DIR})

add_library(maple ${BISON_PARSER_OUTPUTS}
        ${FLEX_LEXER_OUTPUTS}
        maple.c maple.h)

message(STATUS "build maple end!")