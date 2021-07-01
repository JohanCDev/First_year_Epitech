set(SRCROOT ${PROJECT_SOURCE_DIR}/tests/integration)

add_test(
    NAME integration-test-42sh
    COMMAND tester.sh --color=always
    WORKING_DIRECTORY ${SRCROOT}
)
