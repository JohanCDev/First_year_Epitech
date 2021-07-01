# Locates the LibMy libraries
# ---------------------------
#
# This script is a modified version of the old FindSFML.cmake script from the SFML source tree. 
#
# Output
# ------
#
# This script defines the following variables:
# - For each specified module XXX (ascii, collections, hash, io, memory, parsing, printf):
#   - LIBMY_XXX_LIBRARY_DEBUG:   the name of the debug library of the xxx module (set to LIBMY_XXX_LIBRARY_RELEASE is no debug version is found)
#   - LIBMY_XXX_LIBRARY_RELEASE: the name of the release library of the xxx module (set to LIBMY_XXX_LIBRARY_DEBUG is no release version is found)
#   - LIBMY_XXX_LIBRARY:         the name of the library to link to for the xxx module (includes both debug and optimized names if necessary)
#   - LIBMY_XXX_FOUND:           true if either the debug or release library of the xxx module is found
#   - LIBMY_XXX_DEPENDENCIES:    the list of libraries the module depends on, in case of static linking
# - LIBMY_LIBRARIES:    the list of all libraries corresponding to the required modules
# - LIBMY_FOUND:        true if all the required modules are found
# - LIBMY_INCLUDE_DIR:  the path where LibMy headers are located (the directory containing the libmy/config.h file)
# - LIBMY_DEPENDENCIES: the list of libraries LibMy depends on, in case of static linking

# Creates an upper case variable copy of var
function(find_libmy_copy_var var)
    if (DEFINED ${var}) 
        string(TOUPPER ${var} var_upper)
        set(${var_upper} ${${var}} PARENT_SCOPE)
        mark_as_advanced(${var_upper})
    endif()
endfunction()

set(FIND_LibMy_PATHS
    ${LibMy_ROOT}
    $ENV{LibMy_ROOT}
    ${PROJECT_SOURCE_DIR}/../my
    ${PROJECT_SOURCE_DIR}/../LibMy
    /usr/local
    /usr)

find_path(LibMy_INCLUDE_DIR libmy/config.h
    PATH_SUFFIXES include
    PATHS ${FIND_LibMy_PATHS})

# check the version number
set(LibMy_VERSION_OK TRUE)
if (LibMy_FIND_VERSION AND LibMy_INCLUDE_DIR)
    # read libmy/config.h
    file(READ "${LibMy_INCLUDE_DIR}/libmy/config.h" LibMy_CONFIG_H_CONTENTS)

    # extract the version numbers from libmy/config.h
    string(REGEX REPLACE ".*#define LIBMY_VERSION_MAJOR ([0-9]+).*" "\\1" LibMy_VERSION_MAJOR "${LibMy_CONFIG_H_CONTENTS}")
    string(REGEX REPLACE ".*#define LIBMY_VERSION_MINOR ([0-9]+).*" "\\1" LibMy_VERSION_MINOR "${LibMy_CONFIG_H_CONTENTS}")
    string(REGEX REPLACE ".*#define LIBMY_VERSION_PATCH ([0-9]+).*" "\\1" LibMy_VERSION_PATCH "${LibMy_CONFIG_H_CONTENTS}")
    find_libmy_copy_var(LibMy_VERSION_MAJOR)
    find_libmy_copy_var(LibMy_VERSION_MINOR)
    find_libmy_copy_var(LibMy_VERSION_PATCH)

    # transform version numbers into integers
    math(EXPR LibMy_REQUESTED_VERSION "${LibMy_FIND_VERSION_MAJOR} * 10000 + ${LibMy_FIND_VERSION_MINOR} * 100 + ${LibMy_FIND_VERSION_PATCH}")
    math(EXPR LibMy_VERSION "${LibMy_VERSION_MAJOR} * 10000 + ${LibMy_VERSION_MINOR} * 100 + ${LibMy_VERSION_PATCH}")

    # compare them
    if (LibMy_VERSION LESS LibMy_REQUESTED_VERSION)
        set(LibMy_VERSION_OK FALSE)
    endif()
endif()

