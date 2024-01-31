/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalomon <fsalomon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 13:20:54 by fsalomon          #+#    #+#             */
/*   Updated: 2024/01/31 15:40:27 by fsalomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_three_b(t_stack **b)
{
	t_stack	*first;
	t_stack	*last;

	first = *b;
	last = first->prev;
	if (last->min && first->next->max)
		ft_swap_b(b);
	else if (first->min && first->next->max)
		ft_rotate_b(b);
	else if (last->max && first->next->min)
		ft_reverse_rotate_b(b);
	else if (first->min && last->max)
	{
		ft_rotate_b(b);
		ft_swap_b(b);
	}
	else if (first->max && first->next->min)
	{
		ft_reverse_rotate_b(b);
		ft_swap_b(b);
	}
}
