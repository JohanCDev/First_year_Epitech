set(SRCROOT ${PROJECT_SOURCE_DIR}/src/command)
set(INCROOT ${PROJECT_SOURCE_DIR}/include)

set(SRC
    ${SRC}
    ${INCROOT}/command.h
    ${SRCROOT}/command_drop.c
    ${SRCROOT}/command_execute_builtin.c
    ${SRCROOT}/command_execute_external.c
    ${SRCROOT}/command_execute.c
    ${SRCROOT}/command_expand_aliases.c
    ${SRCROOT}/command_expand_redirect.c
    ${SRCROOT}/command_expand_vars.c
    ${SRCROOT}/command_globbing.c
    ${SRCROOT}/command_init.c
    ${SRCROOT}/command_need_globbing.c
    ${SRCROOT}/command_open_redirects.c
    ${SRCROOT}/command_parse.c
    ${SRCROOT}/command_resolve.c
    ${SRCROOT}/command_resolve.c
    PARENT_SCOPE
)
