set(INCROOT ${PROJECT_SOURCE_DIR}/include/libmy/collections)
set(SRCROOT ${PROJECT_SOURCE_DIR}/src/collections/vec)

set(VECTOR_SRC
    ${INCROOT}/vec.h
    ${SRCROOT}/my_vec_change_value.c
    ${SRCROOT}/my_vec_clear.c
    ${SRCROOT}/my_vec_copy.c
    ${SRCROOT}/my_vec_ensure_capacity.c
    ${SRCROOT}/my_vec_extend_to_length.c
    ${SRCROOT}/my_vec_free.c
    ${SRCROOT}/my_vec_init_capacity.c
    ${SRCROOT}/my_vec_insert.c
    ${SRCROOT}/my_vec_pop.c
    ${SRCROOT}/my_vec_push.c
    ${SRCROOT}/my_vec_remove.c
    ${SRCROOT}/my_vec_reserve.c
    ${SRCROOT}/my_vec_set_capacity.c
    ${SRCROOT}/my_vec_shrink_to_fit.c
)
set(VECTOR_SRC ${VECTOR_SRC} PARENT_SCOPE)

source_group("vector" FILES ${VECTOR_SRC})
