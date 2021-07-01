BUILD_DIR := build

CONFIG_FLAGS := -G"Unix Makefiles" -B$(BUILD_DIR) -DLIBMY_BUILD_DOC=TRUE

CONFIG_FLAGS_RELEASE := -DCMAKE_BUILD_TYPE=Release -DLIBMY_BUILD_TEST_SUITE=TRUE $(CONFIG_FLAGS)
CONFIG_FLAGS_DEBUG := -DCMAKE_BUILD_TYPE=Debug -DLIBMY_BUILD_TEST_SUITE=TRUE -DLIBMY_USE_GCOV=TRUE $(CONFIG_FLAGS)

BUILD_FLAGS_RELEASE := --config Release -j
BUILD_FLAGS_DEBUG := --config Debug -j

all:
	cmake $(CONFIG_FLAGS_RELEASE)
	cmake --build $(BUILD_DIR) $(BUILD_FLAGS_RELEASE)

clean:
	rm -rf $(BUILD_DIR)/CMakeFiles
	rm -rf $(BUILD_DIR)/src
fclean: clean
	rm -rf $(BUILD_DIR)
	rm -rf doc/html doc/Doxyfile
	rm -rf include/libmy/config.h

debug:
	cmake $(CONFIG_FLAGS_DEBUG)
	cmake --build $(BUILD_DIR) $(BUILD_FLAGS_DEBUG)

re: fclean all

docs: all
	(cd $(BUILD_DIR) && cmake --build . --target libmy-doc)
open_docs:
	xdg-open doc/html/index.html > /dev/null
docs_open: open_docs

run_tests: fclean debug
	(cd build && ctest --verbose) || true
run_test: run_tests
tests_run: run_tests
test_run: run_test

coverage:
	gcovr .
	gcovr --branch .

.PHONY: all clean fclean debug re docs open_docs docs_open run_tests run_test tests_run test_run coverage
