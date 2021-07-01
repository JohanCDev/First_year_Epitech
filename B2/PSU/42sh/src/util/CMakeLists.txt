set(SRCROOT ${PROJECT_SOURCE_DIR}/src/util)
set(INCROOT ${PROJECT_SOURCE_DIR}/include)

set(SRC
    ${SRC}
    ${INCROOT}/util.h
    ${SRCROOT}/column_print.c
    ${SRCROOT}/create_file_path.c
    ${SRCROOT}/free_entry.c
    ${SRCROOT}/lstr.c
    ${SRCROOT}/parsing.c
    ${SRCROOT}/sclose.c
    ${SRCROOT}/split_at.c
    ${SRCROOT}/words.c
    PARENT_SCOPE
)
