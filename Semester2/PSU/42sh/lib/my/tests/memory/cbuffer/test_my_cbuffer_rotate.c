/*
** EPITECH PROJECT, 2020
** LibMy - memory module
** File description:
** Tests the my_cbuffer_rotate_* functions
*/

#include <criterion/criterion.h>
#include "libmy/memory.h"

Test(my_cbuffer_rotate_left, empty_buf)
{
    my_cbuffer_t buf = {"ABCDEFGHIJ", 10, 0, 4, 4};

    my_cbuffer_rotate_left(&buf, 69);
    cr_assert_str_eq(buf.data, "ABCDEFGHIJ");
    cr_assert_eq(buf.cap, 10);
    cr_assert_eq(buf.len, 0);
    cr_assert_eq(buf.tail, 4);
    cr_assert_eq(buf.head, 4);
}

Test(my_cbuffer_rotate_left, no_rotation)
{
    my_cbuffer_t buf = {"atedRot", 7, 7, 4, 4};
    char dst[8] = {0};

    my_cbuffer_rotate_left(&buf, 0);
    cr_assert_str_eq(buf.data, "atedRot");
    cr_assert_eq(buf.cap, 7);
    cr_assert_eq(buf.len, 7);
    cr_assert_eq(buf.tail, 4);
    cr_assert_eq(buf.head, 4);
    cr_assert_str_eq(my_cbuffer_read_front(&buf, dst, 7), "Rotated");
}

Test(my_cbuffer_rotate_left, rotation_no_hole)
{
    my_cbuffer_t buf = {"atedRot", 7, 7, 4, 4};
    char dst[8] = {0};

    my_cbuffer_rotate_left(&buf, 3);
    cr_assert_str_eq(buf.data, "atedRot");
    cr_assert_eq(buf.cap, 7);
    cr_assert_eq(buf.len, 7);
    cr_assert_eq(buf.tail, 0);
    cr_assert_eq(buf.head, 0);
    cr_assert_str_eq(my_cbuffer_read_front(&buf, dst, 7), "atedRot");
}

Test(my_cbuffer_rotate_left, rotation_with_mid_hole)
{
    char data[] = "RotABCated";
    my_cbuffer_t buf = {data, 10, 7, 6, 3};
    char dst[11] = {0};

    my_cbuffer_rotate_left(&buf, 4);
    cr_assert_str_eq(buf.data, "Rotatedted");
    cr_assert_eq(buf.cap, 10);
    cr_assert_eq(buf.len, 7);
    cr_assert_eq(buf.tail, 0);
    cr_assert_eq(buf.head, 7);
    cr_assert_str_eq(my_cbuffer_read_front(&buf, dst, 7), "Rotated");
}

Test(my_cbuffer_rotate_left, rotation_with_edge_holes)
{
    char data[] = "CRotatedAB";
    my_cbuffer_t buf = {data, 10, 7, 1, 8};
    char dst[11] = {0};

    my_cbuffer_rotate_left(&buf, 4);
    cr_assert_str_eq(buf.data, "taotatedRo");
    cr_assert_eq(buf.cap, 10);
    cr_assert_eq(buf.len, 7);
    cr_assert_eq(buf.tail, 5);
    cr_assert_eq(buf.head, 2);
    cr_assert_str_eq(my_cbuffer_read_front(&buf, dst, 7), "tedRota");
}

Test(my_cbuffer_rotate_right, empty_buf)
{
    my_cbuffer_t buf = {"ABCDEFGHIJ", 10, 0, 4, 4};

    my_cbuffer_rotate_right(&buf, 42);
    cr_assert_str_eq(buf.data, "ABCDEFGHIJ");
    cr_assert_eq(buf.cap, 10);
    cr_assert_eq(buf.len, 0);
    cr_assert_eq(buf.tail, 4);
    cr_assert_eq(buf.head, 4);
}

Test(my_cbuffer_rotate_right, no_rotation)
{
    my_cbuffer_t buf = {"atedRot", 7, 7, 4, 4};
    char dst[8] = {0};

    my_cbuffer_rotate_right(&buf, 0);
    cr_assert_str_eq(buf.data, "atedRot");
    cr_assert_eq(buf.cap, 7);
    cr_assert_eq(buf.len, 7);
    cr_assert_eq(buf.tail, 4);
    cr_assert_eq(buf.head, 4);
    cr_assert_str_eq(my_cbuffer_read_front(&buf, dst, 7), "Rotated");
}

Test(my_cbuffer_rotate_right, rotation_no_hole)
{
    my_cbuffer_t buf = {"atedRot", 7, 7, 4, 4};
    char dst[8] = {0};

    my_cbuffer_rotate_right(&buf, 4);
    cr_assert_str_eq(buf.data, "atedRot");
    cr_assert_eq(buf.cap, 7);
    cr_assert_eq(buf.len, 7);
    cr_assert_eq(buf.tail, 0);
    cr_assert_eq(buf.head, 0);
    cr_assert_str_eq(my_cbuffer_read_front(&buf, dst, 7), "atedRot");
}

Test(my_cbuffer_rotate_right, rotation_with_mid_hole)
{
    char data[] = "RotABCated";
    my_cbuffer_t buf = {data, 10, 7, 6, 3};
    char dst[11] = {0};

    my_cbuffer_rotate_right(&buf, 4);
    cr_assert_str_eq(buf.data, "RodRotated");
    cr_assert_eq(buf.cap, 10);
    cr_assert_eq(buf.len, 7);
    cr_assert_eq(buf.tail, 2);
    cr_assert_eq(buf.head, 9);
    cr_assert_str_eq(my_cbuffer_read_front(&buf, dst, 7), "dRotate");
}

Test(my_cbuffer_rotate_right, rotation_with_edge_holes)
{
    char data[] = "CRotatedAB";
    my_cbuffer_t buf = {data, 10, 7, 1, 8};
    char dst[11] = {0};

    my_cbuffer_rotate_right(&buf, 4);
    cr_assert_str_eq(buf.data, "dRotateate");
    cr_assert_eq(buf.cap, 10);
    cr_assert_eq(buf.len, 7);
    cr_assert_eq(buf.tail, 7);
    cr_assert_eq(buf.head, 4);
    cr_assert_str_eq(my_cbuffer_read_front(&buf, dst, 7), "atedRot");
}
