set(SRCROOT "${PROJECT_SOURCE_DIR}/tests/printf")

set(SRC
    ${SRCROOT}/test_my_asprintf.c
    ${SRCROOT}/test_my_dprintf.c
    ${SRCROOT}/test_my_fprintf.c
    ${SRCROOT}/test_my_printf.c
    ${SRCROOT}/test_my_snprintf.c
    ${SRCROOT}/test_my_sprintf.c
    ${SRCROOT}/test_my_vasprintf.c
    ${SRCROOT}/test_my_vdprintf.c
    ${SRCROOT}/test_my_vfprintf.c
    ${SRCROOT}/test_my_vprintf.c
    ${SRCROOT}/test_my_vsnprintf.c
    ${SRCROOT}/test_my_vsprintf.c
)

libmy_add_test(test-libmy-printf "${SRC}" my-printf)
