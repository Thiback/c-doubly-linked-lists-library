/*
** PERSONAL PROJECT, 2019
** doubly linked list objects library
** File description:
** "dllist_array_to_list" unit tests.
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <unistd.h>
#include <string.h>
#include "dllists_obj.h"
#include "test_utils.h"

void *change_first_char(void *param)
{
    static char modif = 'a';
    char *target = (char *)param;

    target[0] = modif++;
    return (NULL);
}

Test(iterate_with_callback, null_array_ptr,
.description="call with a NULL list pointer")
{
    cr_assert_eq(dllist_iterate_with_callback(NULL, change_first_char), 84);
}

Test(iterate_with_callback, null_callback_ptr,
.description="call with a NULL callback pointer")
{
    dllist_t dllist = dllist_create();

    cr_assert_eq(dllist.callback(&dllist, NULL), 84);
}

Test(iterate_with_callback, empty_node_list,
.init=cr_redirect_stdout,
.description="call with an empty list")
{
    dllist_t dllist = dllist_create();

    cr_assert_eq(dllist.callback(&dllist, change_first_char), 0);
}

Test(iterate_with_callback, single_node_list,
.init=cr_redirect_stdout,
.description="call with an empty list")
{
    dllist_t dllist = dllist_create();

    cr_assert_eq(dllist.add_head(&dllist, strdup("toot")), 0);
    cr_assert_eq(dllist.callback(&dllist, change_first_char), 0);
}

Test(iterate_with_callback, two_node_list,
.init=cr_redirect_stdout,
.description="call with an empty list")
{
    dllist_t dllist = dllist_create();
    char *data2[] = {"aoot", "buut"};

    cr_assert_eq(dllist.add_tail(&dllist, strdup("toot")), 0);
    cr_assert_eq(dllist.add_tail(&dllist, strdup("tuut")), 0);
    cr_assert_eq(dllist.callback(&dllist, change_first_char), 0);
    cr_assert_eq(cmp_list_to_ptr_array(&dllist, data2), 0);
}

Test(iterate_with_callback, ten_node_list,
.init=cr_redirect_stdout,
.description="call with an empty list")
{
    dllist_t dllist = dllist_create();
    char *data[] = {"one", "two", "three", "four", "five",
                    "six", "seven", "eight", "nine", "ten"};
    char *data2[] = {"ane", "bwo", "chree", "dour", "eive",
                    "fix", "geven", "hight", "iine", "jen"};

    for (register int i = 0; i < 10; ++i)
        cr_assert_eq(dllist.add_tail(&dllist, strdup(data[i])), 0);
    cr_assert_eq(dllist.callback(&dllist, change_first_char), 0);
    cr_assert_eq(cmp_list_to_ptr_array(&dllist, data2), 0);
}