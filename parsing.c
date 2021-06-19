#include "push_swap.h"

int	issorted(t_stack *a)
{
	int	i;
	int	flag;

	flag = 1;
	i = 0;
	while (i < a->tail)
	{
		if (a->table[i] < a->table[i + 1])
		{
			flag = 0;
		}
		i++;
	}
	return (flag);
}

int	is_number(char *s)
{
	int	i;

	i = 0;
	if (s[i] == '-')
		i++;
	while (s[i])
	{
		if (s[i] < 48 || s[i] > 57)
			return (0);
		i++;
	}
	return (1);
}

t_stack	*fill_stack(int c, char **v, int multi, char *name)
{
	t_stack	*s;
	int		i;

	s = malloc(sizeof(t_stack));
	s->table = malloc(sizeof(int) * (c - 1));
	s->tail = (c - 1) * multi;
	i = 0;
	while (i < s->tail)
	{
		if (!is_number(v[c - i - 1]))
			return (NULL);
		s->table[i] = ft_atoi(v[c - i - 1]) * multi;
		i++;
	}
	s->tail--;
	s->name = name;
	return (s);
}

int	check_stack(t_stack *a)
{
	if (!a || simplify_array(a) < 0)
		return (0);
	return (1);
}
