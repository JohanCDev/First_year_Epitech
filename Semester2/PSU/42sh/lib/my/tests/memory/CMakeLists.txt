set(SRCROOT "${PROJECT_SOURCE_DIR}/tests/memory")

set(SRC
    ${SRCROOT}/test_my_binary_search.c
    ${SRCROOT}/test_my_endian.c
    ${SRCROOT}/test_my_memchr.c
    ${SRCROOT}/test_my_memcmp.c
    ${SRCROOT}/test_my_memcpy.c
    ${SRCROOT}/test_my_memmove.c
    ${SRCROOT}/test_my_memrev.c
    ${SRCROOT}/test_my_memset.c
    ${SRCROOT}/test_my_memswap.c
    ${SRCROOT}/test_my_msort.c
    ${SRCROOT}/test_my_swap_ptr.c
)

if (LIBMY_ALLOW_MALLOC_FREE)
    add_subdirectory(alloc)
endif()
add_subdirectory(cbuffer)

libmy_add_test(test-libmy-memory "${SRC};${ALLOC_SRC};${CBUFFER_SRC}" my-memory)
