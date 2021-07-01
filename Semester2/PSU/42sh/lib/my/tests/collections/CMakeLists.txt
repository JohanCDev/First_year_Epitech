add_subdirectory(vec)
add_subdirectory(hash_map)

libmy_add_test(test-libmy-collections "${VECTOR_SRC};${HASH_MAP_SRC}" my-collections)
