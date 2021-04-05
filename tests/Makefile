##
## PERSONAL PROJECT, 2019
## doubly linked list objects library
## File description:
## header of the library
##

NAME			=	unit_tests

SRC_PATH		=	../lib/dllists/src/

UNITS_SRC_PATH	=	./src/

SRC				=	$(SRC_PATH)dllist_create.c								\
					$(SRC_PATH)dllist_add_head.c							\
					$(SRC_PATH)dllist_add_tail.c							\
					$(SRC_PATH)dllist_listlen.c								\
					$(SRC_PATH)dllist_remove_head.c							\
					$(SRC_PATH)dllist_remove_tail.c 						\
					$(SRC_PATH)dllist_get_node_from_head.c					\
					$(SRC_PATH)dllist_get_node_from_tail.c 					\
					$(SRC_PATH)dllist_remove_node_pos.c						\
					$(SRC_PATH)dllist_get_node_at.c 						\
					$(SRC_PATH)dllist_get_data_at.c							\
					$(SRC_PATH)dllist_free_list.c 							\
					$(SRC_PATH)dllist_insert_node.c 						\
					$(SRC_PATH)dllist_swap_data.c 							\
					$(SRC_PATH)dllist_to_ptr_array.c 						\
					$(SRC_PATH)dllist_reverse_list.c 						\
					$(SRC_PATH)dllist_iterate_with_callback.c				\
					$(SRC_PATH)array_to_dllist.c							\
					$(UNITS_SRC_PATH)test_dllist_create.c					\
					$(UNITS_SRC_PATH)test_dllist_add_head.c					\
					$(UNITS_SRC_PATH)test_dllist_add_tail.c					\
					$(UNITS_SRC_PATH)test_dllist_listlen.c					\
					$(UNITS_SRC_PATH)test_dllist_remove_head.c				\
					$(UNITS_SRC_PATH)test_dllist_remove_tail.c 				\
					$(UNITS_SRC_PATH)test_dllist_get_node_from_head.c		\
					$(UNITS_SRC_PATH)test_dllist_get_node_from_tail.c 		\
					$(UNITS_SRC_PATH)test_dllist_remove_node_pos.c			\
					$(UNITS_SRC_PATH)test_dllist_get_node_at.c 				\
					$(UNITS_SRC_PATH)test_dllist_get_data_at.c 				\
					$(UNITS_SRC_PATH)test_dllist_free_list.c 				\
					$(UNITS_SRC_PATH)test_dllist_insert_node.c 				\
					$(UNITS_SRC_PATH)test_dllist_swap_data.c 				\
					$(UNITS_SRC_PATH)test_dllist_to_ptr_array.c 			\
					$(UNITS_SRC_PATH)test_dllist_reverse_list.c				\
					$(UNITS_SRC_PATH)test_array_to_dllist.c					\
					$(UNITS_SRC_PATH)test_dllist_iterate_with_callback.c	\
					$(UNITS_SRC_PATH)dllist_test_utils.c					\

OBJ				=	$(SRC:.c=.o)

CC				=	gcc

CFLAGS			=	-Wall -Wextra -W -fprofile-arcs -ftest-coverage -D _GNU_SOURCE

CPPFLAGS		=	-I../include/ -I./include/

CRITERION		=	-lgcov -lcriterion

all:			$(NAME)

$(NAME):		fclean $(OBJ)
				$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(CRITERION) $(CPPFLAGS)
				./$(NAME)

clean:
				$(RM) -rf $(OBJ) $(DEBUG_OBJ)

fclean:			clean
				$(RM) -f $(NAME)
				find ../ -name "*.gcda" -delete -o -name "*.gcno" -delete

re:				fclean all

.PHONY:			all clean fclean re
