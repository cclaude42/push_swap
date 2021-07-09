NAME = push_swap

CC = clang

CFLAGS = -Wall -Wextra -Werror

HEADER = push_swap.h

SRC = push_swap.c parsing.c basic_algorithm.c instructions.c \
		list_utils.c list_utils2.c list_utils3.c

OBJ = $(SRC:c=o)

SRCB =

OBJB = $(SRCB:c=o)

all: $(NAME)

$(NAME): $(OBJ)
	@echo "\033[0;32m\n\nCompiling push_swap..."
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ)
	@echo "\n\033[0mDone !"

%.o: %.c
	@printf "\033[0;33mGenerating push_swap objects... %-10.10s\r" $@
	@${CC} ${CFLAGS} -c $< -o $@

clean:
	@echo "\033[0;31m\nDeleting objects..."
	@rm -f $(OBJ)
	@echo "\033[0m"

fclean:
	@echo "\033[0;31m\nDeleting objects..."
	@rm -f $(OBJ)
	@echo "\nDeleting executable..."
	@rm -f $(NAME)
	@echo "\033[0m"

re: fclean all

$(NAME)_bonus: $(OBJB)
	@echo "\033[0;32m\n\nCompiling push_swap (with bonuses)..."
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJB)
	@echo "\n\033[0mDone !"

.PHONY: clean fclean re bonus
