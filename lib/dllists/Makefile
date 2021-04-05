##
## EPITECH PROJECT, 2019
## doubly linked list objects library
## File description:
## Makefile of the library
##

SRC			=	src/dllist_create.c					\
				src/dllist_add_head.c				\
				src/dllist_add_tail.c				\
				src/dllist_listlen.c				\
				src/dllist_remove_head.c			\
				src/dllist_remove_tail.c			\
				src/dllist_get_node_from_head.c		\
				src/dllist_remove_node_pos.c		\
				src/dllist_get_node_from_tail.c 	\
				src/dllist_get_node_at.c			\
				src/dllist_get_data_at.c			\
				src/dllist_free_list.c				\
				src/dllist_insert_node.c 			\
				src/dllist_swap_data.c 				\
				src/dllist_to_ptr_array.c			\
				src/dllist_reverse_list.c			\
				src/array_to_dllist.c				\
				src/dllist_iterate_with_callback.c	\

OBJ			=	$(SRC:.c=.o)

CFLAGS		=	-Wall -Wextra

CPPFLAGS	=	-I../../include

NAME		=	libdllists.a

all:		$(NAME)

$(NAME):	$(OBJ)
			ar rc $(NAME) $(OBJ)

clean:
			rm -rf $(OBJ)

fclean:		clean
			rm -f $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
