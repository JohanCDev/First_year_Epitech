set(SRCROOT "${PROJECT_SOURCE_DIR}/tests/ascii")

set(SRC
    ${SRCROOT}/test_my_revstr.c
    ${SRCROOT}/test_my_strcapitalize.c
    ${SRCROOT}/test_my_strcat.c
    ${SRCROOT}/test_my_strchr.c
    ${SRCROOT}/test_my_strcmp.c
    ${SRCROOT}/test_my_strcpy.c
    ${SRCROOT}/test_my_str_csplit_iter.c
    ${SRCROOT}/test_my_strechr.c
    ${SRCROOT}/test_my_stricmp.c
    ${SRCROOT}/test_my_strincmp.c
    ${SRCROOT}/test_my_str_isalpha.c
    ${SRCROOT}/test_my_str_islower.c
    ${SRCROOT}/test_my_str_isnum.c
    ${SRCROOT}/test_my_str_isprintable.c
    ${SRCROOT}/test_my_str_isupper.c
    ${SRCROOT}/test_my_strlen.c
    ${SRCROOT}/test_my_strlowcase.c
    ${SRCROOT}/test_my_strncat.c
    ${SRCROOT}/test_my_strncmp.c
    ${SRCROOT}/test_my_strncpy.c
    ${SRCROOT}/test_my_strstr.c
    ${SRCROOT}/test_my_strstr_n.c
    ${SRCROOT}/test_my_strupcase.c
)

if (LIBMY_ALLOW_MALLOC_FREE)
    set(SRC
        ${SRCROOT}/test_my_free_str_array.c
        ${SRCROOT}/test_my_strdup.c
        ${SRCROOT}/test_my_strndup.c
        ${SRCROOT}/test_my_str_to_word_array.c
        ${SRC}
    )
endif()

add_subdirectory(character)

libmy_add_test(test-libmy-ascii "${SRC};${CHARACTER_SRC}" my-ascii)
