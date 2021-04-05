/*
** PERSONAL PROJECT, 2019
** doubly linked list objects library
** File description:
** "dllist_array_to_list" unit tests.
*/

#include <criterion/criterion.h>
#include <string.h>
#include "dllists_obj.h"
#include "test_utils.h"

Test(array_to_dllist, null_array_ptr,
.description="call with a NULL array")
{
    cr_assert_null(array_to_dllist(NULL, 10));
}

Test(array_to_dllist, single_element_array,
.description="call with a single element array")
{
    dllist_t *dllist;
    char *data[] = {"one"};

    dllist = array_to_dllist((void **)data, 1);
    cr_assert_eq(cmp_list_to_ptr_array(dllist, data), 0);
}

Test(array_to_dllist, ten_node_dllist,
.description="ten node dllist")
{
    dllist_t *dllist;
    char *data[] = {"un", "deux", "trois", "quatre", "cinq",
                    "six", "sept", "huit", "neuf", "dix"};


    dllist = array_to_dllist((void **)data, 10);
    cr_assert_not_null(dllist);
    cr_assert_eq(cmp_list_to_ptr_array(dllist, data), 0);
}