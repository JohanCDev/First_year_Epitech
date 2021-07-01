set(SRCROOT ${PROJECT_SOURCE_DIR}/src/variables)
set(INCROOT ${PROJECT_SOURCE_DIR}/include)

set(SRC
    ${SRC}
    ${INCROOT}/variables.h
    ${SRCROOT}/check_var_name.c
    ${SRCROOT}/expand_var.c
    ${SRCROOT}/expand_vars.c
    ${SRCROOT}/print_var_error.c
    PARENT_SCOPE
)
