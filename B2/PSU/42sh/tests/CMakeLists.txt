set(SRCROOT "${PROJECT_SOURCE_DIR}/tests")

set(SRC
    ${SRCROOT}/test_args.c
    ${SRCROOT}/test_context.c
    ${SRCROOT}/test_create_file_path.c
    ${SRCROOT}/test_env.c
    ${SRCROOT}/test_error.c
    ${SRCROOT}/test_reset_path.c
    ${SRCROOT}/test_util.c
    ${SRCROOT}/test_vars.c
)

add_executable(unit-test-42sh ${SRC})

source_group("" FILES ${SRC})
set_target_properties(unit-test-42sh PROPERTIES FOLDER "tests")

if (CMAKE_COMPILER_IS_GNUCC)
    target_compile_options(unit-test-42sh PRIVATE -Wall -Wextra)
endif()

target_link_libraries(unit-test-42sh PRIVATE 42sh-lib ${CRITERION_LIBRARIES})

add_test(NAME unit-test-42sh COMMAND unit-test-42sh)

add_subdirectory(integration)
