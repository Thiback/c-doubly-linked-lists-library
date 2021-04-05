/*
** PERSONAL PROJECT, 2019
** doubly linked list objects library
** File description:
** "dllist_add_tail" unit tests.
*/

#include <stdlib.h>
#include <string.h>
#include <criterion/logging.h>
#include "criterion/criterion.h"
#include "dllists_obj.h"

Test(add_dllist_tail, single_call_empty_list,
.description="single call on a empty list object.")
{
    dllist_t mylist = dllist_create();

    cr_assert_eq(mylist.add_tail(&mylist, "tata"), 0);
    cr_assert_eq(mylist.len, 1);
    cr_assert_not_null(mylist.head);
    cr_assert_eq(mylist.head, mylist.tail);
    cr_assert_null(mylist.head->next);
    cr_assert_null(mylist.head->prev);
}

Test(add_dllist_tail, single_call_single_node,
.description="single call on a list with only one node")
{
    dllist_t mylist = dllist_create();

    mylist.head = malloc(sizeof(node_t));
    mylist.tail = mylist.head;
    mylist.head->data = strdup("tata");
    mylist.len = 1;

    cr_assert_eq(mylist.add_tail(&mylist, "tail"), 0);
    cr_assert_eq(mylist.len, 2);
    cr_assert_neq(mylist.head, mylist.tail);
    cr_assert_eq(strcmp(mylist.tail->data, "tail"), 0);
    cr_assert_eq(mylist.head->prev, NULL);
    cr_assert_eq(mylist.head->next, mylist.tail);
    cr_assert_eq(strcmp(mylist.head->data, "tata"), 0);
    cr_assert_eq(mylist.tail->next, NULL);
    cr_assert_eq(mylist.tail->prev, mylist.head);
}

Test(add_dllist_tail, three_node_list_creation,
.description="creation of a list of three nodes.")
{
    dllist_t mylist = dllist_create();
    node_t *node_2;
    node_t *node_3;

    cr_assert_eq(mylist.add_tail(&mylist, "tata"), 0);
    cr_assert_eq(mylist.add_tail(&mylist, "titi"), 0);
    cr_assert_eq(mylist.add_tail(&mylist, "tutu"), 0);

    //testing the dllist_t object
    cr_assert_not_null(mylist.head);
    cr_assert_neq(mylist.head, mylist.tail);
    cr_assert_eq(mylist.len, 3);

    //testing the head node
    cr_assert_eq(strcmp(mylist.head->data, "tata"), 0);
    cr_assert_eq(mylist.head->prev, NULL);
    cr_assert_not_null(mylist.head->next);

    //testing the second node
    node_2 = mylist.head->next;
    cr_assert_eq(strcmp(node_2->data, "titi"), 0);
    cr_assert_not_null(node_2->next);
    cr_assert_eq(node_2->prev, mylist.head);
    cr_assert_not_null(node_2->next);

    //testing the last node
    node_3 = node_2->next;
    cr_assert_eq(node_3, mylist.tail);
    cr_assert_eq(strcmp(node_3->data, "tutu"), 0);
    cr_assert_eq(node_3->prev, node_2);
    cr_assert_null(node_3->next);
}

Test(add_dllist_tail, five_node_list_creation,
.description="creation of a list of three nodes.")
{
    dllist_t mylist = dllist_create();
    node_t *node_2;
    node_t *node_3;
    node_t *node_4;
    node_t *node_5;

    cr_assert_eq(mylist.add_tail(&mylist, "tata"), 0);
    cr_assert_eq(mylist.add_tail(&mylist, "titi"), 0);
    cr_assert_eq(mylist.add_tail(&mylist, "tutu"), 0);
    cr_assert_eq(mylist.add_tail(&mylist, "tete"), 0);
    cr_assert_eq(mylist.add_tail(&mylist, "toto"), 0);

    //testing the dllist_t object
    cr_assert_not_null(mylist.head);
    cr_assert_neq(mylist.head, mylist.tail);
    cr_assert_eq(mylist.len, 5);

    //testing the head node
    cr_assert_eq(strcmp(mylist.head->data, "tata"), 0);
    cr_assert_eq(mylist.head->prev, NULL);
    cr_assert_not_null(mylist.head->next);

    //testing the second node
    node_2 = mylist.head->next;
    cr_assert_eq(strcmp(node_2->data, "titi"), 0);
    cr_assert_not_null(node_2->next);
    cr_assert_eq(node_2->prev, mylist.head);
    cr_assert_not_null(node_2->next);

    //testing the third node
    node_3 = node_2->next;
    cr_assert_eq(strcmp(node_3->data, "tutu"), 0);
    cr_assert_eq(node_3->prev, node_2);
    cr_assert_not_null(node_3->next);

    //testing the fourth node
    node_4 = node_3->next;
    cr_assert_eq(strcmp(node_4->data, "tete"), 0);
    cr_assert_eq(node_4->prev, node_3);
    cr_assert_not_null(node_4->next);

    //testing the last node
    node_5 = node_4->next;
    cr_assert_eq(strcmp(node_5->data, "toto"), 0);
    cr_assert_eq(node_5, mylist.tail);
    cr_assert_eq(node_5->prev, node_4);
    cr_assert_null(node_5->next);
}