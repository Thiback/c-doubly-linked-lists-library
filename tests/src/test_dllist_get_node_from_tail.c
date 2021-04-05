/*
** PERSONAL PROJECT, 2019
** doubly linked list objects library
** File description:
** "dllist get node from tail" unit tests
*/

#include "criterion/criterion.h"
#include "dllists_obj.h"

Test(get_node_from_tail, null_dllist,
.description="single call with a null pointer as parameter")
{
    cr_assert_eq(dllist_get_node_from_tail(NULL, 0), NULL);
}

Test(get_node_from_tail, null_head,
.description="single call with null head ptr")
{
    dllist_t dllist = dllist_create();

    dllist.len = 2;
    cr_assert_eq(dllist_get_node_from_tail(&dllist, 2), NULL);
}

Test(get_node_from_tail, length_zero,
.description="single call on a list with a length of 0")
{
    dllist_t dllist = dllist_create();

    cr_assert_eq(dllist.add_head(&dllist, strdup("toto")), 0);
    dllist.len = 0;
    cr_assert_eq(dllist_get_node_from_tail(&dllist, 2), NULL);
}

Test(get_node_from_tail, head_node_target,
.description="single call targeting the head node")
{
    dllist_t dllist = dllist_create();
    node_t *node;

    cr_assert_eq(dllist.add_head(&dllist, strdup("toto")), 0);
    cr_assert_eq(dllist.add_head(&dllist, strdup("tata")), 0);
    cr_assert_eq(dllist.add_head(&dllist, strdup("titi")), 0);
    node = dllist_get_node_from_tail(&dllist, 0);
    cr_assert_not_null(node);
    cr_assert_str_eq(node->data, "titi");
}

Test(get_node_from_tail, second_node_target,
.description="single call targeting the second node")
{
    dllist_t dllist = dllist_create();
    node_t *node;

    cr_assert_eq(dllist.add_head(&dllist, strdup("toto")), 0);
    cr_assert_eq(dllist.add_head(&dllist, strdup("tata")), 0);
    cr_assert_eq(dllist.add_head(&dllist, strdup("titi")), 0);
    node = dllist_get_node_from_tail(&dllist, 1);
    cr_assert_not_null(node);
    cr_assert_str_eq(node->data, "tata");
}

Test(get_node_from_tail, middle_node_target,
.description="single call targeting the middle node")
{
    dllist_t dllist = dllist_create();
    node_t *node;

    cr_assert_eq(dllist.add_head(&dllist, strdup("toto")), 0);
    cr_assert_eq(dllist.add_head(&dllist, strdup("tata")), 0);
    cr_assert_eq(dllist.add_head(&dllist, strdup("titi")), 0);
    cr_assert_eq(dllist.add_head(&dllist, strdup("tutu")), 0);
    cr_assert_eq(dllist.add_head(&dllist, strdup("tete")), 0);
    node = dllist_get_node_from_tail(&dllist, 2);
    cr_assert_not_null(node);
    cr_assert_str_eq(node->data, "titi");
}

Test(get_node_from_tail, second_to_last_node_target,
.description="single call targeting a second to last node")
{
    dllist_t dllist = dllist_create();
    node_t *node;

    cr_assert_eq(dllist.add_head(&dllist, strdup("toto")), 0);
    cr_assert_eq(dllist.add_head(&dllist, strdup("tata")), 0);
    cr_assert_eq(dllist.add_head(&dllist, strdup("titi")), 0);
    cr_assert_eq(dllist.add_head(&dllist, strdup("tutu")), 0);
    cr_assert_eq(dllist.add_head(&dllist, strdup("tete")), 0);
    node = dllist_get_node_from_tail(&dllist, 3);
    cr_assert_not_null(node);
    cr_assert_str_eq(node->data, "tata");
}

Test(get_node_from_tail, last_node_target,
.description="single call targeting the last node")
{
    dllist_t dllist = dllist_create();
    node_t *node;

    cr_assert_eq(dllist.add_head(&dllist, strdup("toto")), 0);
    cr_assert_eq(dllist.add_head(&dllist, strdup("tata")), 0);
    cr_assert_eq(dllist.add_head(&dllist, strdup("titi")), 0);
    cr_assert_eq(dllist.add_head(&dllist, strdup("tutu")), 0);
    cr_assert_eq(dllist.add_head(&dllist, strdup("tete")), 0);
    node = dllist_get_node_from_tail(&dllist, 4);
    cr_assert_not_null(node);
    cr_assert_str_eq(node->data, "toto");
}