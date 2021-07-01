set(INCROOT ${PROJECT_SOURCE_DIR}/include)
set(SRCROOT ${PROJECT_SOURCE_DIR}/src)

set(SRC
    ${INCROOT}/builtin.h
    ${INCROOT}/context.h
    ${INCROOT}/definition.h
    ${INCROOT}/error.h
    ${INCROOT}/shell.h
    ${SRCROOT}/context.c
    ${SRCROOT}/cwd.c
    ${SRCROOT}/env.c
    ${SRCROOT}/error.c
    ${SRCROOT}/execute_2.c
    ${SRCROOT}/execute.c
    ${SRCROOT}/lint.c
    ${SRCROOT}/open_script.c
    ${SRCROOT}/parse_args.c
    ${SRCROOT}/print.c
    ${SRCROOT}/reset_path.c
    ${SRCROOT}/start.c
    ${SRCROOT}/status.c
    ${SRCROOT}/vars.c
    ${SRCROOT}/prompt.c
    ${SRCROOT}/print_prompt.c
    ${SRCROOT}/print_util.c
    ${SRCROOT}/prompt_util.c
)

add_subdirectory(builtin)
add_subdirectory(command)
add_subdirectory(line_edit)
add_subdirectory(token)
add_subdirectory(util)
add_subdirectory(variables)

source_group("" FILES ${SRC})

add_library(42sh-lib STATIC ${SRC})
add_executable(42sh ${SRCROOT}/main.c)

if (CMAKE_COMPILER_IS_GNUCC)
    # Compile Options
    target_compile_options(42sh-lib PRIVATE
       "-Wall" "-Wextra" "-Wshadow"
       "$<$<CONFIG:RELEASE>:-O3;-fno-builtin>"
       "$<$<CONFIG:DEBUG>:-O0;-g3;-ggdb>"
    )
    target_compile_options(42sh PRIVATE
       "-Wall" "-Wextra" "-Wshadow"
       "$<$<CONFIG:RELEASE>:-O3;-fno-builtin>"
       "$<$<CONFIG:DEBUG>:-O0;-g3;-ggdb>"
    )

    # Enable test coverage
    if (USE_GCOV)
        target_link_options(42sh-lib PRIVATE "-lgcov" "--coverage")
        target_compile_options(42sh-lib PRIVATE "--coverage" "-fprofile-arcs" "-ftest-coverage")
    endif()
endif()

target_link_libraries(42sh-lib PUBLIC my-ascii my-collections my-hash my-io my-memory my-parsing my-printf)

# Link to gcov if coverage is enabled
if (CMAKE_COMPILER_IS_GNUCC AND USE_GCOV)
    target_link_libraries(42sh-lib PUBLIC gcov)
endif()

target_link_libraries(42sh PRIVATE 42sh-lib)

target_include_directories(42sh-lib PUBLIC ${INCROOT} ${LIBMY_INCLUDE_DIR})

add_custom_command(TARGET 42sh
	POST_BUILD
	COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:42sh> ${PROJECT_SOURCE_DIR})

