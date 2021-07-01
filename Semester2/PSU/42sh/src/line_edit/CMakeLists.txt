set(SRCROOT ${PROJECT_SOURCE_DIR}/src/line_edit)
set(INCROOT ${PROJECT_SOURCE_DIR}/include)

add_subdirectory(keybinds)
add_subdirectory(completion)

set(SRC
    ${SRC}
    ${INCROOT}/line_edit.h
    ${SRCROOT}/line_edit_fill.c
    ${SRCROOT}/line_edit_reset.c
    PARENT_SCOPE
)
