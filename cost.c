/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalomon <fsalomon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 10:02:05 by fsalomon          #+#    #+#             */
/*   Updated: 2024/02/17 14:37:23 by fsalomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_return_the_lowest(int max_ra_rb, int max_rra_rrb, int min_sep)
{
	if (max_ra_rb <= max_rra_rrb && max_ra_rb < min_sep)
		return (max_ra_rb);
	if (max_rra_rrb <= max_ra_rb && max_rra_rrb < min_sep)
		return (max_rra_rrb);
	return (min_sep);
}

int	ft_optimise_cost(int ra, int rb, int rra, int rrb)
{
	int	cost;
	int	max_ra_rb;
	int	max_rra_rrb;
	int	min_sep;

	cost = 0;
	max_ra_rb = ft_max_ra_rb(ra, rb);
	max_rra_rrb = ft_max_rra_rrb(rra, rrb);
	if (ra + rrb < rra + rb)
		min_sep = ra + rrb;
	else
		min_sep = rra + rb;
	cost = ft_return_the_lowest(max_ra_rb, max_rra_rrb, min_sep);
	return (cost);
}

int	ft_count_cost_a(t_stack *a, unsigned int size_a, unsigned int size_b)
{
	int	ra;
	int	rb;
	int	rra;
	int	rrb;

	ra = a->index;
	rb = a->target->index;
	rra = size_a - a->index;
	rrb = size_b - a->target->index;
	return (ft_optimise_cost(ra, rb, rra, rrb));
}

int	ft_count_cost_b(t_stack *b, unsigned int size_a, unsigned int size_b)
{
	int	ra;
	int	rb;
	int	rra;
	int	rrb;

	rb = b->index;
	ra = b->target->index;
	rrb = size_b - b->index;
	rra = size_a - b->target->index;
	return (ft_optimise_cost(ra, rb, rra, rrb));
}
