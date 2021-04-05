/*
** PERSONAL PROJECT, 2019
** doubly linked list objects library
** File description:
** ""dllist_get_data_at" unit tests."
*/

#include <criterion/criterion.h>
#include <criterion/logging.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "dllists_obj.h"
#include "test_utils.h"

Test(get_data_at, null_dllist,
.description="single call with a null dllist.")
{
    cr_assert_null(dllist_get_data_at(NULL, 0));
}

Test(get_data_at, empty_dllist,
.description="single call on an empty dllist")
{
    dllist_t dllist = dllist_create();

    cr_assert_null(dllist_get_data_at(&dllist, 0));
}

Test(get_data_at, single_node_list,
.description="single call on a single call list")
{
    dllist_t dllist = dllist_create();
    char *target = NULL;

    cr_assert_eq(dllist.add_head(&dllist, strdup("toto")), 0);
    cr_assert_not_null(dllist_get_data_at(&dllist, 0));
    target = (char *)(dllist.at(&dllist, 0));
    cr_assert_str_eq(target, "toto");
}

Test(get_data_at, two_node_list,
.description="two calls on a two node list")
{
    dllist_t dllist = dllist_create();
    char *target = NULL;

    cr_assert_eq(dllist.add_head(&dllist, strdup("toto")), 0);
    cr_assert_eq(dllist.add_head(&dllist, strdup("tata")), 0);
    target = dllist.at(&dllist, 0);
    cr_assert_not_null(target);
    cr_assert_str_eq(target, "tata");
    target = dllist.at(&dllist, 1);
    cr_assert_not_null(target);
    cr_assert_str_eq(target, "toto");
    cr_assert_null(dllist.at(&dllist, 2));
}

Test(get_data_at, ten_node_list,
.description="checking a full list")
{
    dllist_t dllist = dllist_create();
    char *target = NULL;
    char *data[10] = {"toto", "tata", "tutu", "tete", "titi",
                    "dada", "dede", "didi", "dodo", "dudu"};

    for (register int i = 0; i < 10; i++)
        cr_assert_eq(dllist.add_tail(&dllist, strdup(data[i])), 0);
    for (register int i = 0; i < 10; i++) {
        target = dllist.at(&dllist, i);
        cr_assert_not_null(target);
        cr_assert_str_eq(target, data[i]);
    }
}

Test(get_data_at, big_list,
.description="checking a big list")
{
    dllist_t dllist = dllist_create();
    char *data;
    char *target = NULL;

    for (register size_t i = 0; i < 1024; ++i) {
        asprintf(&data, "%ld\n", i);
        cr_assert_eq(dllist.add_tail(&dllist, strdup(data)), 0);
        free(data);
    }
    for (register size_t i = 0; i < 1024; ++i) {
        asprintf(&data, "%ld\n", i);
        target = dllist.at(&dllist, i);
        cr_assert_not_null(target);
        cr_assert_str_eq(target, data);
        free(data);
    }
}