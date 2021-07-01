set(INCROOT ${PROJECT_SOURCE_DIR}/include/libmy)
set(SRCROOT ${PROJECT_SOURCE_DIR}/src/io)

set(SRC
    ${INCROOT}/io.h
    ${INCROOT}/io/config.h
)

# IDE source group
source_group("" FILES ${SRC})

add_subdirectory(iostream)
add_subdirectory(raw)

libmy_add_module(my-io SOURCES "${SRC};${IOSTREAM_SRC};${RAW_SRC}")

# setup dependencies
if (LIBMY_ALLOW_MALLOC_FREE)
    target_link_libraries(my-io PUBLIC my-ascii my-collections)
else()
    target_link_libraries(my-io PUBLIC my-ascii)
endif()

target_include_directories(my-io PUBLIC "${PROJECT_SOURCE_DIR}/include")
