#include "push_swap.h"

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
