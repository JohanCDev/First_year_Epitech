cmake_minimum_required(VERSION 3.9.0)

# include the LibMy specific macros
include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/macros.cmake)

# determine whether to create a debug or release build
libmy_set_option(CMAKE_BUILD_TYPE Release STRING "Choose the type of build (Debug or Release)")

# setup version numbers
set(VERSION_MAJOR 0)
set(VERSION_MINOR 3)
set(VERSION_PATCH 10)
set(VERSION "${VERSION_MAJOR}.${VERSION_MINOR}.${VERSION_PATCH}")

project(LibMy
    VERSION ${VERSION} 
    LANGUAGES C)

# specify the C standard
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED True)

# include the config file
include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/config.cmake)

# add an option for choosing the build type (shared or static)
libmy_set_option(BUILD_SHARED_LIBS TRUE BOOL "TRUE to build LibMy as shared libraries, FALSE to build it as static libraries")

# add an option to control which modules are built
libmy_set_option(LIBMY_MODULES "ascii;collections;hash;io;memory;parsing;printf" STRING "LibMy module to build. currently available:
- ascii
- collections
- hash
- io
- memory
- parsing
- printf")

libmy_enable_module(ascii LIBMY_HAS_ASCII_MODULE)
libmy_enable_module(collections LIBMY_HAS_COLLECTIONS_MODULE)
libmy_enable_module(hash LIBMY_HAS_HASH_MODULE)
libmy_enable_module(io LIBMY_HAS_IO_MODULE)
libmy_enable_module(memory LIBMY_HAS_MEMORY_MODULE)
libmy_enable_module(parsing LIBMY_HAS_PARSING_MODULE)
libmy_enable_module(printf LIBMY_HAS_PRINTF_MODULE)

# add an option for building the API documentation
libmy_set_option(LIBMY_BUILD_DOC FALSE BOOL "TRUE to generate the API documentation, FALSE to ignore it")

# add an option for building the test suite
libmy_set_option(LIBMY_BUILD_TEST_SUITE FALSE BOOL "TRUE to build the LibMy test suite, FALSE to ignore it")

# add an option for choosing allowed system functions
libmy_set_option(LIBMY_ALLOWED_FUNCTIONS "malloc_free;open;read;close" STRING "LibMy allowed functions flags. currently available:
- malloc_free
- open
- read
- close")

libmy_set_option(LIBMY_USE_GCOV FALSE BOOL "TRUE to enable GCC's code coverage. FALSE to ignore it")

set(LIBMY_ALLOWED_FUNCTIONS_LIST ${LIBMY_ALLOWED_FUNCTIONS})
separate_arguments(LIBMY_ALLOWED_FUNCTIONS)

# enable project folders
set_property(GLOBAL PROPERTY USE_FOLDERS ON)
set_property(GLOBAL PROPERTY PREDEFINED_TARGETS_FOLDER "CMake")

# Preprocessor definitions
libmy_add_allowed_function(malloc_free LIBMY_ALLOW_MALLOC_FREE)
libmy_add_allowed_function(open LIBMY_ALLOW_OPEN)
libmy_add_allowed_function(read LIBMY_ALLOW_READ)
libmy_add_allowed_function(close LIBMY_ALLOW_CLOSE)

if (LIBMY_BUILD_TEST_SUITE)
    # disable assertions when running unit tests
    add_compile_definitions(NDEBUG=1)
endif()

include (TestBigEndian)

TEST_BIG_ENDIAN(LIBMY_IS_BIG_ENDIAN)
if (LIBMY_IS_BIG_ENDIAN)
    set(LIBMY_ENDIAN LIBMY_BIG_ENDIAN)
else()
    set(LIBMY_ENDIAN LIBMY_LITTLE_ENDIAN)
endif()


configure_file(${PROJECT_SOURCE_DIR}/include/libmy/config.h.in ${PROJECT_SOURCE_DIR}/include/libmy/config.h @ONLY)

# add the subdirectories
add_subdirectory(src)

# build documentation
if (LIBMY_BUILD_DOC)
    add_subdirectory(doc)
endif()

# Add ./cmake/modules to the module path
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake/modules")

if (LIBMY_BUILD_TEST_SUITE)
    # Check for criterion
    find_package (Criterion REQUIRED)
    enable_testing()
    add_subdirectory(tests)
endif()
