set(SRCROOT ${PROJECT_SOURCE_DIR}/src/token)
set(INCROOT ${PROJECT_SOURCE_DIR}/include)

set(SRC
    ${SRC}
    ${INCROOT}/token.h
    ${SRCROOT}/token_consume.c
    ${SRCROOT}/token_find.c
    ${SRCROOT}/token_stream_drop.c
    ${SRCROOT}/token_stream_init.c
    ${SRCROOT}/token_stream_parse.c
    ${SRCROOT}/token_stream_push.c
    ${SRCROOT}/token_string_2.c
    ${SRCROOT}/token_string.c
    ${SRCROOT}/token_to_str.c
    PARENT_SCOPE
)
