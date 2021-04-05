/*
** PERSONAL PROJECT, 2019
** doubly linked list objects library
** File description:
** "dllist_swap_data" unit tests.
*/

#include <criterion/criterion.h>
#include <string.h>
#include "dllists_obj.h"
#include "test_utils.h"

Test(swap_data, null_dllist_ptr,
.description="call with a NULL parameter")
{
    cr_assert_eq(dllist_swap_data(NULL, 0, 1), 84);
}

Test(swap_data, empty_list,
.description="call with an empty list")
{
    dllist_t dllist = dllist_create();

    cr_assert_eq(dllist.swap(&dllist, 0, 1), 84);
}

Test(swap_data, out_of_bounds_1,
.description="call with a position out of the list range")
{
    dllist_t dllist = dllist_create();

    cr_assert_eq(dllist.add_head(&dllist, strdup("hi")), 0);
    cr_assert_eq(dllist.add_head(&dllist, strdup("ho")), 0);
    cr_assert_eq(dllist.add_head(&dllist, strdup("ha")), 0);
    cr_assert_eq(dllist.swap(&dllist, 0, 3), 84);
}

Test(swap_data, out_of_bounds_2,
.description="call with a position out of the list range")
{
    dllist_t dllist = dllist_create();

    cr_assert_eq(dllist.add_head(&dllist, strdup("hi")), 0);
    cr_assert_eq(dllist.add_head(&dllist, strdup("ho")), 0);
    cr_assert_eq(dllist.add_head(&dllist, strdup("ha")), 0);
    cr_assert_eq(dllist.swap(&dllist, 3, 1), 84);
}

Test(swap_data, out_of_bounds_3,
.description="call with a position out of the list range")
{
    dllist_t dllist = dllist_create();

    cr_assert_eq(dllist.add_head(&dllist, strdup("hi")), 0);
    cr_assert_eq(dllist.add_head(&dllist, strdup("ho")), 0);
    cr_assert_eq(dllist.add_head(&dllist, strdup("ha")), 0);
    cr_assert_eq(dllist.swap(&dllist, 7, 1), 84);
}

Test(swap_data, swap_head_and_tail,
.description="swapping head and tail")
{
    dllist_t dllist = dllist_create();

    cr_assert_eq(dllist.add_head(&dllist, strdup("hi")), 0);
    cr_assert_eq(dllist.add_head(&dllist, strdup("ho")), 0);
    cr_assert_eq(dllist.add_head(&dllist, strdup("ha")), 0);
    cr_assert_eq(dllist.swap(&dllist, 0, 2), 0);
    cr_assert_str_eq(dllist.at(&dllist, 0), "hi");
    cr_assert_str_eq(dllist.at(&dllist, 1), "ho");
    cr_assert_str_eq(dllist.at(&dllist, 2), "ha");
}

Test(swap_data, swap_tail_and_head,
.description="swapping tail and head")
{
    dllist_t dllist = dllist_create();

    cr_assert_eq(dllist.add_head(&dllist, strdup("hi")), 0);
    cr_assert_eq(dllist.add_head(&dllist, strdup("ho")), 0);
    cr_assert_eq(dllist.add_head(&dllist, strdup("ha")), 0);
    cr_assert_eq(dllist.swap(&dllist, 2, 0), 0);
    cr_assert_str_eq(dllist.at(&dllist, 0), "hi");
    cr_assert_str_eq(dllist.at(&dllist, 1), "ho");
    cr_assert_str_eq(dllist.at(&dllist, 2), "ha");
}

Test(swap_data, same_positions,
.description="passing the same position as both index parameters")
{
    dllist_t dllist = dllist_create();

    cr_assert_eq(dllist.add_head(&dllist, strdup("hi")), 0);
    cr_assert_eq(dllist.add_head(&dllist, strdup("ho")), 0);
    cr_assert_eq(dllist.add_head(&dllist, strdup("ha")), 0);
    cr_assert_eq(dllist.swap(&dllist, 2, 2), 0);
    cr_assert_str_eq(dllist.at(&dllist, 0), "ha");
    cr_assert_str_eq(dllist.at(&dllist, 1), "ho");
    cr_assert_str_eq(dllist.at(&dllist, 2), "hi");
}

Test(swap_data, ten_node_list_1,
.description="swapping two elements in the middle of a ten node list")
{
    dllist_t dllist = dllist_create();
    char *data [] =     {"un", "deux", "trois", "quatre", "cinq", "six", "sept", "huit", "neuf", "dix"};
    char *target [] =   {"un", "deux", "trois", "six", "cinq", "quatre", "sept", "huit", "neuf", "dix"};

    for (register int i = 0; i < 10; ++i)
        cr_assert_eq(dllist.add_tail(&dllist, data[i]), 0);
    cr_assert_eq(dllist.swap(&dllist, 5, 3), 0);
    cr_assert_eq(cmp_list_to_ptr_array(&dllist, target), 0);
}

Test(swap_data, ten_node_list_2,
.description="swapping the two first elements of a ten node list")
{
    dllist_t dllist = dllist_create();
    char *data [] =     {"un", "deux", "trois", "quatre", "cinq", "six", "sept", "huit", "neuf", "dix"};
    char *target [] =   {"deux", "un", "trois", "quatre", "cinq", "six", "sept", "huit", "neuf", "dix"};

    for (register int i = 0; i < 10; ++i)
        cr_assert_eq(dllist.add_tail(&dllist, data[i]), 0);
    cr_assert_eq(dllist.swap(&dllist, 0, 1), 0);
    cr_assert_eq(cmp_list_to_ptr_array(&dllist, target), 0);
}

Test(swap_data, ten_node_list_3,
.description="swapping the two last elements of a ten node list")
{
    dllist_t dllist = dllist_create();
    char *data [] =     {"un", "deux", "trois", "quatre", "cinq", "six", "sept", "huit", "neuf", "dix"};
    char *target [] =   {"un", "deux", "trois", "quatre", "cinq", "six", "sept", "huit", "dix", "neuf"};

    for (register int i = 0; i < 10; ++i)
        cr_assert_eq(dllist.add_tail(&dllist, data[i]), 0);
    cr_assert_eq(dllist.swap(&dllist, 9, 8), 0);
    cr_assert_eq(cmp_list_to_ptr_array(&dllist, target), 0);
}