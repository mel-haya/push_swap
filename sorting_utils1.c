#include "push_swap.h"

int	get_largest_pos(t_stack *a)
{
	int	i;
	int	largest;

	i = 0;
	largest = 0;
	while (i <= a->tail)
	{
		if (a->table[i] > a->table[largest])
			largest = i;
		i++;
	}
	return (largest);
}

void	push_largest_left(t_stack *b, t_stack *a, int pos)
{
	int	largest;

	largest = b->table[pos];
	while (1)
	{
		if (b->table[b->tail] == largest)
		{
			p(a, b);
			break ;
		}
		else if (b->table[b->tail] == largest - 1)
			p(a, b);
		else if (b->table[b->tail] == largest - 2)
		{
			p(a, b);
			r(a, NULL);
		}
		else
			r(b, NULL);
	}
}

void	push_largest_right(t_stack *b, t_stack *a, int pos)
{
	int	largest;

	largest = b->table[pos];
	while (1)
	{
		if (b->table[b->tail] == largest)
		{
			p(a, b);
			break ;
		}
		else if (b->table[b->tail] == largest - 1)
			p(a, b);
		else if (b->table[b->tail] == largest - 2)
		{
			p(a, b);
			r(a, NULL);
		}
		else
		{
			rr(b, NULL);
		}
	}
}

void	push_to_b_norm(t_stack *a, t_stack *b, int mid, int s)
{
	int	i;
	int	size;

	i = 0;
	size = a->tail;
	while (i <= size && b->tail < (s * 2) - 2)
	{
		if (a->table[a->tail] >= (mid - s) && a->table[a->tail] < mid)
		{
			p(b, a);
			r(b, NULL);
		}
		else if (a->table[a->tail] <= (mid + s) && a->table[a->tail] >= mid)
			p(b, a);
		else
			r(a, NULL);
		i++;
	}
}

void	push_to_b(t_stack *a, t_stack *b)
{
	int	i;
	int	s;
	int	multi;
	int	size;
	int	midpoint;

	midpoint = a->tail / 2;
	if (a->tail > 150)
		s = a->tail / 18;
	else
		s = a->tail / 6;
	multi = 1;
	while (a->tail >= 0)
	{
		i = 0;
		size = a->tail;
		push_to_b_norm(a, b, midpoint, s * multi);
		multi++;
	}
}
