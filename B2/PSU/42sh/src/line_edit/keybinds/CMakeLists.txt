set(SRCROOT ${PROJECT_SOURCE_DIR}/src/line_edit/keybinds)
set(INCROOT ${PROJECT_SOURCE_DIR}/include)

set(SRC
    ${SRC}
    ${INCROOT}/keybinds.h
    ${SRCROOT}/keybind_backward_word.c
    ${SRCROOT}/keybind_capitalize_word.c
    ${SRCROOT}/keybind_clear_screen.c
    ${SRCROOT}/keybind_completion.c
    ${SRCROOT}/keybind_delete_word.c
    ${SRCROOT}/keybind_delete.c
    ${SRCROOT}/keybind_downcase_word.c
    ${SRCROOT}/keybind_empty.c
    ${SRCROOT}/keybind_eof.c
    ${SRCROOT}/keybind_escape.c
    ${SRCROOT}/keybind_forward_word.c
    ${SRCROOT}/keybind_line_end.c
    ${SRCROOT}/keybind_line_kill.c
    ${SRCROOT}/keybind_line_start.c
    ${SRCROOT}/keybind_move_cursor.c
    ${SRCROOT}/keybind_send_cmd.c
    ${SRCROOT}/keybind_show.c
    ${SRCROOT}/keybind_upcase_word.c
    ${SRCROOT}/keybinds_map.c
    ${SRCROOT}/keybinds.c
    PARENT_SCOPE
)
