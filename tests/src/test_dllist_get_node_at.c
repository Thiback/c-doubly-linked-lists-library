/*
** PERSONAL PROJECT, 2019
** doubly linked list objects library
** File description:
** ""dllist_get_node_at" unit tests."
*/

#include <criterion/criterion.h>
#include <criterion/logging.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "dllists_obj.h"
#include "test_utils.h"

Test(get_node_at, null_dllist,
.description="single call with a null dllist.")
{
    cr_assert_null(dllist_get_node_at(NULL, 0));
}

Test(get_node_at, empty_dllist,
.description="single call on an empty dllist")
{
    dllist_t dllist = dllist_create();

    cr_assert_null(dllist_get_node_at(&dllist, 0));
}

Test(get_node_at, single_node_list,
.description="single call on a single call list")
{
    dllist_t dllist = dllist_create();
    node_t *target = NULL;

    cr_assert_eq(dllist.add_head(&dllist, strdup("toto")), 0);
    cr_assert_not_null(dllist_get_node_at(&dllist, 0));
    target = dllist_get_node_at(&dllist, 0);
    cr_assert_str_eq(target->data, "toto");
}

Test(get_node_at, two_node_list,
.description="two calls on a two node list")
{
    dllist_t dllist = dllist_create();
    node_t *target = NULL;

    cr_assert_eq(dllist.add_head(&dllist, strdup("toto")), 0);
    cr_assert_eq(dllist.add_head(&dllist, strdup("tata")), 0);
    target = dllist_get_node_at(&dllist, 0);
    cr_assert_not_null(target);
    cr_assert_str_eq(target->data, "tata");
    target = dllist_get_node_at(&dllist, 1);
    cr_assert_not_null(target);
    cr_assert_str_eq(target->data, "toto");
    cr_assert_null(dllist_get_node_at(&dllist, 2));
}

Test(get_node_at, ten_node_list,
.description="checking a full list")
{
    dllist_t dllist = dllist_create();
    node_t *target = NULL;
    char *data[10] = {"toto", "tata", "tutu", "tete", "titi",
                    "dada", "dede", "didi", "dodo", "dudu"};

    for (register int i = 0; i < 10; i++)
        cr_assert_eq(dllist.add_tail(&dllist, strdup(data[i])), 0);
    for (register int i = 0; i < 10; i++) {
        target = dllist_get_node_at(&dllist, i);
        cr_assert_not_null(target);
        cr_assert_str_eq(target->data, data[i]);
    }
}

Test(get_node_at, big_list,
.description="checking a big list")
{
    dllist_t dllist = dllist_create();
    char *data;
    node_t *target = NULL;

    for (register size_t i = 0; i < 1024; ++i) {
        asprintf(&data, "%ld\n", i);
        cr_assert_eq(dllist.add_tail(&dllist, strdup(data)), 0);
        free(data);
    }
    for (register size_t i = 0; i < 1024; ++i) {
        asprintf(&data, "%ld\n", i);
        target = dllist_get_node_at(&dllist, i);
        cr_assert_not_null(target);
        cr_assert_str_eq(target->data, data);
        free(data);
    }
}