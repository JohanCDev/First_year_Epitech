set(SRCROOT "${PROJECT_SOURCE_DIR}/tests/collections/vec")

set(VECTOR_SRC
    ${SRCROOT}/test_my_vec_change_value.c
    ${SRCROOT}/test_my_vec_clear.c
    ${SRCROOT}/test_my_vec_copy.c
    ${SRCROOT}/test_my_vec_ensure_capacity.c
    ${SRCROOT}/test_my_vec_extend_to_length.c
    ${SRCROOT}/test_my_vec_free.c
    ${SRCROOT}/test_my_vec_init_capacity.c
    ${SRCROOT}/test_my_vec_insert.c
    ${SRCROOT}/test_my_vec_pop.c
    ${SRCROOT}/test_my_vec_push.c
    ${SRCROOT}/test_my_vec_remove.c
    ${SRCROOT}/test_my_vec_reserve.c
    ${SRCROOT}/test_my_vec_set_capacity.c
    ${SRCROOT}/test_my_vec_shrink_to_fit.c
    PARENT_SCOPE
)
