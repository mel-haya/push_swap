#include "checker_bonus.h"

int	check_action(char *a)
{
	int	l;
	int	flag;

	flag = 1;
	l = ft_strlen(a);
	if (l == 2)
	{
		if ((a[0] == 's' || a[0] == 'p' || a[0] == 'r') && \
		((a[1] == 'a' || a[1] == 'b' || a[1] == a[0]) && a[1] != 'p'))
			return (1);
	}
	else if (l == 3)
	{
		if ((a[0] == 'r' && a[1] == 'r') && \
		(a[2] == 'a' || a[2] == 'b' || a[2] == 'r'))
			return (1);
	}
	return (0);
}

void	init_buffer(char *buf)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		buf[i] = 0;
		i++;
	}
}

int	read_actions(t_stack *a, t_stack *b, char *s)
{
	int		l;
	int		i;
	char	r;

	l = 1;
	while (l != 0)
	{
		i = 0;
		init_buffer(s);
		while (s[i] != '\n' && l != 0)
		{
			l = read(0, &r, 1);
			if (r == '\n' || l == 0)
				break ;
			s[i] = r;
			i++;
		}
		s[i] = 0;
		if ((i < 4 && check_action(s)) || l == 0)
			execute_action(a, b, s);
		else
			return (0);
	}
	return (1);
}

void	free_stacks(t_stack *a, t_stack *b, char *buf)
{
	free(a->table);
	free(b->table);
	free(a);
	free(b);
	free(buf);
}

int	main(int c, char **v)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	*s;

	s = (char *) malloc(4 * sizeof(char));
	if (!s || c == 1)
		return (0);
	stack_a = fill_stack(c, v, 1, "a");
	stack_b = fill_stack(c, v, 0, "b");
	if (!stack_b || !stack_a || !check_stack(stack_a) || \
	!read_actions(stack_a, stack_b, s))
	{
		ft_putstr_fd("ERROR\n", 1);
		return (0);
	}
	if (issorted(stack_a) && stack_b->tail == -1)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	free_stacks(stack_a, stack_b, s);
}
