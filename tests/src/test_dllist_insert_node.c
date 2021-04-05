/*
** PERSONAL PROJECT, 2019
** doubly linked list objects library
** File description:
** "dllist_add_head" unit tests.
*/

#include <stdlib.h>
#include <string.h>
#include <criterion/logging.h>
#include "criterion/criterion.h"
#include "test_utils.h"
#include "dllists_obj.h"


Test(insert_node, null_dllist,
.description="single call with a null dllist pointer")
{
    cr_assert_eq(dllist_insert_data(NULL, strdup("toto"), 0), 84);
}

Test(insert_node, empty_dllist,
.description="single call on an empty dllist")
{
    dllist_t dllist = dllist_create();

    cr_assert_eq(dllist.insert(&dllist, strdup("toto"), 0), 0);
    cr_assert_eq(dllist.len, 1);
    cr_assert_not_null(dllist.head);
    cr_assert_eq(dllist.head, dllist.tail);
    cr_assert_str_eq((char *)dllist.head->data, "toto");
}

Test(insert_node, empty_list_out_of_bonds,
.description="single call for inserting out of bonds")
{
    dllist_t dllist = dllist_create();

    cr_assert_eq(dllist.insert(&dllist, strdup("toto"), 1), 84);
}

Test(insert_node, single_node_list_tail,
.description="single call for inserting at the end of a single node list")
{
    dllist_t dllist = dllist_create();
    char *data[] = {"tata", "toto"};

    cr_assert_eq(dllist.add_head(&dllist, strdup("toto")), 0);
    cr_assert_eq(dllist.insert(&dllist, strdup("tata"), 1), 0);
    cmp_list_to_ptr_array(&dllist, data);
    cr_assert_eq(dllist.len, 2);
}

Test(insert_node, single_node_list_head,
.description="single call for inserting at the start of a single node list")
{
    dllist_t dllist = dllist_create();
    char *data[] = {"toto", "tata"};

    cr_assert_eq(dllist.add_head(&dllist, strdup(data[1])), 0);
    cr_assert_eq(dllist.insert(&dllist, strdup(data[0]), 0), 0);
    cr_assert_eq(dllist.len, 2);
}

Test(insert_node, three_node_list,
.description="creating a three node list")
{
    dllist_t dllist = dllist_create();
    char *data[] = {"toto", "tata", "tutu"};

    cr_assert_eq(dllist.insert(&dllist, strdup(data[0]), 0), 0);
    cr_assert_eq(dllist.insert(&dllist, strdup(data[2]), 1), 0);
    cr_assert_eq(dllist.insert(&dllist, strdup(data[1]), 1), 0);
    cr_assert_eq(dllist.len, 3);
    cr_assert_eq(cmp_list_to_ptr_array(&dllist, data), 0);
}

Test(insert_node, ten_node_list,
.description="creating a ten node list")
{
    dllist_t dllist = dllist_create();
    char *data[] = {"toto", "tata", "tutu", "titi", "tete",
                     "lili", "lala", "lolo", "lulu", "lele"};
    char *final_data[] = {"toto", "tata", "tutu", "titi", "tete", "target",
                     "lili", "lala", "lolo", "lulu", "lele"};

    for (register int i = 0; i < 10 ; ++i)
        cr_assert_eq(dllist.add_tail(&dllist, data[i]), 0);
    cr_assert_eq(dllist.insert(&dllist, strdup(final_data[5]), 5), 0);
    cr_assert_eq(cmp_list_to_ptr_array(&dllist, final_data), 0);
    cr_assert_eq(dllist.len, 11);
}

Test(insert_node, ten_node_list_2,
.description="creating a ten node list")
{
    dllist_t dllist = dllist_create();
    char *data[] = {"toto", "tata", "tutu", "titi", "tete",
                     "lili", "lala", "lolo", "lulu", "lele"};
    char *final_data[] = {"toto", "tata", "target", "tutu", "titi", "tete",
                     "lili", "lala", "lolo", "lulu", "lele"};

    for (register int i = 0; i < 10 ; ++i)
        cr_assert_eq(dllist.add_tail(&dllist, data[i]), 0);
    cr_assert_eq(dllist.insert(&dllist, strdup(final_data[2]), 2), 0);
    cr_assert_eq(dllist.len, 11);
    cr_assert_eq(cmp_list_to_ptr_array(&dllist, final_data), 0);
}

