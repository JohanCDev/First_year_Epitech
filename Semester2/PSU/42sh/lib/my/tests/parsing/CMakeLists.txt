set(SRCROOT "${PROJECT_SOURCE_DIR}/tests/parsing")

set(SRC
    ${SRCROOT}/test_my_getnbr_base.c
    ${SRCROOT}/test_my_getnbr.c
    ${SRCROOT}/test_my_next_size_t.c
    ${SRCROOT}/test_my_next_uint.c
)

libmy_add_test(test-libmy-parsing "${SRC}" my-parsing)
