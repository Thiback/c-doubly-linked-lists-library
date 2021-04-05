/*
** PERSONAL PROJECT, 2019
** doubly linked list objects library
** File description:
** "dllist get node from head" unit tests
*/

#include "criterion/criterion.h"
#include "dllists_obj.h"

Test(get_node_from_head, null_dllist,
.description="single call with a null pointer as parameter")
{
    cr_assert_eq(dllist_get_node_from_head(NULL, 0), NULL);
}

Test(get_node_from_head, null_head,
.description="single call with null head ptr")
{
    dllist_t dllist = dllist_create();

    dllist.len = 2;
    cr_assert_eq(dllist_get_node_from_head(&dllist, 2), NULL);
}

Test(get_node_from_head, length_zero,
.description="single call on a list with a length of 0")
{
    dllist_t dllist = dllist_create();

    cr_assert_eq(dllist.add_head(&dllist, strdup("toto")), 0);
    dllist.len = 0;
    cr_assert_eq(dllist_get_node_from_head(&dllist, 2), NULL);
}

Test(get_node_from_head, head_node_target,
.description="single call targeting the head node")
{
    dllist_t dllist = dllist_create();
    node_t *node;

    cr_assert_eq(dllist.add_head(&dllist, strdup("toto")), 0);
    cr_assert_eq(dllist.add_head(&dllist, strdup("tata")), 0);
    cr_assert_eq(dllist.add_head(&dllist, strdup("titi")), 0);
    node = dllist_get_node_from_head(&dllist, 0);
    cr_assert_not_null(node);
    cr_assert_str_eq(node->data, "titi");
}

Test(get_node_from_head, second_node_target,
.description="single call targeting the second node")
{
    dllist_t dllist = dllist_create();
    node_t *node;

    cr_assert_eq(dllist.add_head(&dllist, strdup("toto")), 0);
    cr_assert_eq(dllist.add_head(&dllist, strdup("tata")), 0);
    cr_assert_eq(dllist.add_head(&dllist, strdup("titi")), 0);
    node = dllist_get_node_from_head(&dllist, 1);
    cr_assert_not_null(node);
    cr_assert_str_eq(node->data, "tata");
}

Test(get_node_from_head, middle_node_target,
.description="single call targeting the middle node")
{
    dllist_t dllist = dllist_create();
    node_t *node;

    cr_assert_eq(dllist.add_head(&dllist, strdup("toto")), 0);
    cr_assert_eq(dllist.add_head(&dllist, strdup("tata")), 0);
    cr_assert_eq(dllist.add_head(&dllist, strdup("titi")), 0);
    cr_assert_eq(dllist.add_head(&dllist, strdup("tutu")), 0);
    cr_assert_eq(dllist.add_head(&dllist, strdup("tete")), 0);
    node = dllist_get_node_from_head(&dllist, 2);
    cr_assert_not_null(node);
    cr_assert_str_eq(node->data, "titi");
}

Test(get_node_from_head, second_to_last_node_target,
.description="single call targeting a second to last node")
{
    dllist_t dllist = dllist_create();
    node_t *node;

    cr_assert_eq(dllist.add_head(&dllist, strdup("toto")), 0);
    cr_assert_eq(dllist.add_head(&dllist, strdup("tata")), 0);
    cr_assert_eq(dllist.add_head(&dllist, strdup("titi")), 0);
    cr_assert_eq(dllist.add_head(&dllist, strdup("tutu")), 0);
    cr_assert_eq(dllist.add_head(&dllist, strdup("tete")), 0);
    node = dllist_get_node_from_head(&dllist, 3);
    cr_assert_not_null(node);
    cr_assert_str_eq(node->data, "tata");
}

Test(get_node_from_head, last_node_target,
.description="single call targeting the last node")
{
    dllist_t dllist = dllist_create();
    node_t *node;

    cr_assert_eq(dllist.add_head(&dllist, strdup("toto")), 0);
    cr_assert_eq(dllist.add_head(&dllist, strdup("tata")), 0);
    cr_assert_eq(dllist.add_head(&dllist, strdup("titi")), 0);
    cr_assert_eq(dllist.add_head(&dllist, strdup("tutu")), 0);
    cr_assert_eq(dllist.add_head(&dllist, strdup("tete")), 0);
    node = dllist_get_node_from_head(&dllist, 4);
    cr_assert_not_null(node);
    cr_assert_str_eq(node->data, "toto");
}