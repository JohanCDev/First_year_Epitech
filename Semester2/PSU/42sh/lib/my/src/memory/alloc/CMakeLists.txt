set(INCROOT ${PROJECT_SOURCE_DIR}/include/libmy)
set(SRCROOT ${PROJECT_SOURCE_DIR}/src/memory/alloc)

set(ALLOC_SRC
    ${INCROOT}/memory/alloc.h
    ${SRCROOT}/my_calloc.c
    ${SRCROOT}/my_memdup.c
    ${SRCROOT}/my_realloc.c
    ${SRCROOT}/my_sfree.c
)

set(ALLOC_SRC ${ALLOC_SRC} PARENT_SCOPE)

source_group("allocation" FILES ${ALLOC_SRC})
