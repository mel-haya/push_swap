#include "push_swap.h"

void	sort_medium(t_stack *a, t_stack *b)
{
	while (a->tail > 2)
	{
		pop_by_index(a, get_smallest(a));
		p(b, a);
	}
	sort_small_stack(a);
	while (b->tail >= 0)
	{
		p(a, b);
	}
}

void	sort_big_stack(t_stack *a, t_stack *b)
{
	int	pos;

	push_to_b(a, b);
	while (b->tail >= 0)
	{
		pos = get_largest_pos(b);
		if (pos >= b->tail / 2)
			push_largest_left(b, a, pos);
		else if (pos < b->tail / 2)
			push_largest_right(b, a, pos);
		if (a->table[a->tail] > a->table[a->tail - 1])
			s(a, NULL);
		if (a->table[0] < a->table[1])
			rr(a, NULL);
	}
}

int	main(int c, char **v)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = fill_stack(c, v, 1, "a");
	stack_b = fill_stack(c, v, 0, "b");
	if (issorted(stack_a))
		return (0);
	if (!check_stack(stack_a))
	{
		printf("ERROR\n");
		return (0);
	}
	if (stack_a->tail < 10)
	{
		sort_medium(stack_a, stack_b);
		return (0);
	}
	sort_big_stack(stack_a, stack_b);
}
