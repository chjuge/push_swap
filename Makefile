DIR		= 	src

SRCS	=	$(DIR)/adjust_cmds.c \
			$(DIR)/bubble_sort.c \
			$(DIR)/check_input.c \
			$(DIR)/check_is_sorted.c \
			$(DIR)/checks.c \
			$(DIR)/cmds_push.c \
			$(DIR)/cmds_rotate.c \
			$(DIR)/cmds_rotate_rev.c \
			$(DIR)/cmds_swap.c \
			$(DIR)/deep_free.c \
			$(DIR)/execute_cmds.c \
			$(DIR)/fill_stack_a.c \
			$(DIR)/fill_stack_b.c \
			$(DIR)/fill_store.c \
			$(DIR)/find_appropriate.c \
			$(DIR)/find_max_min_med.c \
			$(DIR)/find_min_score.c \
			$(DIR)/find_score.c \
			$(DIR)/ft_atoi.c \
			$(DIR)/ft_split.c \
			$(DIR)/full_free.c \
			$(DIR)/main.c \
			$(DIR)/parse_args.c \
			$(DIR)/show.c \
			$(DIR)/sorting.c \
			$(DIR)/to_head.c \
			$(DIR)/transform_args.c \
			$(DIR)/utils1.c \
			$(DIR)/utils2.c \
			$(DIR)/score_to_zero.c \
			$(DIR)/adjasting_input.c \
			$(DIR)/deep_copy.c \
			$(DIR)/cut_head.c \
			$(DIR)/ft_lstnew.c \
			$(DIR)/add_front_back.c \
			$(DIR)/sort_3.c	\
			$(DIR)/final_rotates.c \
			$(DIR)/sort_fast.c \
			$(DIR)/find_all_scores.c \
			$(DIR)/find_route.c \
			$(DIR)/adjust_by_route.c \
			$(DIR)/route_calc.c

OBJS	= 	$(SRCS:.c=.o)

HEAD	=	header/push_swap.h

CC		=	gcc
CFLAGS	=	-Wall -Werror -Wextra
#  -fsanitize=address
# -static-libsan -g
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