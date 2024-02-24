/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_min_max.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalomon <fsalomon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 09:02:15 by fsalomon          #+#    #+#             */
/*   Updated: 2024/02/14 10:37:40 by fsalomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_init_to_zero_min_max(t_stack **a, unsigned int lst_size)
{
	unsigned int	i;

	i = 0;
	while (i < lst_size)
	{
		(*a)->min = 0;
		(*a)->max = 0;
		(*a) = (*a)->next;
		i++;
	}
}

void	ft_init_min_and_max(t_stack **a, unsigned int lst_size)
{
	t_stack			*min;
	t_stack			*max;
	unsigned int	i;

	i = 0;
	min = *a;
	max = *a;
	while (i < lst_size)
	{
		if ((*a)->number < min->number)
			min = *a;
		else if ((*a)->number > max->number)
			max = *a;
		(*a) = (*a)->next;
		i++;
	}
	min->min = 1;
	max->max = 1;
}

int	ft_max_ra_rb(int ra, int rb)
{
	if (ra > rb)
		return (ra);
	return (rb);
}

int	ft_max_rra_rrb(int rra, int rrb)
{
	if (rra > rrb)
		return (rra);
	return (rrb);
}
