#include "push_swap.h"

void	pop_by_index(t_stack *a, int index)
{
	int	times;
	int	i;

	i = 0;
	if (index <= a->tail / 2)
		times = index;
	else
		times = a->tail - index - 1;
	while (i <= times)
	{
		if (index <= a->tail / 2)
			rr(a, NULL);
		else
			r(a, NULL);
		i++;
	}
}

int	get_smallest(t_stack *a)
{
	int	i;
	int	smallest;

	smallest = 0;
	i = 0;
	while (i <= a->tail)
	{
		if (a->table[i] < a->table[smallest])
			smallest = i;
		i++;
	}
	return (smallest);
}

int	get_pos(t_stack *s, int n)
{
	int	pos;
	int	i;
	int	occurrence;

	i = 0;
	pos = 0;
	occurrence = 0;
	while (i <= s->tail)
	{
		if (n > s->table[i])
			pos++;
		if (n == s->table[i])
			occurrence++;
		i++;
	}
	if (occurrence > 1)
		return (-1);
	return (pos);
}

int	simplify_array(t_stack *s)
{
	int	i;
	int	*new;

	new = malloc((s->tail + 1) * sizeof(int));
	i = 0;
	while (i <= s->tail)
	{
		new[i] = get_pos(s, s->table[i]);
		if (new[i] < 0)
			return (-1);
		i++;
	}
	free(s->table);
	s->table = new;
	return (0);
}

void	sort_small_stack(t_stack *a)
{
	int	*table;

	table = a->table;
	if (a->tail == 1)
	{
		s(a, NULL);
		return ;
	}
	if (table[2] > table[1] && table[2] > table[0])
		r(a, NULL);
	else if (table[1] > table[2] && table[1] > table[0])
		rr(a, NULL);
	if (table[2] > table[1])
		s(a, NULL);
}
