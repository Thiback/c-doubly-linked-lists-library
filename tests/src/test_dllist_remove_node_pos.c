/*
** PERSONAL PROJECT, 2019
** doubly linked list objects library
** File description:
** "dllist_remove_pos" unit tests.
*/

#include "dllists_obj.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <criterion/logging.h>
#include <stddef.h>
#include <string.h>

Test(remove_pos, call_on_null_dllist,
.description="call on a null pointer")
{
    dllist_t *mylist = NULL;

    cr_assert_eq(dllist_remove_node_pos(mylist, 0), 84);
}

Test(remove_pos, call_on_empty_dllist,
.description="call on an empty list")
{
    dllist_t mylist = dllist_create();

    cr_assert_eq(dllist_remove_node_pos(&mylist, 0), 84);
}

Test(remove_pos, out_of_bounds_removal,
.description="call with an index too high")
{
    dllist_t mylist = dllist_create();

    cr_assert_eq(mylist.add_head(&mylist, strdup("tata")), 0);
    cr_assert_eq(mylist.add_head(&mylist, strdup("titi")), 0);
    cr_assert_eq(mylist.add_head(&mylist, strdup("tutu")), 0);
    cr_assert_eq(mylist.remove_pos(&mylist, 3),84);
    cr_assert_eq(mylist.listlen(&mylist), 3);
}

Test(remove_pos, remove_head,
.description="remove the head of a list")
{
    dllist_t mylist = dllist_create();

    cr_assert_eq(mylist.add_head(&mylist, strdup("tata")), 0);
    cr_assert_eq(mylist.add_head(&mylist, strdup("titi")), 0);
    cr_assert_eq(mylist.add_head(&mylist, strdup("tutu")), 0);
    cr_assert_eq(mylist.remove_pos(&mylist, 0), 0);
    cr_assert_not_null(mylist.head);
    cr_assert_not_null(mylist.tail);
    cr_assert_neq(mylist.head, mylist.tail);
    cr_assert_str_eq(mylist.head->data, "titi");
    cr_assert_str_eq(mylist.tail->data, "tata");
    cr_assert_null(mylist.head->prev);
    cr_assert_eq(mylist.head->next, mylist.tail);
    cr_assert_eq(mylist.tail->prev, mylist.head);
    cr_assert_null(mylist.tail->next);
    cr_assert_eq(mylist.listlen(&mylist), 2);
}

Test(remove_pos, remove_tail,
.description="remove the tail of a list")
{
    dllist_t mylist = dllist_create();

    cr_assert_eq(mylist.add_tail(&mylist, strdup("tata")), 0);
    cr_assert_eq(mylist.add_tail(&mylist, strdup("titi")), 0);
    cr_assert_eq(mylist.add_tail(&mylist, strdup("tutu")), 0);
    cr_assert_eq(mylist.remove_pos(&mylist, 2), 0);
    cr_assert_not_null(mylist.head);
    cr_assert_not_null(mylist.tail);
    cr_assert_neq(mylist.head, mylist.tail);
    cr_assert_eq(strcmp(mylist.head->data, "tata"), 0);
    cr_assert_eq(strcmp(mylist.tail->data, "titi"), 0);
    cr_assert_null(mylist.head->prev);
    cr_assert_eq(mylist.head->prev, mylist.tail->next);
    cr_assert_eq(mylist.tail->prev, mylist.head);
    cr_assert_null(mylist.tail->next);
    cr_assert_eq(mylist.listlen(&mylist), 2);
}

Test(remove_pos, remove_center,
.description="remove a central node", .init=cr_redirect_stdout)
{
    dllist_t mylist = dllist_create();
    node_t *target_prev = NULL;
    node_t *target_next = NULL;
    node_t *current = NULL;

    cr_assert_eq(mylist.add_tail(&mylist, strdup("tata")), 0);
    cr_assert_eq(mylist.add_tail(&mylist, strdup("titi")), 0);
    target_prev = mylist.tail;
    cr_assert_eq(mylist.add_tail(&mylist, strdup("tutu")), 0);
    cr_assert_eq(mylist.add_tail(&mylist, strdup("tete")), 0);
    target_next = mylist.tail;
    cr_assert_eq(mylist.add_tail(&mylist, strdup("toto")), 0);

    cr_assert_eq(mylist.remove_pos(&mylist, 2), 0);
    cr_assert_not_null(mylist.head);
    cr_assert_not_null(mylist.tail);
    cr_assert_neq(mylist.head, mylist.tail);
    cr_assert_null(mylist.head->prev);
    cr_assert_eq(mylist.head->prev, mylist.tail->next);
    cr_assert_eq(mylist.tail->prev->prev, mylist.head->next);
    cr_assert_null(mylist.tail->next);
    cr_assert_not_null(target_prev);
    cr_assert_str_eq(target_prev->data, "titi");
    cr_assert_eq(target_prev->next, target_next);
    cr_assert_not_null(target_next);
    cr_assert_eq(target_next->prev, target_prev);
    cr_assert_str_eq(target_next->data, "tete");

    cr_assert_eq(mylist.listlen(&mylist), 4);
    current = mylist.head;
    while (current) {
        printf("%s\n", (char *)current->data);
        current = current->next;
    }
    fflush(stdout);
    cr_assert_stdout_eq_str("tata\ntiti\ntete\ntoto\n");
}