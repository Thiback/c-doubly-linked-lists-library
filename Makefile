##
## PERSONAL PROJECT, 2019
## doubly linked list objects library
## File description:
## Makefile of the library
##

SRC			=	src/main.c	\

OBJ			=	$(SRC:.c=.o)

CPPFLAGS	=	-I./include/

CFLAGS		=	-Wall -Wextra -g

CC			=	gcc

LIBDIR		=	lib/dllists/

LIBNAME		=	dllists

DEBUG_SRC		=	$(LIBDIR)src/dllist_create.c				\
					$(LIBDIR)src/dllist_add_head.c				\
					$(LIBDIR)src/dllist_add_tail.c				\
					$(LIBDIR)src/dllist_listlen.c				\
					$(LIBDIR)src/dllist_remove_head.c			\
					$(LIBDIR)src/dllist_remove_tail.c			\
					$(LIBDIR)src/dllist_get_node_from_head.c	\
					$(LIBDIR)src/dllist_remove_node_pos.c		\
					$(LIBDIR)src/dllist_get_node_from_tail.c 	\
					$(LIBDIR)src/dllist_get_data_at.c			\
					$(LIBDIR)src/dllist_get_node_at.c			\
					$(LIBDIR)src/dllist_free_list.c				\
					$(LIBDIR)src/dllist_insert_node.c 			\
					$(LIBDIR)src/dllist_swap_data.c 			\
					$(LIBDIR)src/dllist_to_ptr_array.c 			\
					$(LIBDIR)src/dllist_reverse_list.c 			\
					$(LIBDIR)src/dllist_iterate_with_callback.c \
					$(LIBDIR)src/array_to_dllist.c				\
					src/main.c									\

DEBUG_OBJ		=	$(DEBUG_SRC:.c=.o)

NAME		=	dllists_functional_tests

UT_DIR	=	./tests/

all:		$(NAME)

$(NAME):	$(OBJ)
			make -C $(LIBDIR)
			$(CC) $(CFLAGS)	$(CPPFLAGS) $(OBJ) -o $(NAME) -L $(LIBDIR) -l $(LIBNAME)

clean:
			rm -rf $(OBJ)
			make -C $(LIBDIR) clean
			make -C $(UT_DIR) clean

fclean:		clean
			rm -f $(NAME)
			make -C $(LIBDIR) fclean
			make -C $(UT_DIR) fclean

tests_run:
			make -C $(UT_DIR) && ./tests/unit_tests

debug:		$(DEBUG_OBJ)
			$(CC) $(CFLAGS) -o $(NAME) $(DEBUG_OBJ) $(CRITERION) $(CPPFLAGS)

re:			fclean all

.PHONY:		all clean fclean re tests_run
