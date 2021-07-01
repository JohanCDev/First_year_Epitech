cmake_minimum_required(VERSION 3.0.0)

project(42sh C)

# Specify the C standard
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED True)

# Add ./cmake/modules to the module path
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake/modules")

# Unit testing
if (BUILD_TEST_SUITE)
    # Check for criterion
    find_package(Criterion REQUIRED)
    set(LIBMY_BUILD_TEST_SUITE True)
    if (USE_GCOV)
        set(LIBMY_USE_GCOV True)
    endif()
    enable_testing()
endif()

# LibMy dependency
set(BUILD_SHARED_LIBS FALSE)
set(LIBMY_INCLUDE_DIR "${PROJECT_SOURCE_DIR}/lib/my/include")
set(LIBMY_MODULES
    ascii
    collections
    hash
    io
    memory
    parsing
    printf
)
set(LIBMY_ALLOWED_FUNCTIONS
    malloc_free
    open
    read
    write
    close
)
add_subdirectory(lib/my)

add_subdirectory(src)

if (BUILD_TEST_SUITE)
    add_subdirectory(tests)
endif()
