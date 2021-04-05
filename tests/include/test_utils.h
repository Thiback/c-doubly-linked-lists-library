/*
** PERSONAL PROJECT, 2019
** doubly linked list objects library
** File description:
** header for utility functions used in the unit tests of the dllist library.
*/

#ifndef TEST_UTILS
#define TEST_UTILS

#include "dllists_obj.h"

void print(dllist_t *dllist_t);
void print_reverse(dllist_t *dllist);
void print_list_adv(dllist_t *dllist);
int cmp_list_to_ptr_array(dllist_t *dllist, char **array);
int rev_cmp_list_to_ptr_array(dllist_t *dllist, char **array);
int check_list_to_array_integrity(dllist_t *dllist, char **array);

/*
** debug variants of the function above behave the same way,
** but display additional data for debbugging purposes.
*/

void debug_print(dllist_t *dllist);
void debug_print_reverse(dllist_t *dllist);
int debug_cmp_list_to_ptr_array(dllist_t *dllist, char **array);
int debug_rev_cmp_list_to_ptr_array(dllist_t *dllist, char **array);
int debug_check_list_to_array_integrity(dllist_t *dllist, char **array);

#endif
