/*
** PERSONAL PROJECT, 2019
** doubly linked list objects library
** File description:
** "dllist_remove_head" unit tests.
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <string.h>
#include <stdlib.h>
#include "dllists_obj.h"
#include "test_utils.h"

Test(dllist_remove_head, null_dllist_ptr,
.description="call with a NULL parameter")
{
    cr_assert_eq(dllist_remove_head(NULL), 84);
}

Test(dllist_remove_head, invalid_len,
.description="dllist has a length member of 0")
{
    dllist_t dllist = dllist_create();

    cr_assert_eq(dllist.remove_head(&dllist), 84);
}

Test(dllist_remove_head, null_tail,
.description="call using a dllist with a NULL pointer as tail, despite len of 1.")
{
    dllist_t dllist = dllist_create();

    dllist.len = 1;
    cr_assert_eq(dllist.remove_head(&dllist), 84);
}

Test(dllist_remove_head, single_node_dllist_tail_removal, .init=cr_redirect_stdout,
.description="single call on a single node dllist")
{
    dllist_t dllist = dllist_create();

    cr_assert_eq(dllist.add_head(&dllist, strdup("hi")), 0);
    cr_assert_eq(dllist.remove_head(&dllist), 0);
    cr_assert_eq(dllist.remove_head(&dllist), 84);
    cr_assert_eq(dllist.len, 0);
    cr_assert_null(dllist.tail);
    cr_assert_null(dllist.head);
}

Test(dllist_remove_head, three_node_dllist_tail_removal, .init=cr_redirect_stdout,
.description="single call on a three node dllist")
{
    dllist_t dllist = dllist_create();

    cr_assert_eq(dllist.add_head(&dllist, strdup("hi")), 0);
    cr_assert_eq(dllist.add_head(&dllist, strdup("ho")), 0);
    cr_assert_eq(dllist.add_head(&dllist, strdup("he")), 0);
    cr_assert_eq(dllist.remove_head(&dllist), 0);
    print(&dllist);
    cr_assert_eq(dllist.len, 2);
    cr_assert_stdout_eq_str("ho\nhi\n");
}

Test(dllist_remove_head, full_list_destruction,
.description="deleting a dllist of 10 nodes")
{
    dllist_t dllist = dllist_create();
    char *array[] = {"toto",
                      "tata",
                      "titi",
                      "tutu",
                      "foobar",
                      "bar",
                      "hey",
                      "ho",
                      "lavabo",
                      "chicore"};
    int j = 0;
    int res;

    for (register int i = 0 ; i < 10 ; ++i) {
        cr_assert_eq(dllist.len, i);
        cr_assert_eq(dllist.add_tail(&dllist, strdup(array[i])), 0);
        cr_assert_eq(dllist.len, i + 1);
    }
    cr_assert_eq(0, cmp_list_to_ptr_array(&dllist, array));
    while (dllist.len > 0) {
        res = dllist.remove_head(&dllist);
        cr_assert_eq(res, 0);
        j++;
    }
    cr_assert_null(dllist.head);
    cr_assert_null(dllist.tail);
    cr_assert_eq(dllist.len, 0);
}