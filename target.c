/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalomon <fsalomon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 15:32:43 by fsalomon          #+#    #+#             */
/*   Updated: 2024/02/20 13:49:06 by fsalomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_closest_max(t_stack **a, t_stack **b, t_stack **target)
{
	unsigned int	j;
	int				target_find;

	j = 0;
	target_find = 0;
	while (j < ft_get_stack_size(b))
	{
		if (target_find)
		{
			if ((*b)->number > (*a)->number && (*target)->number > (*b)->number)
				(*target) = (*b);
		}
		else
		{
			if ((*b)->number > (*a)->number)
			{
				(*target) = (*b);
				target_find = 1;
			}
		}
		(*b) = (*b)->next;
		j++;
	}
	return (target_find);
}

int	ft_closest_min(t_stack **a, t_stack **b, t_stack **target)
{
	unsigned int	j;
	int				target_find;

	j = 0;
	target_find = 0;
	while (j < ft_get_stack_size(b))
	{
		if (target_find)
		{
			if ((*b)->number < (*a)->number && (*target)->number < (*b)->number)
				(*target) = (*b);
		}
		else
		{
			if ((*b)->number < (*a)->number)
			{
				(*target) = (*b);
				target_find = 1;
			}
		}
		(*b) = (*b)->next;
		j++;
	}
	return (target_find);
}

t_stack	*ft_find_max(t_stack **lst, unsigned int size_lst)
{
	unsigned int	j;
	t_stack			*target;

	j = 0;
	ft_init_min_and_max(lst, size_lst);
	while (j < size_lst)
	{
		if ((*lst)->max)
			target = (*lst);
		(*lst) = (*lst)->next;
		j++;
	}
	return (target);
}

t_stack	*ft_find_min(t_stack **lst, unsigned int size_lst)
{
	unsigned int	j;
	t_stack			*target;

	j = 0;
	ft_init_to_zero_min_max(lst, size_lst);
	ft_init_min_and_max(lst, size_lst);
	while (j < size_lst)
	{
		if ((*lst)->min)
			target = (*lst);
		(*lst) = (*lst)->next;
		j++;
	}
	return (target);
}
