/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalomon <fsalomon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 16:39:59 by fsalomon          #+#    #+#             */
/*   Updated: 2024/01/31 17:12:19 by fsalomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_init_cost(t_stack **a, t_stack **b)
{
	unsigned int	size;
	unsigned int	i;

	i = 0;
	size = ft_get_stack_size(a);
	while (i < size)
	{
		(*a)->cost = ft_count_cost(*a) + ft_count_cost(*b);
		(*a) = (*a)->next;
		i++;
	}
}

int	ft_count_cost(t_stack *a, t_stack *target)
{
	unsigned int median;

	median = (ft_get_stack_size(a)/2);
	
	
}

void	ft_init_index(t_stack **a)
{
	unsigned int size;
	unsigned int i;

	i = 0;
	size = ft_get_stack_size(a);
	while (i < size)
	{
		(*a)->index = i;
		(*a) = (*a)->next;
		i++;
	}
}