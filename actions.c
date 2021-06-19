#include "push_swap.h"

void	s(t_stack *a, t_stack *b)
{
	swap_stack(a);
	if (b)
	{
		swap_stack(b);
		ft_putstr_fd("ss\n", 1);
		return ;
	}
	ft_putstr_fd("s", 1);
	ft_putstr_fd(a->name, 1);
	ft_putstr_fd("\n", 1);
}

void	p(t_stack *a, t_stack *b)
{
	push_stack(a, b);
	ft_putstr_fd("p", 1);
	ft_putstr_fd(a->name, 1);
	ft_putstr_fd("\n", 1);
}

void	r(t_stack *a, t_stack *b)
{
	rotate_stack(a);
	if (b)
	{
		rotate_stack(b);
		ft_putstr_fd("rr\n", 1);
		return ;
	}
	ft_putstr_fd("r", 1);
	ft_putstr_fd(a->name, 1);
	ft_putstr_fd("\n", 1);
}

void	rr(t_stack *a, t_stack *b)
{
	rr_stack(a);
	if (b)
	{
		rr_stack(b);
		ft_putstr_fd("rrr\n", 1);
		return ;
	}
	ft_putstr_fd("rr", 1);
	ft_putstr_fd(a->name, 1);
	ft_putstr_fd("\n", 1);
}
