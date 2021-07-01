set(SRCROOT "${PROJECT_SOURCE_DIR}/tests/memory/alloc")

set(ALLOC_SRC
    ${SRCROOT}/test_my_calloc.c
    ${SRCROOT}/test_my_memdup.c
    ${SRCROOT}/test_my_realloc.c
    ${SRCROOT}/test_my_sfree.c
)

set(ALLOC_SRC ${ALLOC_SRC} PARENT_SCOPE)
