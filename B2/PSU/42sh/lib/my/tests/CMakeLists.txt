include_directories("${PROJECT_SOURCE_DIR}/include")

if (LIBMY_HAS_ASCII_MODULE)
    add_subdirectory(ascii)
endif()

if (LIBMY_HAS_COLLECTIONS_MODULE)
    add_subdirectory(collections)
endif()

if (LIBMY_HAS_HASH_MODULE)
    add_subdirectory(hash)
endif()

if (LIBMY_HAS_IO_MODULE)
    add_subdirectory(io)
endif()

if (LIBMY_HAS_MEMORY_MODULE)
    add_subdirectory(memory)
endif()

if (LIBMY_HAS_PARSING_MODULE)
    add_subdirectory(parsing)
endif()

if (LIBMY_HAS_PRINTF_MODULE)
    add_subdirectory(printf)
endif()
