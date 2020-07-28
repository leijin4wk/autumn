# bison and flex
find_package(BISON)

find_package(FLEX)

FLEX_TARGET(MapleLexer ./test.l ${CMAKE_CURRENT_BINARY_DIR}/lexer.c)

BISON_TARGET(MapleParser ./test.y ${CMAKE_CURRENT_BINARY_DIR}/parser.c
        DEFINES_FILE ${CMAKE_CURRENT_BINARY_DIR}/parser.h
        )

# default header file is parser.hpp
ADD_FLEX_BISON_DEPENDENCY(MapleLexer  MapleParser)

include_directories(${CMAKE_CURRENT_BINARY_DIR})

add_library(maple ${BISON_MapleParser_OUTPUTS}
        ${FLEX_MapleLexer_OUTPUTS}
        )
