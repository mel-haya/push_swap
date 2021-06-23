#include "checker.h"

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
