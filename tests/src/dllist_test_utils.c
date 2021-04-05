/*
** EPITECH PROJECT, 2019
** singly linked lists (sllist) library
** File description:
** Utility functions for the unit testing of the sllist library
*/

#include "criterion/logging.h"
#include <stdio.h>
#include <stdlib.h>
#include "dllists_obj.h"
#include "string.h"
#include "test_utils.h"

#define OK 0
#define KO 84

void print(dllist_t *dllist)
{
    node_t *current = dllist->head;

    while (current) {
        printf("%s\n", (char *)current->data);
        fflush(stdout);
        current = current->next;
    }
}

void print_reverse(dllist_t *dllist)
{
    node_t *current = dllist->tail;

    while (current) {
        printf("%s\n", (char *)current->data);
        fflush(stdout);
        current = current->prev;
    }
}

void debug_print(dllist_t *dllist)
{
    node_t *current = dllist->head;

    while (current) {
        printf("       %s\n", (char *)current->data);
        cr_log_warn("%s\n", (char *)current->data);
        fflush(stdout);
        current = current->next;
    }
}

void debug_print_reverse(dllist_t *dllist)
{
    node_t *current = dllist->tail;

    while (current) {
        printf("       %s\n", (char *)current->data);
        cr_log_warn("%s\n", (char *)current->data);
        fflush(stdout);
        current = current->prev;
    }
}

int cmp_list_to_ptr_array(dllist_t *dllist, char **array)
{
    node_t *current = dllist->head;

    for (register int i = 0; array[i] && current; ++i) {
        if ((current->data == NULL && array[i] != NULL) ||
            (array[i] == NULL && current->data != NULL))
            return (KO);
        else if ((array[i] && current->data) &&
            (strcmp(array[i], current->data) != 0))
            return (KO);
        current = current->next;
    }
    return (OK);
}

int rev_cmp_list_to_ptr_array(dllist_t *dllist, char **array)
{
    node_t *current = dllist->tail;
    register int i = dllist->len - 1;

    while (array[i] && current) {
        if ((current->data == NULL && array[i] != NULL) ||
            (array[i] == NULL && current->data != NULL))
            return (KO);
        else if ((array[i] && current->data) &&
            (strcmp(array[i], current->data) != 0))
            return (KO);
        current = current->prev;
        --i;
    }
    return (OK);
}

/*
** checks the list contents from start to end and from end to start
*/
int check_list_to_array_integrity(dllist_t *dllist, char **array)
{
    if (cmp_list_to_ptr_array(dllist, array) != OK)
        return (KO);
    else if (rev_cmp_list_to_ptr_array(dllist, array) != OK)
        return (KO);
    return (OK);
}

int debug_check_list_to_array_integrity(dllist_t *dllist, char **array)
{
    if (debug_cmp_list_to_ptr_array(dllist, array) != OK) {
        cr_log_warn("dllist HEAD-->TAIL isn't identical to pointer array!");
        return (KO);
    } else if (debug_rev_cmp_list_to_ptr_array(dllist, array) != OK) {
        cr_log_warn("dllist TAIL-->HEAD isn't identical to pointer array!");
        return (KO);
    }
    return (OK);
}

int debug_rev_cmp_list_to_ptr_array(dllist_t *dllist, char **array)
{
    char *debug_output = NULL;
    node_t *current = dllist->tail;

    cr_log_warn("COMPARING list and array contents:\n");
    for (register size_t i = dllist->len - 1 ; array[i] && dllist && current ; --i) {
        if (current) {
            asprintf(&debug_output,
            "  CMP list: {\x1b[97m%s\x1b[0m}\tarray[%ld]: {\x1b[97m%s\x1b[0m}",
                (current->data ? (char *)current->data : "NULL"),
                i, (array[i] ? array[i] :"NULL"));
        }
        if (!current || (current->data == NULL && array[i] != NULL) ||
            (array[i] == NULL && current->data != NULL)) {
            cr_log_warn("%s --> \x1b[91mKO\x1b[0m\n", debug_output);
            free(debug_output);
            return (KO);
        } else if ((array[i] && current->data) &&
            (strcmp(array[i], (char *)current->data) != 0)) {
            cr_log_warn("%s --> \x1b[91mKO\x1b[0m\n", debug_output);
            free(debug_output);
            return (KO);
        }
        cr_log_warn("%s --> OK\n", debug_output);
        free(debug_output);
        debug_output = NULL;
        current = current->prev;
    }
    cr_log_warn("COMPARISON OK\n");
    return (OK);
}

int debug_cmp_list_to_ptr_array(dllist_t *dllist, char **array)
{
    char *debug_output = NULL;
    node_t *current = dllist->head;

    cr_log_warn("COMPARING list and array contents:\n");
    for (register int i = 0; array[i] && dllist && current ; ++i) {
        if (current) {
            asprintf(&debug_output,
            "  CMP list: {\x1b[97m%s\x1b[0m}\tarray[%d]: {\x1b[97m%s\x1b[0m}",
                (current->data ? (char *)current->data : "NULL"),
                i, (array[i] ? array[i] :"NULL"));
        }
        if (!current || (current->data == NULL && array[i] != NULL) ||
            (array[i] == NULL && current->data != NULL)) {
            cr_log_warn("%s --> \x1b[91mKO\x1b[0m\n", debug_output);
            free(debug_output);
            return (KO);
        } else if ((array[i] && current->data) &&
            (strcmp(array[i], (char *)current->data) != 0)) {
            cr_log_warn("%s --> \x1b[91mKO\x1b[0m\n", debug_output);
            free(debug_output);
            return (KO);
        }
        cr_log_warn("%s --> OK\n", debug_output);
        free(debug_output);
        debug_output = NULL;
        current = current->next;
    }
    cr_log_warn("COMPARISON OK\n");
    return (OK);
}

void print_list_adv(dllist_t *dllist)
{
    node_t *current = dllist->head;

    cr_log_warn("Printing list adv:\n");
    if (!current) {
        cr_log_warn("HEAD is NULL\ndone printing\n");
        return;
    }
    for (register int i = 0; current; ++i) {
        cr_log_warn("\t[%d]prev = \"%s\"\n", i, current->prev ? (char *)(current->prev->data) : "NULL");
        cr_log_warn("\t[%d]current = \"\x1b[97m%s\x1b[0m\"\n", i, (char *)(current->data));
        cr_log_warn("\t[%d]next = \"%s\"\n", i, current->next ? (char *)current->next->data : "NULL");
        cr_log_warn("\t\n");
        current = current->next;
    }
    cr_log_warn("done printing\n");
}