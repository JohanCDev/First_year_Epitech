TARGET := 42sh
BUILD_DIR := build

CONFIG_FLAGS := -G"Unix Makefiles" -B$(BUILD_DIR)

CONFIG_FLAGS_RELEASE := -DCMAKE_BUILD_TYPE=Release -DBUILD_TEST_SUITE=TRUE $(CONFIG_FLAGS)
CONFIG_FLAGS_DEBUG := -DCMAKE_BUILD_TYPE=Debug -DBUILD_TEST_SUITE=TRUE -DUSE_GCOV=TRUE $(CONFIG_FLAGS)

BUILD_FLAGS_RELEASE := --config Release -j
BUILD_FLAGS_DEBUG := --config Debug -j

# Build Targets
all: $(TARGET)
$(TARGET):
	cmake $(CONFIG_FLAGS_RELEASE)
	cmake --build $(BUILD_DIR) $(BUILD_FLAGS_RELEASE)

# Remove Target's Build Files
clean:
	rm -rf $(BUILD_DIR)/CMakeFiles
	rm -rf $(BUILD_DIR)/src/CMakeFiles

# Remove Target
fclean:
	rm -rf $(BUILD_DIR)
	rm -f $(TARGET)

# Recompile all
re: fclean all

# Debug Target
debug:
	cmake $(CONFIG_FLAGS_DEBUG)
	cmake --build $(BUILD_DIR) $(BUILD_FLAGS_DEBUG)

# Run Target
run_tests: fclean debug
	(cd $(BUILD_DIR) && ctest --verbose) || true
run_test: run_tests
tests_run: run_tests
test_run: run_test

# Display Code Coverage
coverage:
	gcovr .
	gcovr --branch .

.PHONY: \
	all $(TARGET) \
	clean fclean re \
	debug \
	run_tests run_test tests_run test_run coverage
