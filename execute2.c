/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalomon <fsalomon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 16:59:48 by fsalomon          #+#    #+#             */
/*   Updated: 2024/02/17 10:31:45 by fsalomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_excute_ra_rrb(t_stack **a, t_stack **b, int ra, int rrb)
{
	int	i;

	i = 0;
	while (i < ra)
	{
		ft_rotate_a(a);
		i++;
	}
	i = 0;
	while (i < rrb)
	{
		ft_reverse_rotate_b(b);
		i++;
	}
}

void	ft_excute_rra_rb(t_stack **a, t_stack **b, int rra, int rb)
{
	int	i;

	i = 0;
	while (i < rra)
	{
		ft_reverse_rotate_a(a);
		i++;
	}
	i = 0;
	while (i < rb)
	{
		ft_rotate_b(b);
		i++;
	}
}

void	ft_execute_action_a(int size_a, int size_b, t_stack **a, t_stack **b)
{
	int		ra;
	int		rb;
	int		rra;
	int		rrb;
	t_stack	*cheapest;

	cheapest = ft_find_cheapest(a);
	ra = cheapest->index;
	rb = cheapest->target->index;
	rra = size_a - cheapest->index;
	rrb = size_b - cheapest->target->index;
	if (ft_optimise_action(ra, rb, rra, rrb) == 1)
		ft_excute_ra_rb(a, b, ra, rb);
	else if (ft_optimise_action(ra, rb, rra, rrb) == 2)
		ft_excute_rra_rrb(a, b, rra, rrb);
	else if (ft_optimise_action(ra, rb, rra, rrb) == 3)
		ft_excute_ra_rrb(a, b, ra, rrb);
	else if (ft_optimise_action(ra, rb, rra, rrb) == 4)
		ft_excute_rra_rb(a, b, rra, rb);
	return ;
}

void	ft_execute_action_b(int size_a, int size_b, t_stack **a, t_stack **b)
{
	int	ra;
	int	rra;
	int	i;

	size_b = 1;
	ra = (*b)->target->index;
	rra = size_a - (*b)->target->index;
	i = 0;
	if (ra < rra)
	{
		while (i < ra)
		{
			ft_rotate_a(a);
			i++;
		}
	}
	else
	{
		while (i < rra)
		{
			ft_reverse_rotate_a(a);
			i++;
		}
	}
	return ;
}
