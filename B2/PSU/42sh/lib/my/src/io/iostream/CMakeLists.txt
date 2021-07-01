set(INCROOT ${PROJECT_SOURCE_DIR}/include/libmy)
set(SRCROOT ${PROJECT_SOURCE_DIR}/src/io/iostream)

set(IOSTREAM_SRC
    ${INCROOT}/io/iostream.h
    ${INCROOT}/internal/iostream.h
    ${SRCROOT}/iostream.h
    ${SRCROOT}/my_fclose_allow_close.c
    ${SRCROOT}/my_fclose.c
    ${SRCROOT}/my_feof.c
    ${SRCROOT}/my_fflush.c
    ${SRCROOT}/my_ffree.c
    ${SRCROOT}/my_fget_buffer.c
    ${SRCROOT}/my_finit.c
    ${SRCROOT}/my_flush_iostream.c
    ${SRCROOT}/my_fopen.c
    ${SRCROOT}/my_fopen.h
    ${SRCROOT}/my_fputc.c
    ${SRCROOT}/my_fputint.c
    ${SRCROOT}/my_fputintmax_t_base.c
    ${SRCROOT}/my_fputs.c
    ${SRCROOT}/my_fputs_endl.c
    ${SRCROOT}/my_fputuint.c
    ${SRCROOT}/my_fputuintmax_t_base.c
    ${SRCROOT}/my_fread_allow_read.c
    ${SRCROOT}/my_fread.c
    ${SRCROOT}/my_fread_to_string_allow_read.c
    ${SRCROOT}/my_fread_to_string.c
    ${SRCROOT}/my_free_iostream.c
    ${SRCROOT}/my_frputc.c
    ${SRCROOT}/my_fset_buffer.c
    ${SRCROOT}/my_fset_threshold.c
    ${SRCROOT}/my_fwrite.c
    ${SRCROOT}/my_getdelim.c
    ${SRCROOT}/my_get_iostream.c
    ${SRCROOT}/my_init_iostream.c
    ${SRCROOT}/my_is_iostream.c
)

if ("close" IN_LIST LIBMY_ALLOWED_FUNCTIONS_LIST)
    set(IOSTREAM_SRC
        ${IOSTREAM_SRC}
        ${SRCROOT}/my_fclose_allow_close.c
    )
endif()

if ("read" IN_LIST LIBMY_ALLOWED_FUNCTIONS_LIST)
    set(IOSTREAM_SRC
        ${IOSTREAM_SRC}
        ${SRCROOT}/my_fread_allow_read.c
        ${SRCROOT}/my_fread_to_string_allow_read.c
    )
endif()

if (LIBMY_ALLOW_MALLOC_FREE)
    set(IOSTREAM_SRC
        ${IOSTREAM_SRC}
        ${SRCROOT}/my_fread_to_string.c
        ${SRCROOT}/my_getdelim.c
    )
endif()

set(IOSTREAM_SRC ${IOSTREAM_SRC} PARENT_SCOPE)

source_group("I/O streams" FILES ${IOSTREAM_SRC})
