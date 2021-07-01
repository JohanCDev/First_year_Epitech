set(INCROOT ${PROJECT_SOURCE_DIR}/include/libmy)
set(SRCROOT ${PROJECT_SOURCE_DIR}/src/ascii)

set(SRC
    ${INCROOT}/ascii.h
    ${INCROOT}/ascii/config.h
    ${INCROOT}/ascii/ascii.h
    ${INCROOT}/ascii/character.h
    ${SRCROOT}/my_revstr.c
    ${SRCROOT}/my_strcapitalize.c
    ${SRCROOT}/my_strcat.c
    ${SRCROOT}/my_strchr.c
    ${SRCROOT}/my_strcmp.c
    ${SRCROOT}/my_strcpy.c
    ${SRCROOT}/my_str_csplit_iter.c
    ${SRCROOT}/my_strechr.c
    ${SRCROOT}/my_stricmp.c
    ${SRCROOT}/my_strincmp.c
    ${SRCROOT}/my_str_isalpha.c
    ${SRCROOT}/my_str_islower.c
    ${SRCROOT}/my_str_isnum.c
    ${SRCROOT}/my_str_isprintable.c
    ${SRCROOT}/my_str_isupper.c
    ${SRCROOT}/my_strlen.c
    ${SRCROOT}/my_strlowcase.c
    ${SRCROOT}/my_strncat.c
    ${SRCROOT}/my_strncmp.c
    ${SRCROOT}/my_strncpy.c
    ${SRCROOT}/my_strndup.c
    ${SRCROOT}/my_strstr.c
    ${SRCROOT}/my_strstr_n.c
    ${SRCROOT}/my_strupcase.c 
)

if (LIBMY_ALLOW_MALLOC_FREE)
    set(SRC
        ${SRCROOT}/my_free_str_array.c
        ${SRCROOT}/my_strdup.c
        ${SRCROOT}/my_str_to_word_array.c
        ${SRC}
    )
endif()

# IDE source group
source_group("" FILES ${SRC})

libmy_add_module(my-ascii SOURCES ${SRC})

# setup dependencies
target_link_libraries(my-ascii PUBLIC my-memory)

target_include_directories(my-ascii PUBLIC "${PROJECT_SOURCE_DIR}/include")
