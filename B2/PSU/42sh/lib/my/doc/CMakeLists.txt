find_package(Doxygen QUIET)

# set the input and output documentation paths
set(DOXYGEN_INPUT_DIR ${PROJECT_SOURCE_DIR})
set(DOXYGEN_OUTPUT_DIR ${PROJECT_SOURCE_DIR}/doc)

# configure the source Doxyfile by copying it and replacing all @variables@
set(DOXYGEN_CONFIGURED_INPUT ${DOXYGEN_OUTPUT_DIR}/Doxyfile)
configure_file(${DOXYGEN_INPUT_DIR}/doc/Doxyfile.in ${DOXYGEN_CONFIGURED_INPUT} @ONLY)

# target setup
if (DOXYGEN_FOUND)
    add_custom_target(libmy-doc ALL
        COMMAND ${CMAKE_COMMAND} -E echo_append "Building API Documentation..."
        COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_CONFIGURED_INPUT}
        COMMAND ${CMAKE_COMMAND} -E echo "Done."
        WORKING_DIRECTORY ${DOXYGEN_INPUT_DIR}
    )
else()
    add_custom_target(libmy-doc ALL
        COMMAND ${CMAKE_COMMAND} -E echo_append "Building API Documentation..."
        COMMAND ${CMAKE_COMMAND} -E echo " ERROR: doxygen was not found"
        COMMAND ${CMAKE_COMMAND} -E false
        WORKING_DIRECTORY ${DOXYGEN_INPUT_DIR}
    )
endif()

# Prevent this target from being built by default
set_target_properties(libmy-doc PROPERTIES EXCLUDE_FROM_ALL TRUE)
