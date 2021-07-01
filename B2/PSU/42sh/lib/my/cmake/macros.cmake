# Common LibMy macros and functions

# Defines a macro that helps defining an option
macro(libmy_set_option var default type docstring)
    if(NOT DEFINED ${var})
        set(${var} ${default})
    endif()
    set(${var} ${${var}} CACHE ${type} ${docstring} FORCE)
endmacro()

# Adds a new target that is a LibMy module
macro(libmy_add_module target)
    # argument parsing
    cmake_parse_arguments(ADD_MODULE "STATIC" "" "SOURCES" ${ARGN})
    if (NOT "${ADD_MODULE_UNPARSED_ARGUMENTS}" STREQUAL "")
        message(FATAL_ERROR "Extra unparsed arguments when calling libmy_add_module: ${ADD_MODULE_UNPARSED_ARGUMENTS}")
    endif()
    
    # create the target
    if (ADD_MODULE_STATIC)
        add_library(${target} STATIC ${ADD_MODULE_SOURCES})
    else()
        add_library(${target} ${ADD_MODULE_SOURCES})
    endif()

    # define the export symbol of the module
    string(REPLACE "-" "_" NAME_UPPER "${target}")
    string(TOUPPER "${NAME_UPPER}" NAME_UPPER)
    set_target_properties(${target} PROPERTIES DEFINE_SYMBOL ${NAME_UPPER}_EXPORTS)

    # adjust output suffix depending on output type
    if (BUILD_SHARED_LIBS AND NOT ADD_MODULE_STATIC)
        set_target_properties(${target} PROPERTIES DEBUG_POSTFIX -debug)
    else()
        set_target_properties(${target} PROPERTIES DEBUG_POSTFIX -static-debug)
        set_target_properties(${target} PROPERTIES RELEASE_POSTFIX -static)
        set_target_properties(${target} PROPERTIES MINSIZEREL_POSTFIX -static)
        set_target_properties(${target} PROPERTIES RELWITHDEBINFO_POSTFIX -static)
    endif()

    # set version and soversion of target
    set_target_properties(${target} PROPERTIES SOVERSION ${VERSION_MAJOR}.${VERSION_MINOR})
    set_target_properties(${target} PROPERTIES VERSION ${VERSION_MAJOR}.${VERSION_MINOR}.${VERSION_PATCH})

    # set the target's folder (for IDEs)
    set_target_properties(${target} PROPERTIES FOLDER "LibMy")

    # if using gcc >= 4.0 or clang >= 3.0 on a non-Windows platform, we must hide public symbols by default
    # (exported ones are explicitly marked)
    if((LIBMY_COMPILER_GCC AND NOT LIBMY_GCC_VERSION VERSION_LESS "4") OR (LIBMY_COMPILER_CLANG AND NOT LIBMY_CLANG_VERSION VERSION_LESS "3"))
        set_target_properties(${target} PROPERTIES COMPILE_FLAGS -fvisibility=hidden)
    endif()

    # Enable Warnings
    if (CMAKE_COMPILER_IS_GNUCC)
        if (LIBMY_USE_GCOV)
            target_link_options(${target} PRIVATE "-lgcov" "--coverage")
            target_compile_options(${target} PRIVATE "--coverage" "-fprofile-arcs" "-ftest-coverage")
        endif()
        # Compile Options
        target_compile_options(${target} PRIVATE
            "-Wall" "-Wextra" "-Wshadow" "-Wno-abi"
            "$<$<CONFIG:RELEASE>:-O3;-fno-builtin>"
            "$<$<CONFIG:DEBUG>:-O0;-g3;-ggdb>"
        )
    endif()

    # define LIBMY_STATIC if the build type is not set to 'shared'
    if(NOT BUILD_SHARED_LIBS)
        target_compile_definitions(${target} PUBLIC "LIBMY_STATIC")
    endif()
endmacro()


# Add a new target which is a LibMy test
function(libmy_add_test target SOURCES DEPENDS)
    # set a source group for the source files
    source_group("" FILES ${SOURCES})

    # create the target
    add_executable(${target} ${SOURCES})

    # set the target's folder (for IDEs that support it, e.g. Visual Studio)
    set_target_properties(${target} PROPERTIES FOLDER "tests")

    # Enable Warnings
    if (CMAKE_COMPILER_IS_GNUCC)
        target_compile_options(${target} PRIVATE -Wall -Wextra)
    endif()

    # link the target to its LibMy dependencies
    if(DEPENDS)
        target_link_libraries(${target} PRIVATE ${DEPENDS})
    endif()

    # Add Criterion dependency
    target_link_libraries(${target} PRIVATE ${CRITERION_LIBRARIES})

    # Link to gcov if build type is set to 'static'
    if (CMAKE_COMPILER_IS_GNUCC AND LIBMY_USE_GCOV)
        target_link_libraries(${target} PRIVATE gcov)
    endif()
    
    # Add the test
    add_test(${target} ${target})
endfunction()

macro(libmy_enable_module module_name variable)
    if (${module_name} IN_LIST LIBMY_MODULES)
        set(${variable} 1)
    else()
        set(${variable} 0)
    endif()
endmacro()

macro(libmy_add_allowed_function function define)
    if (${function} IN_LIST LIBMY_ALLOWED_FUNCTIONS_LIST)
        set(${define} 1)
    else()
        set(${define} 0)
    endif()
endmacro()