# find the requested modules
set(LibMy_FOUND TRUE) # will be set to false if one of the required modules is not found
foreach(FIND_LibMy_COMPONENT ${LibMy_FIND_COMPONENTS})
    string(TOLOWER ${FIND_LibMy_COMPONENT} FIND_LibMy_COMPONENT_LOWER)
    string(TOUPPER ${FIND_LibMy_COMPONENT} FIND_LibMy_COMPONENT_UPPER)
    set(FIND_LibMy_COMPONENT_NAME ${FIND_LibMy_COMPONENT_LOWER})

    # static release library
    find_library(LibMy_${FIND_LibMy_COMPONENT_UPPER}_LIBRARY_STATIC_RELEASE
        NAMES ${FIND_LibMy_COMPONENT_NAME}-static
        PATH_SUFFIXES lib64 lib build/lib
        PATHS ${FIND_LibMy_PATHS})

    # static debug library
    find_library(LibMy_${FIND_LibMy_COMPONENT_UPPER}_LIBRARY_STATIC_DEBUG
        NAMES ${FIND_LibMy_COMPONENT_NAME}-static-debug
        PATH_SUFFIXES lib64 lib build/lib
        PATHS ${FIND_LibMy_PATHS})

    # dynamic release library
    find_library(LibMy_${FIND_LibMy_COMPONENT_UPPER}_LIBRARY_DYNAMIC_RELEASE
        NAMES ${FIND_LibMy_COMPONENT_NAME}
        PATH_SUFFIXES lib64 lib build/lib
        PATHS ${FIND_LibMy_PATHS})

    # dynamic debug library
    find_library(LibMy_${FIND_LibMy_COMPONENT_UPPER}_LIBRARY_DYNAMIC_DEBUG
        NAMES ${FIND_LibMy_COMPONENT_NAME}-debug
        PATH_SUFFIXES lib64 lib build/lib
        PATHS ${FIND_LibMy_PATHS})

    # choose the entries that fit the requested link type
    if (LibMy_STATIC_LIBRARIES)
        if (LibMy_${FIND_LibMy_COMPONENT_UPPER}_LIBRARY_STATIC_RELEASE)
            set(LibMy_${FIND_LibMy_COMPONENT_UPPER}_LIBRARY_RELEASE ${LibMy_${FIND_LibMy_COMPONENT_UPPER}_LIBRARY_STATIC_RELEASE})
        endif()
        if (LibMy_${FIND_LibMy_COMPONENT_UPPER}_LIBRARY_STATIC_DEBUG)
            set(LibMy_${FIND_LibMy_COMPONENT_UPPER}_LIBRARY_DEBUG ${LibMy_${FIND_LibMy_COMPONENT_UPPER}_LIBRARY_STATIC_DEBUG})
        endif()
    else()
        if (LibMy_${FIND_LibMy_COMPONENT_UPPER}_LIBRARY_DYNAMIC_RELEASE)
            set(LibMy_${FIND_LibMy_COMPONENT_UPPER}_LIBRARY_RELEASE ${LibMy_${FIND_LibMy_COMPONENT_UPPER}_LIBRARY_DYNAMIC_RELEASE})
        endif()
        if (LibMy_${FIND_LibMy_COMPONENT_UPPER}_LIBRARY_DYNAMIC_DEBUG)
            set(LibMy_${FIND_LibMy_COMPONENT_UPPER}_LIBRARY_DEBUG ${LibMy_${FIND_LibMy_COMPONENT_UPPER}_LIBRARY_DYNAMIC_DEBUG})
        endif()
    endif()

    if (LibMy_${FIND_LibMy_COMPONENT_UPPER}_LIBRARY_DEBUG OR LibMy_${FIND_LibMy_COMPONENT_UPPER}_LIBRARY_RELEASE)
        # library found
        set(LibMy_${FIND_LibMy_COMPONENT_UPPER}_FOUND TRUE)

        # if both are found, set LibMy_XXX_LIBRARY to contain both
        if (LibMy_${FIND_LibMy_COMPONENT_UPPER}_LIBRARY_DEBUG AND LibMy_${FIND_LibMy_COMPONENT_UPPER}_LIBRARY_RELEASE)
            set(LibMy_${FIND_LibMy_COMPONENT_UPPER}_LIBRARY
                debug     ${LibMy_${FIND_LibMy_COMPONENT_UPPER}_LIBRARY_DEBUG}
                optimized ${LibMy_${FIND_LibMy_COMPONENT_UPPER}_LIBRARY_RELEASE})
        endif()

        # if only one debug/release variant is found, set the other to be equal to the found one
        if (LibMy_${FIND_LibMy_COMPONENT_UPPER}_LIBRARY_DEBUG AND NOT LibMy_${FIND_LibMy_COMPONENT_UPPER}_LIBRARY_RELEASE)
            # debug and not release
            set(LibMy_${FIND_LibMy_COMPONENT_UPPER}_LIBRARY_RELEASE ${LibMy_${FIND_LibMy_COMPONENT_UPPER}_LIBRARY_DEBUG})
            set(LibMy_${FIND_LibMy_COMPONENT_UPPER}_LIBRARY         ${LibMy_${FIND_LibMy_COMPONENT_UPPER}_LIBRARY_DEBUG})
        endif()
        if (LibMy_${FIND_LibMy_COMPONENT_UPPER}_LIBRARY_RELEASE AND NOT LibMy_${FIND_LibMy_COMPONENT_UPPER}_LIBRARY_DEBUG)
            # release and not debug
            set(LibMy_${FIND_LibMy_COMPONENT_UPPER}_LIBRARY_DEBUG ${LibMy_${FIND_LibMy_COMPONENT_UPPER}_LIBRARY_RELEASE})
            set(LibMy_${FIND_LibMy_COMPONENT_UPPER}_LIBRARY       ${LibMy_${FIND_LibMy_COMPONENT_UPPER}_LIBRARY_RELEASE})
        endif()
    else()
        # library not found
        set(LibMy_FOUND FALSE)
        set(LibMy_${FIND_LibMy_COMPONENT_UPPER}_FOUND FALSE)
        set(LibMy_${FIND_LibMy_COMPONENT_UPPER}_LIBRARY "")
        set(FIND_LibMy_MISSING "${FIND_LibMy_MISSING} LibMy_${FIND_LibMy_COMPONENT_UPPER}_LIBRARY")
    endif()

    # mark as advanced
    mark_as_advanced(LibMy_${FIND_LibMy_COMPONENT_UPPER}_LIBRARY
        LibMy_${FIND_LibMy_COMPONENT_UPPER}_LIBRARY_RELEASE
        LibMy_${FIND_LibMy_COMPONENT_UPPER}_LIBRARY_DEBUG
        LibMy_${FIND_LibMy_COMPONENT_UPPER}_LIBRARY_STATIC_RELEASE
        LibMy_${FIND_LibMy_COMPONENT_UPPER}_LIBRARY_STATIC_DEBUG
        LibMy_${FIND_LibMy_COMPONENT_UPPER}_LIBRARY_DYNAMIC_RELEASE
        LibMy_${FIND_LibMy_COMPONENT_UPPER}_LIBRARY_DYNAMIC_DEBUG)

    find_libmy_copy_var(LibMy_${FIND_LibMy_COMPONENT_UPPER}_LIBRARY)
    find_libmy_copy_var(LibMy_${FIND_LibMy_COMPONENT_UPPER}_LIBRARY_RELEASE)
    find_libmy_copy_var(LibMy_${FIND_LibMy_COMPONENT_UPPER}_LIBRARY_DEBUG)
    find_libmy_copy_var(LibMy_${FIND_LibMy_COMPONENT_UPPER}_FOUND)

    # add to the global list of libraries
    set(LibMy_LIBRARIES ${LibMy_LIBRARIES} "${LibMy_${FIND_LibMy_COMPONENT_UPPER}_LIBRARY}")
