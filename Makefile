NAME = push_swap

RED		=	\033[91;1m
GREEN	=	\033[92;1m
CLEAR	=	\033[0m

CC = gcc

CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g3

RM = rm -f
		
SRCS = src/push_swap.c src/ft_utils.c src/check_numbers.c src/stack_manager.c \
		src/moves/push.c src/moves/rotate.c src/moves/swap.c src/sort_functions.c\
		src/real_sort_functions.c \

OBJS = $(SRCS:.c=.o)

INCLUDES = -I includes/push_swap.h -I includes/libft.h

LIBFT_DIR = libft/

MAKEFLAGS += --silent

all: $(NAME)

bonus: $(NAME_BONUS)

$(NAME): $(OBJS)
	@make bonus -sC $(LIBFT_DIR)
	@cp ./libft/libft.a .
	@echo "$(GREEN)Libft compiled"
	@$(CC) $(CFLAGS) $(OBJS) $(INCLUDES) libft.a -o $(NAME)
	@echo "$(GREEN)Push_Swap compiled"

clean :
		@$(RM) $(OBJS)
		@make clean -sC  $(LIBFT_DIR)
		@echo "$(RED)Clean done"

fclean : clean
		@$(RM) $(NAME)
		@make fclean -sC  $(LIBFT_DIR)
		@$(RM) $(NAME) libft.a
		@echo "$(RED)fclean done"

re : fclean all

.PHONY: all clean fclean re