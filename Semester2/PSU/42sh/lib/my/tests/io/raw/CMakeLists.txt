set(SRCROOT "${PROJECT_SOURCE_DIR}/tests/io/raw")

set(RAW_SRC
    ${SRCROOT}/test_my_putchar.c
    ${SRCROOT}/test_my_put_nbr.c
    ${SRCROOT}/test_my_putstr.c
    ${SRCROOT}/test_my_putuint.c
    ${SRCROOT}/test_my_show_word_array.c
    ${SRCROOT}/test_my_showmem.c
    ${SRCROOT}/test_my_showstr.c
)

set( RAW_SRC ${RAW_SRC} PARENT_SCOPE)
