HEADER		= includes/checker.h

SRCS_C		=	srcs_checker/check_args.c srcs_checker/main.c srcs_checker/operations.c \
				srcs_checker/operations_bis.c srcs_checker/operations_ter.c srcs_checker/stack.c

LIBFT		=	libft.a

NAME_C		=	checker

CC			=	gcc

CFLAGS		=	-Wall -Werror -Wextra

OBJS_C		=	$(SRCS_C:.c=.o)
.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME_C):	$(OBJS_C) $(HEADER)
			$(MAKE) -C ./libft
			cp libft/libft.a .
			$(CC) -o $(NAME_C) $(SRCS_C) $(LIBFT)

all :	$(NAME_C)

clean : 
		$(MAKE) clean -C ./libft
		rm -rf $(OBJS_C)

fclean :
		$(MAKE) fclean -C ./libft
		rm -rf $(OBJS_C) libft.a checker
	
re :	fclean all

.PHONY : clean fclean re all