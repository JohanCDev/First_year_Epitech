set(INCROOT ${PROJECT_SOURCE_DIR}/include/libmy)
set(SRCROOT ${PROJECT_SOURCE_DIR}/src/parsing)

set(SRC
    ${INCROOT}/parsing.h
    ${INCROOT}/parsing/config.h
    ${INCROOT}/parsing/parsing.h
    ${SRCROOT}/my_getnbr_base.c
    ${SRCROOT}/my_getnbr.c
    ${SRCROOT}/my_next_size_t.c
    ${SRCROOT}/my_next_uint.c
)

# IDE source group
source_group("" FILES ${SRC})

libmy_add_module(my-parsing SOURCES ${SRC})

# setup dependencies
target_link_libraries(my-parsing PUBLIC my-ascii)

target_include_directories(my-parsing PUBLIC "${PROJECT_SOURCE_DIR}/include")
