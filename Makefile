

NAME = libft.a

all:$(NAME)
	gcc push_swap.c actions.c libft/libft.a -g -o push_swap
	
$(NAME): 
	$(MAKE) -C libft/
