#include "checker_bonus.h"

void	swap_stack(t_stack *stack_a)
{
	int	tmp;

	if (stack_a->tail < 1)
		return ;
	tmp = stack_a->table[stack_a->tail];
	stack_a->table[stack_a->tail] = stack_a->table[stack_a->tail - 1];
	stack_a->table[stack_a->tail - 1] = tmp;
}

void	push_stack(t_stack *a, t_stack *b)
{
	int	last;

	if (b->tail < 0)
		return ;
	last = b->table[b->tail];
	b->tail--;
	a->tail++;
	a->table[a->tail] = last;
}

void	rotate_stack(t_stack *a)
{
	int	last;
	int	i;

	if (a->tail < 1)
		return ;
	i = a->tail;
	last = a->table[a->tail];
	while (i > 0)
	{
		a->table[i] = a->table[i - 1];
		i--;
	}
	a->table[0] = last;
}

void	rr_stack(t_stack *a)
{
	int	first;
	int	i;

	if (a->tail < 1)
		return ;
	i = 0;
	first = a->table[0];
	while (i < a->tail)
	{
		a->table[i] = a->table[i + 1];
		i++;
	}
	a->table[a->tail] = first;
}

void	execute_action(t_stack *a, t_stack *b, char *s)
{
	int	l;

	l = ft_strlen(s);
	if (l == 2 && s[0] == 's' && (s[1] == 'a' || s[1] == 's'))
		swap_stack(a);
	if (l == 2 && s[0] == 's' && (s[1] == 'b' || s[1] == 's'))
		swap_stack(b);
	if (l == 2 && s[0] == 'p' && s[1] == 'b')
		push_stack(b, a);
	if (l == 2 && s[0] == 'p' && s[1] == 'a')
		push_stack(a, b);
	if (l == 2 && s[0] == 'r' && (s[1] == 'a' || s[1] == 'r'))
		rotate_stack(a);
	if (l == 2 && s[0] == 'r' && (s[1] == 'b' || s[1] == 'r'))
		rotate_stack(b);
	if (l == 3 && (s[2] == 'a' || s[2] == 'r'))
		rr_stack(a);
	if (l == 3 && (s[2] == 'b' || s[2] == 'r'))
		rr_stack(b);
}
