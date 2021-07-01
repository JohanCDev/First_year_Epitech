set(INCROOT ${PROJECT_SOURCE_DIR}/include/libmy)
set(SRCROOT ${PROJECT_SOURCE_DIR}/src/memory)

set(SRC
    ${INCROOT}/memory.h
    ${INCROOT}/memory/config.h
    ${INCROOT}/memory/memory.h
    ${INCROOT}/memory/endian.h
    ${INCROOT}/internal/memory.h
    ${SRCROOT}/my_binary_search.c
    ${SRCROOT}/my_memchr.c
    ${SRCROOT}/my_memcmp.c
    ${SRCROOT}/my_memcpy.c
    ${SRCROOT}/my_memmove.c
    ${SRCROOT}/my_memrev.c
    ${SRCROOT}/my_memset.c
    ${SRCROOT}/my_memswap.c
    ${SRCROOT}/my_msort.c
    ${SRCROOT}/my_swap_ptr.c
)

# IDE source group
source_group("" FILES ${SRC})

if (LIBMY_ALLOW_MALLOC_FREE)
    add_subdirectory(alloc)
endif()
add_subdirectory(cbuffer)

libmy_add_module(my-memory SOURCES "${SRC};${ALLOC_SRC};${CBUFFER_SRC}")

target_include_directories(my-memory PUBLIC "${PROJECT_SOURCE_DIR}/include")
