/*
** PERSONAL PROJECT, 2019
** doubly linked list objects library
** File description:
** "dllist_listlen" unit tests.
*/

#include "criterion/criterion.h"
#include "dllists_obj.h"

Test(listlen, call_on_NULL,
.description="single call on a NULL pointer")
{
    dllist_t *null_list = NULL;

    cr_assert_eq(dllist_listlen(null_list), 0);
}

Test(listlen, call_on_new_list,
.description="single call on a newly created dllist object.")
{
    dllist_t mylist = dllist_create();

    cr_assert_eq(mylist.listlen(&mylist), 0);
}

Test(listlen, 3_nodes_list_add_head,
.description="single call on a 3 node dllist object.")
{
    dllist_t mylist = dllist_create();

    cr_assert_eq(mylist.add_head(&mylist, "tata"), 0);
    cr_assert_eq(mylist.add_head(&mylist, "toto"), 0);
    cr_assert_eq(mylist.add_head(&mylist, "titi"), 0);
    cr_assert_eq(mylist.listlen(&mylist), 3);
}

Test(listlen, 3_nodes_list_add_tail,
.description="single call on a 3 node dllist object.")
{
    dllist_t mylist = dllist_create();

    cr_assert_eq(mylist.add_tail(&mylist, "tata"), 0);
    cr_assert_eq(mylist.add_tail(&mylist, "toto"), 0);
    cr_assert_eq(mylist.add_tail(&mylist, "titi"), 0);
    cr_assert_eq(mylist.listlen(&mylist), 3);
}