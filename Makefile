
# -*- Makefile -*-

NAME = push_swap
BONUS = checker
LFT = libft/libft.a
FLAGS = -Wall -Werror -Wextra
SRC = push_swap.c sorting_utils.c sorting_utils1.c actions.c actions1.c parsing.c
BONUS_SRC = actions_bonus.c checker_bonus.c parsing_bonus.c sorting_utils_bonus.c
O = $(SRC:.c=.o)

all: $(NAME)

clean:
	$(MAKE) -C libft/ fclean

fclean: clean
	rm $(NAME)
	rm $(BONUS)

re: fclean re

$(NAME):
	$(MAKE) -C libft/
	gcc $(SRC) $(LFT) $(FLAGS) -o $(NAME)

bonus: 
	$(MAKE) -C libft/
	gcc $(BONUS_SRC) libft/*.o $(FLAGS) -o $(BONUS)



