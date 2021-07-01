set(INCROOT ${PROJECT_SOURCE_DIR}/include/libmy)
set(SRCROOT ${PROJECT_SOURCE_DIR}/src/hash)

set(SRC
    ${INCROOT}/hash.h
    ${INCROOT}/hash/config.h
    ${INCROOT}/hash/hash.h
    ${INCROOT}/internal/hash.h
    ${SRCROOT}/hash.h
    ${SRCROOT}/my_hasher_finish.c
    ${SRCROOT}/my_hasher_init.c
    ${SRCROOT}/my_hasher_write.c
    ${SRCROOT}/my_hasher_write_fixed_int.c
    ${SRCROOT}/my_hasher_write_int.c
    ${SRCROOT}/my_hash_load_from_mem.c
    ${SRCROOT}/my_siphash13_rounds.c
)

# IDE source group
source_group("" FILES ${SRC})

libmy_add_module(my-hash SOURCES ${SRC})

# setup dependencies
target_link_libraries(my-hash PUBLIC my-memory)

target_include_directories(my-hash PUBLIC "${PROJECT_SOURCE_DIR}/include")
