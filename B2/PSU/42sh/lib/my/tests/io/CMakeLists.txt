add_subdirectory(iostream)
add_subdirectory(raw)

libmy_add_test(test-libmy-io "${IOSTREAM_SRC};${RAW_SRC}" my-io)
