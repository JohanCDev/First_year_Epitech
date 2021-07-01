set(INCROOT ${PROJECT_SOURCE_DIR}/include/libmy)
set(SRCROOT ${PROJECT_SOURCE_DIR}/src/io/raw)

set(RAW_SRC
    ${INCROOT}/io/raw.h
    ${SRCROOT}/my_putchar.c
    ${SRCROOT}/my_put_nbr.c
    ${SRCROOT}/my_putstr.c
    ${SRCROOT}/my_putuint.c
    ${SRCROOT}/my_showmem.c
    ${SRCROOT}/my_showstr.c
    ${SRCROOT}/my_show_word_array.c
)

set(RAW_SRC ${RAW_SRC} PARENT_SCOPE)

source_group("I/O streams" FILES ${RAW_SRC})
