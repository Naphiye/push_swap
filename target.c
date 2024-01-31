/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalomon <fsalomon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 15:32:43 by fsalomon          #+#    #+#             */
/*   Updated: 2024/01/31 16:34:22 by fsalomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

t_stack	*ft_find_max(t_stack **b, unsigned int size_b)
{
	unsigned int	j;
	t_stack			*target;

	j = 0;
	ft_init_min_and_max(b, size_b);
	while (j < size_b)
	{
		if ((*b)->max)
			target = (*b);
		(*b) = (*b)->next;
		j++;
	}
	return (target);
}

t_stack	*ft_find_min(t_stack **b, unsigned int size_b)
{
	unsigned int	j;
	t_stack			*target;

	j = 0;
	ft_init_min_and_max(b, size_b);
	while (j < size_b)
	{
		if ((*b)->min)
			target = (*b);
		(*b) = (*b)->next;
		j++;
	}
	return (target);
}

int	ft_closest_max(t_stack **a, t_stack **b, t_stack **target)
{
	unsigned int	j;
	int				target_find;

	j = 0;
	target_find = 0;
	while (j < ft_get_stack_size(b))
	{
		if ((*b)->number > (*a)->number && (*target)->number > (*b)->number)
		{
			(*target) = (*b);
			target_find = 1;
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
