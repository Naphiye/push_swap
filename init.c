/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalomon <fsalomon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 09:57:24 by fsalomon          #+#    #+#             */
/*   Updated: 2024/02/14 13:25:31 by fsalomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_init_cost_a(t_stack **a)
{
	unsigned int	size_a;
	unsigned int	size_b;
	unsigned int	i;

	i = 0;
	size_a = ft_get_stack_size(a);
	size_b = ft_get_stack_size(&(*a)->target);
	while (i < size_a)
	{
		(*a)->cost = ft_count_cost_a(*a, size_a, size_b);
		(*a) = (*a)->next;
		i++;
	}
	return ;
}

void	ft_init_cost_b(t_stack **b)
{
	unsigned int	size_a;
	unsigned int	size_b;
	unsigned int	i;

	i = 0;
	size_b = ft_get_stack_size(b);
	size_a = ft_get_stack_size(&(*b)->target);
	while (i < size_b)
	{
		(*b)->cost = ft_count_cost_b(*b, size_a, size_b);
		(*b) = (*b)->next;
		i++;
	}
	return ;
}

void	ft_init_index(t_stack **lst)
{
	unsigned int	i;
	unsigned int	size;

	i = 0;
	size = ft_get_stack_size(lst);
	while (i < size)
	{
		(*lst)->index = i;
		i++;
		(*lst) = (*lst)->next;
	}
	return ;
}

void	ft_init_target(t_stack **a, t_stack **b)
{
	t_stack			*target;
	unsigned int	i;
	int				target_find;

	i = 0;
	target = *b;
	target_find = 0;
	while (i < ft_get_stack_size(a))
	{
		target_find = ft_closest_min(a, b, &target);
		if (!target_find)
			target = ft_find_max(b, ft_get_stack_size(b));
		(*a)->target = target;
		(*a) = (*a)->next;
		i++;
	}
}

void	ft_init_target_b(t_stack **a, t_stack **b)
{
	t_stack			*target;
	unsigned int	i;
	int				target_find;

	i = 0;
	target = *a;
	target_find = 0;
	while (i < ft_get_stack_size(b))
	{
		target_find = ft_closest_max(b, a, &target);
		if (!target_find)
			target = ft_find_min(a, ft_get_stack_size(a));
		(*b)->target = target;
		(*b) = (*b)->next;
		i++;
	}
}
