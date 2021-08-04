###################################
# Main : stack sorting program
###################################

NAME = push_swap

CC = clang

CFLAGS = -Wall -Wextra -Werror

INCLUDES = includes

SRC = $(addprefix srcs/, \
		push_swap.c parsing.c instructions.c algorithm.c \
		list_utils1.c list_utils2.c list_utils3.c list_utils4.c)

OBJ = $(SRC:c=o)

###################################
# Bonus : checker program
###################################

NAMEB = checkers/checker

SRCB = $(addprefix srcs/, \
		checker.c parsing.c instructions.c algorithm.c \
		list_utils1.c list_utils2.c list_utils3.c list_utils4.c)

OBJB = $(SRCB:c=o)

###################################
# Methods
###################################

all: $(NAME)

$(NAME): $(OBJ)
	@echo "\033[0;32m\n\nCompiling push_swap..."
	@$(CC) $(CFLAGS) -I $(INCLUDES) -o $(NAME) $(OBJ)
	@echo "\n\033[0mDone !"

%.o: %.c
	@printf "\033[0;33mGenerating push_swap objects... %-20.20s\r" $@
	@$(CC) $(CFLAGS) -I $(INCLUDES) -c $< -o $@

clean:
	@echo "\033[0;31m\nDeleting objects..."
	@rm -f $(OBJ)
	@echo "\033[0m"

fclean:
	@echo "\033[0;31m\nDeleting objects..."
	@rm -f $(OBJ) $(OBJB)
	@echo "\nDeleting executable..."
	@rm -f $(NAME) $(NAMEB)
	@echo "\033[0m"

re: fclean all

bonus: $(OBJB)
	@echo "\033[0;32m\n\nCompiling checker..."
	@$(CC) $(CFLAGS) -I $(INCLUDES) -o $(NAMEB) $(OBJB)
	@echo "\n\033[0mDone !"

.PHONY: clean fclean re bonus
