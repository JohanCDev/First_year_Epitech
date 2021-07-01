set(INCROOT ${PROJECT_SOURCE_DIR}/include/libmy)
set(SRCROOT ${PROJECT_SOURCE_DIR}/src/collections)

if (NOT LIBMY_ALLOW_MALLOC_FREE)
    message(FATAL_ERROR "LibMy collection module requires function 'malloc'")
endif()

set(SRC
    ${INCROOT}/collections.h
    ${INCROOT}/collections/config.h
)

add_subdirectory(hash_map)
add_subdirectory(vec)

# IDE source group
source_group("" FILES ${SRC})

libmy_add_module(my-collections SOURCES ${SRC} ${HASH_MAP_SRC} ${VECTOR_SRC})

# setup dependencies
target_link_libraries(my-collections PUBLIC my-memory my-hash)

target_include_directories(my-collections PUBLIC "${PROJECT_SOURCE_DIR}/include")
