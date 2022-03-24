DIR		= 	src

SRCS	=	$(DIR)/bubble_sort.c  \
			$(DIR)/check_input.c	\
			$(DIR)/checks.c \
			$(DIR)/ft_atoi.c \
			$(DIR)/ft_split.c \
			$(DIR)/main.c \
			$(DIR)/parse_args.c \
			$(DIR)/transform_args.c \
			$(DIR)/utils_lst.c \
			$(DIR)/utils1.c \
			$(DIR)/utils2.c \
			$(DIR)/deep_free.c \
			$(DIR)/show.c

OBJS	= 	$(SRCS:.c=.o)

HEAD	=	header/push_swap.h

CC		=	gcc
CFLAGS	=	-Wall -Werror -Wextra
RM		=	rm -rf

NAME	=	push_swap

all:		$(NAME)

$(NAME):	$(OBJS) $(HEAD)
			$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:		
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all


.PHONY:		all clean fclean re