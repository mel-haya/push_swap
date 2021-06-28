#ifndef CHECKER_H
# define CHECKER_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_stack
{
	int		*table;
	char	*name;
	int		tail;
}			t_stack;

t_stack	*fill_stack(int c, char **v, int multi, char *name);
int		issorted(t_stack *a);
int		check_stack(t_stack *a);
void	swap_stack(t_stack *stack_a);
void	push_stack(t_stack *a, t_stack *b);
void	rotate_stack(t_stack *a);
void	rr_stack(t_stack *a);
void	sort_small_stack(t_stack *a);
void	print_stack(t_stack *stack);
int		simplify_array(t_stack *s);
void	sort_big_stack(t_stack *a, t_stack *b);
void	print_stack(t_stack *stack);
void	sort_medium(t_stack *a, t_stack *b);
int		get_smallest(t_stack *a);
int		is_number(char *s);
void	pop_by_index(t_stack *a, int index);
void	s(t_stack *a, t_stack *b);
void	p(t_stack *a, t_stack *b);
void	r(t_stack *a, t_stack *b);
void	rr(t_stack *a, t_stack *b);
void	push_largest_left(t_stack *b, t_stack *a, int pos);
void	push_largest_right(t_stack *b, t_stack *a, int pos);
int		get_largest_pos(t_stack *a);
void	s(t_stack *a, t_stack *b);
void	p(t_stack *a, t_stack *b);
void	r(t_stack *a, t_stack *b);
void	rr(t_stack *a, t_stack *b);
void	push_to_b(t_stack *a, t_stack *b);
void	ft_putstr_fd(char *s, int fd);
int		ft_atoi(const char *str);
void	ft_putchar_fd(char c, int fd);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_strlen(const char *s);
void	execute_action(t_stack *a, t_stack *b, char *s);
#endif