# LibMy configuration

# detect the compiler and its version
# Note: on some platforms (OS X), CMAKE_COMPILER_IS_GNUC is true
# even when CLANG is used, therefore the Clang test is done first
if(CMAKE_C_COMPILER MATCHES "clang[+][+]" OR CMAKE_C_COMPILER_ID MATCHES "Clang")
   # CMAKE_C_COMPILER_ID is an internal CMake variable subject to change,
   # but there is no other way to detect CLang at the moment
   set(LIBMY_COMPILER_CLANG 1)
   execute_process(COMMAND "${CMAKE_C_COMPILER}" "--version" OUTPUT_VARIABLE CLANG_VERSION_OUTPUT)
   string(REGEX REPLACE ".*clang version ([0-9]+\\.[0-9]+).*" "\\1" LIBMY_CLANG_VERSION "${CLANG_VERSION_OUTPUT}")
elseif(CMAKE_COMPILER_IS_GNUCC)
    set(LIBMY_COMPILER_GCC 1)
    execute_process(COMMAND "${CMAKE_C_COMPILER}" "-dumpversion" OUTPUT_VARIABLE GCC_VERSION_OUTPUT)
    string(REGEX REPLACE "([0-9]+\\.[0-9]+).*" "\\1" LIBMY_GCC_VERSION "${GCC_VERSION_OUTPUT}")
    execute_process(COMMAND "${CMAKE_C_COMPILER}" "--version" OUTPUT_VARIABLE GCC_COMPILER_VERSION)
    string(REGEX MATCHALL ".*(tdm[64]*-[1-9]).*" LIBMY_COMPILER_GCC_TDM "${GCC_COMPILER_VERSION}")
    execute_process(COMMAND "${CMAKE_C_COMPILER}" "-dumpmachine" OUTPUT_VARIABLE GCC_MACHINE)
    string(STRIP "${GCC_MACHINE}" GCC_MACHINE)
    if(GCC_MACHINE MATCHES ".*w64.*")
        set(LIBMY_COMPILER_GCC_W64 1)
    endif()
else()
    message(FATAL_ERROR "Unsupported compiler")
    return()
endif()
