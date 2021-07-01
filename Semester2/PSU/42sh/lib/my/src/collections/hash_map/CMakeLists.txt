set(INCROOT ${PROJECT_SOURCE_DIR}/include/libmy)
set(SRCROOT ${PROJECT_SOURCE_DIR}/src/collections/hash_map)

set(HASH_MAP_SRC
    ${INCROOT}/collections/hash_map.h
    ${INCROOT}/internal/hash_map.h
    ${SRCROOT}/my_hash_map_contains.c
    ${SRCROOT}/my_hash_map_cstr_key.c
    ${SRCROOT}/my_hash_map_drop.c
    ${SRCROOT}/my_hash_map_get.c
    ${SRCROOT}/my_hash_map_hash_key.c
    ${SRCROOT}/my_hash_map_init.c
    ${SRCROOT}/my_hash_map_insert_entry.c
    ${SRCROOT}/my_hash_map_insert.c
    ${SRCROOT}/my_hash_map_iter.c
    ${SRCROOT}/my_hash_map_remove.c
)
set(HASH_MAP_SRC ${HASH_MAP_SRC} PARENT_SCOPE)

source_group("hash map" FILES ${HASH_MAP_SRC})
