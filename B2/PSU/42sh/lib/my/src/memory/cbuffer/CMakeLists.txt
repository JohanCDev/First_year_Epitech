set(INCROOT ${PROJECT_SOURCE_DIR}/include/libmy)
set(SRCROOT ${PROJECT_SOURCE_DIR}/src/memory/cbuffer)

set(CBUFFER_SRC
    ${INCROOT}/memory/cbuffer.h
    ${SRCROOT}/my_cbuffer_get_parts.c
    ${SRCROOT}/my_cbuffer_init.c
    ${SRCROOT}/my_cbuffer_pop.c
    ${SRCROOT}/my_cbuffer_push.c
    ${SRCROOT}/my_cbuffer_read.c
    ${SRCROOT}/my_cbuffer_rotate.c
    ${SRCROOT}/my_cbuffer_write.c
)

set(CBUFFER_SRC ${CBUFFER_SRC} PARENT_SCOPE)

source_group("circular buffer" FILES ${CBUFFER_SRC})