endforeach()

# handle errors
if (NOT LibMy_VERSION_OK)
    # LIBMY version not ok
    set(FIND_LibMy_ERROR "LIBMY found but version too low (requested: ${LibMy_FIND_VERSION}, found: ${LibMy_VERSION_MAJOR}.${LibMy_VERSION_MINOR}.${LibMy_VERSION_PATCH})")
    set(LibMy_FOUND FALSE)
elseif (LibMy_STATIC_LIBRARIES AND FIND_LibMy_DEPENDENCIES_NOTFOUND)
    set(FIND_LibMy_ERROR "LIBMY found but some of its dependencies are missing (${FIND_LibMy_DEPENDENCIES_NOTFOUND})")
    set(LibMy_FOUND FALSE)
elseif (NOT LibMy_FOUND)
    # include directory or library not found
    set(FIND_LibMy_ERROR "Could NOT find LIBMY (missing: ${FIND_LibMy_MISSING})")
endif()
if (NOT LibMy_FOUND)
    if (LibMy_FIND_REQUIRED)
        # fatal error
        message(FATAL_ERROR ${FIND_LibMy_ERROR})
    elseif(NOT LibMy_FIND_QUIETLY)
        # error but continue
        message("${FIND_LibMy_ERROR}")
    endif()
endif()

find_libmy_copy_var(LibMy_LIBRARIES)
find_libmy_copy_var(LibMy_FOUND)
find_libmy_copy_var(LibMy_INCLUDE_DIR)
find_libmy_copy_var(LibMy_DEPENDENCIES)

# handle success
if (LibMy_FOUND AND NOT LibMy_FIND_QUIETLY)
    message(STATUS "Found LibMy ${LibMy_VERSION_MAJOR}.${LibMy_VERSION_MINOR}.${LibMy_VERSION_PATCH} in ${LibMy_INCLUDE_DIR}")
endif()
