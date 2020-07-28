# bison and flex
find_package(BISON)

find_package(FLEX)

FLEX_TARGET(LEXER ./test.l ${CMAKE_CURRENT_BINARY_DIR}/lexer.c)

message(${FLEX_LEXER_OUTPUTS})

BISON_TARGET(PARSER ./test.y ${CMAKE_CURRENT_BINARY_DIR}/yacc.c
        DEFINES_FILE  ${CMAKE_CURRENT_BINARY_DIR}/yacc.h
        )
message(${BISON_PARSER_OUTPUTS})

include_directories(${CMAKE_CURRENT_BINARY_DIR})

add_library(maple ${BISON_PARSER_OUTPUTS}
        ${FLEX_LEXER_OUTPUTS}
        )

