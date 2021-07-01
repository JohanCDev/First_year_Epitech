set(SRCROOT ${PROJECT_SOURCE_DIR}/src/line_edit/completion)
set(INCROOT ${PROJECT_SOURCE_DIR}/include)

set(SRC
    ${SRC}
    ${INCROOT}/completion.h
    ${SRCROOT}/apply_completion.c
    ${SRCROOT}/fill_completion_list.c
    ${SRCROOT}/print_completion_list.c
    PARENT_SCOPE
)
