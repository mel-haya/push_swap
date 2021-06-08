

NAME = libft.a

all:$(NAME)
	gcc push_swap.c actions.c libft/libft.a
	
$(NAME): 
	$(MAKE) -C libft/