Test(insert_node, ten_node_list_3,
.description="creating a ten node list")
{
    dllist_t dllist = dllist_create();
    char *data[] = {"toto", "tata", "tutu", "titi", "tete",
                     "lili", "lala", "lolo", "lulu", "lele"};
    char *final_data[] = {"target", "toto", "tata", "tutu", "titi", "tete",
                     "lili", "lala", "lolo", "lulu", "lele"};

    for (register int i = 0; i < 10 ; ++i)
        cr_assert_eq(dllist.add_tail(&dllist, data[i]), 0);
    cr_assert_eq(dllist.insert(&dllist, strdup(final_data[0]), 0), 0);
    cr_assert_eq(dllist.len, 11);
    cr_assert_eq(cmp_list_to_ptr_array(&dllist, final_data), 0);
}

Test(insert_node, ten_node_list_4,
.description="creating a ten node list")
{
    dllist_t dllist = dllist_create();
    char *data[] = {"toto", "tata", "tutu", "titi", "tete",
                     "lili", "lala", "lolo", "lulu", "lele"};
    char *final_data[] = {"toto", "tata", "tutu", "titi", "tete",
                     "lili", "lala", "lolo", "lulu", "lele", "target"};

    for (register int i = 0; i < 10 ; ++i)
        cr_assert_eq(dllist.add_tail(&dllist, data[i]), 0);
    cr_assert_eq(dllist.insert(&dllist, strdup(final_data[10]), 10), 0);
    cr_assert_eq(dllist.len, 11);
    cr_assert_eq(cmp_list_to_ptr_array(&dllist, final_data), 0);
}

Test(insert_node, ten_node_list_5,
.description="creating a ten node list")
{
    dllist_t dllist = dllist_create();
    char *data[] = {"toto", "tata", "tutu", "titi", "tete",
                     "lili", "lala", "lolo", "lulu", "lele"};
    char *final_data[] = {"toto", "tata", "tutu", "titi", "tete",
                     "lili", "lala", "lolo", "target", "lulu", "lele"};

    for (register int i = 0; i < 10 ; ++i)
        cr_assert_eq(dllist.add_tail(&dllist, data[i]), 0);
    cr_assert_eq(dllist.insert(&dllist, strdup(final_data[8]), 8), 0);
    cr_assert_eq(dllist.len, 11);
    cr_assert_eq(cmp_list_to_ptr_array(&dllist, final_data), 0);
}

Test(insert_node, ten_node_list_6,
.description="creating a ten node list")
{
    dllist_t dllist = dllist_create();
    char *data[] = {"toto", "tata", "tutu", "titi", "tete",
                     "lili", "lala", "lolo", "lulu", "lele"};
    char *final_data[] = {"toto", "tata", "tutu", "titi", "tete",
                     "lili", "lala", "lolo", "lulu", "target", "lele"};

    for (register int i = 0; i < 10 ; ++i)
        cr_assert_eq(dllist.add_tail(&dllist, data[i]), 0);
    cr_assert_eq(dllist.insert(&dllist, strdup(final_data[9]), 9), 0);
    cr_assert_eq(dllist.len, 11);
    cr_assert_eq(cmp_list_to_ptr_array(&dllist, final_data), 0);
}

Test(insert_node, large_list,
.description="creating a very large list")
{
    dllist_t dllist = dllist_create();
    int *data = NULL;
    node_t *current;
    size_t limit = 10;
    register size_t i = 0;

    for (; i < limit; ++i) {
        data = malloc(sizeof(size_t));
        cr_assert_not_null(data);
        *data = i;
        cr_assert_eq(dllist.insert(&dllist, data, i), 0);
    }
    cr_assert_not_null(dllist.head);
    cr_assert_not_null(dllist.tail);
    cr_assert_neq(dllist.head, dllist.tail);
    current = dllist.head;
    for (i = 0; i < limit; ++i) {
        data = current->data;
        cr_assert_eq(*data, i);
        current = current->next;
    }
}
