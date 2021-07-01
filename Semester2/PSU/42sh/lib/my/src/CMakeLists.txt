# set the output directory for LibMy modules
set(LIBRARY_OUTPUT_PATH "${PROJECT_BINARY_DIR}/lib")

# libmy-printf
if (LIBMY_HAS_PRINTF_MODULE)
    add_subdirectory(printf)
    set(LIBMY_HAS_IO_MODULE 1)
    set(LIBMY_HAS_PARSING_MODULE 1)
endif()

# libmy-io
if (LIBMY_HAS_IO_MODULE)
    add_subdirectory(io)
    set(LIBMY_HAS_ASCII_MODULE 1)
    if (LIBMY_ALLOW_MALLOC_FREE)
        set(LIBMY_HAS_COLLECTIONS_MODULE 1)
    endif()
endif()

# libmy-parsing
if (LIBMY_HAS_PARSING_MODULE)
    add_subdirectory(parsing)
    set(LIBMY_HAS_ASCII_MODULE 1)
endif()

# libmy-ascii
if (LIBMY_HAS_ASCII_MODULE)
    add_subdirectory(ascii)
    set(LIBMY_HAS_MEMORY_MODULE 1)
endif()

# libmy-collections
if (LIBMY_HAS_COLLECTIONS_MODULE)
    add_subdirectory(collections)
    set(LIBMY_HAS_MEMORY_MODULE 1)
endif()

# libmy-hash
if (LIBMY_HAS_HASH_MODULE)
    add_subdirectory(hash)
    set(LIBMY_HAS_MEMORY_MODULE 1)
endif()

# libmy-memory
if (LIBMY_HAS_MEMORY_MODULE)
    add_subdirectory(memory)
endif()

