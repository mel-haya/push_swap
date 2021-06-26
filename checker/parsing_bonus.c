#include "checker.h"

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
	if (s[i] == '-' || s[i] == '+')
		i++;
	while (s[i])
	{
		if (s[i] < 48 || s[i] > 57)
			return (0);
		i++;
	}
	return (1);
}

t_stack	*init_stack(int c, int multi, char *name)
{
	t_stack	*s;

	s = malloc(sizeof(t_stack));
	if (!s)
		return (NULL);
	s->table = malloc(sizeof(int) * (c - 1));
	if (!s->table)
		return (NULL);
	s->tail = (c - 1) * multi;
	s->name = name;
	return (s);
}

t_stack	*fill_stack(int c, char **v, int multi, char *name)
{
	t_stack	*s;
	int		i;

	s = init_stack(c, multi, name);
	i = 0;
	if (!s)
		return (NULL);
	while (i < s->tail)
	{
		if (is_number(v[c - i - 1]))
		{
			if (!ft_strcmp(v[c - i - 1], "-1"))
				s->table[i] = -1;
			else
			{
				s->table[i] = ft_atoi(v[c - i - 1]) * multi;
				if (s->table[i] == -1)
					return (NULL);
			}
		}
		else
			return (NULL);
		i++;
	}
	s->tail--;
	return (s);
}

int	check_stack(t_stack *a)
{
	if (!a || simplify_array(a) < 0)
		return (0);
	return (1);
}
