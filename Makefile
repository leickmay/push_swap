HEADER		=	includes/checker.h includes/push_swap.h

SRCS_C		=	srcs_checker/check_args.c srcs_checker/main.c srcs_checker/operations.c \
				srcs_checker/operations_bis.c srcs_checker/operations_ter.c srcs_checker/stack.c

SRCS_P		=	srcs_push_swap/check_args.c srcs_push_swap/main.c srcs_push_swap/operations.c \
				srcs_push_swap/operations_bis.c srcs_push_swap/operations_ter.c srcs_push_swap/stack.c \
				srcs_push_swap/sort.c srcs_push_swap/little_range_algo.c  \
				srcs_push_swap/sort_utils.c srcs_push_swap/min_max_algo.c \
				 srcs_push_swap/huge_sort.c srcs_push_swap/giga_huge_sort.c srcs_push_swap/sort_utils_bis.c


LIBFT		=	libft.a

NAME		=	checker

NAME_P		=	push_swap

CC			=	gcc

CFLAGS		=	-Wall -Werror -Wextra

OBJS_C		=	$(SRCS_C:.c=.o)

OBJS_P		=	$(SRCS_P:.c=.o)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME):	$(OBJS_C) $(OBJS_P) $(HEADER)
			$(MAKE) -C ./libft
			cp libft/libft.a .
			$(CC) -o $(NAME) $(SRCS_C) $(LIBFT)
			$(CC) -o $(NAME_P) $(SRCS_P) $(LIBFT)

#$(NAME_P):	$(OBJS_P) $(HEADER_P)
#			$(MAKE) -C ./libft
#			cp libft/libft.a .
#			$(CC) -o $(NAME_P) $(SRCS_P) $(LIBFT)

all :	$(NAME)

clean : 
		$(MAKE) clean -C ./libft
		rm -rf $(OBJS_C) $(OBJS_P)

fclean :
		$(MAKE) fclean -C ./libft
		rm -rf $(OBJS_C) libft.a checker $(OBJS_P) push_swap
	
re :	fclean all

.PHONY : clean fclean re all