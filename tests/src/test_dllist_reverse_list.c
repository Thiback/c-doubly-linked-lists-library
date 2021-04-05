/*
** PERSONAL PROJECT, 2019
** doubly linked list objects library
** File description:
** "dllist_reverse_list" unit tests.
*/

#include <criterion/criterion.h>
#include <string.h>
#include "dllists_obj.h"
#include "test_utils.h"

Test(reverse_list, null_dllist_ptr,
.description="call with a NULL parameter")
{
    cr_assert_eq(dllist_reverse_list(NULL), 84);
}

Test(reverse_list, empty_dllist,
.description="call with an empty dllist")
{
    dllist_t dllist = dllist_create();

    cr_assert_eq(dllist_reverse_list(&dllist), 84);
}

Test(reverse_list, single_node_dllist,
.description="call with a single node dllist")
{
    dllist_t dllist = dllist_create();
    char *data[] = {"one"};

    cr_assert_eq(dllist.add_tail(&dllist, strdup(data[0])), 0);
    cr_assert_eq(dllist.reverse(&dllist), 0);
    cr_assert_eq(dllist.head, dllist.tail);
    cr_assert_str_eq(dllist.head->data, dllist.tail->data);
}

Test(reverse_list, two_node_list,
.description="call with a two node list")
{
    dllist_t dllist = dllist_create();
    char *data[] = {"one", "two"};
    char *data2[] = {"two", "one"};

    for (register int i = 0; i < 2; ++i)
        cr_assert_eq(dllist.add_tail(&dllist, data[i]), 0);
    cr_assert_eq(dllist.reverse(&dllist), 0);
    cr_assert_eq(check_list_to_array_integrity(&dllist, data2), 0);
}

Test(reverse_list, ten_node_list,
.description="call with a ten node list")
{
    dllist_t dllist = dllist_create();
    char *data[] = {"one", "two", "three", "four", "five",
                     "six", "seven", "eight", "nine", "ten"};
    char *data2[] = {"ten", "nine", "eight", "seven", "six",
                    "five", "four", "three", "two", "one"};

    for (register int i = 0; i < 10; ++i)
        cr_assert_eq(dllist.add_tail(&dllist, data[i]), 0);
    cr_assert_eq(dllist.reverse(&dllist), 0);
    cr_assert_eq(check_list_to_array_integrity(&dllist, data2), 0);
}

Test(reverse_list, seven_node_list,
.description="call with a ten node list")
{
    dllist_t dllist = dllist_create();
    char *data[] = {"one", "two", "three", "four", "five",
                     "six", "seven"};
    char *data2[] = {"seven", "six",
                    "five", "four", "three", "two", "one"};

    for (register int i = 0; i < 7; ++i)
        cr_assert_eq(dllist.add_tail(&dllist, data[i]), 0);
    cr_assert_eq(dllist.reverse(&dllist), 0);
    cr_assert_eq(check_list_to_array_integrity(&dllist, data2), 0);
}