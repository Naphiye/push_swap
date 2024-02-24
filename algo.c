/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalomon <fsalomon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 13:20:54 by fsalomon          #+#    #+#             */
/*   Updated: 2024/02/15 17:08:46 by fsalomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_find_cheapest(t_stack **lst)
{
	int		size;
	int		i;
	t_stack	*cheapest;

	size = ft_get_stack_size(lst);
	i = 0;
	cheapest = *lst;
	while (i < size)
	{
		if ((*lst)->cost < cheapest->cost)
			cheapest = *lst;
		i++;
		(*lst) = (*lst)->next;
	}
	return (cheapest);
}

int	ft_return_the_lowest_combo(int max_ra_rb, int max_rra_rrb, int min_sep,
		int flag)
{
	if (max_ra_rb <= max_rra_rrb && max_ra_rb < min_sep)
		return (1);
	else if (max_rra_rrb <= max_ra_rb && max_rra_rrb < min_sep)
		return (2);
	else if (flag)
		return (3);
	else
		return (4);
}

int	ft_optimise_action(int ra, int rb, int rra, int rrb)
{
	int	combo;
	int	max_ra_rb;
	int	max_rra_rrb;
	int	min_sep;
	int	flag;

	combo = 0;
	flag = 0;
	max_ra_rb = ft_max_ra_rb(ra, rb);
	max_rra_rrb = ft_max_rra_rrb(rra, rrb);
	if (ra + rrb < rra + rb)
	{
		min_sep = ra + rrb;
		flag = 1;
	}
	else
		min_sep = rra + rb;
	combo = ft_return_the_lowest_combo(max_ra_rb, max_rra_rrb, min_sep, flag);
	return (combo);
}

void	ft_push_the_cheapest_b(t_stack **a, t_stack **b)
{
	int	size_a;
	int	size_b;
	int	i;

	i = 0;
	size_a = ft_get_stack_size(a);
	size_b = ft_get_stack_size(b);
	ft_execute_action_a(size_a, size_b, a, b);
	ft_push_b(a, b);
	return ;
}

void	ft_push_the_cheapest_a(t_stack **a, t_stack **b)
{
	int	size_a;
	int	size_b;
	int	i;

	i = 0;
	size_a = ft_get_stack_size(a);
	size_b = ft_get_stack_size(b);
	ft_execute_action_b(size_a, size_b, a, b);
	ft_push_a(b, a);
	return ;
}
