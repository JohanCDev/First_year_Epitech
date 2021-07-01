set(SRCROOT "${PROJECT_SOURCE_DIR}/tests/collections/hash_map")

set(HASH_MAP_SRC
    ${SRCROOT}/test_my_hash_map_contains.c
    ${SRCROOT}/test_my_hash_map_drop.c
    ${SRCROOT}/test_my_hash_map_get.c
    ${SRCROOT}/test_my_hash_map_init.c
    ${SRCROOT}/test_my_hash_map_insert.c
    ${SRCROOT}/test_my_hash_map_iter.c
    ${SRCROOT}/test_my_hash_map_remove.c
    PARENT_SCOPE
)
