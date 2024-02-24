/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalomon <fsalomon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 15:45:51 by fsalomon          #+#    #+#             */
/*   Updated: 2024/02/14 15:03:22 by fsalomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_input_three(t_stack **a)
{
	ft_init_min_and_max(a, ft_get_stack_size(a));
	if (ft_get_stack_size(a) == 2)
	{
		if ((*a)->max)
			ft_swap_a(a);
	}
	else
		ft_sort_three_a(a);
}

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

void	ft_sort_three_a(t_stack **a)
{
	t_stack	*first;
	t_stack	*last;

	first = *a;
	last = first->prev;
	if (last->max && first->next->min)
		ft_swap_a(a);
	else if (first->max && first->next->min)
		ft_rotate_a(a);
	else if (last->min && first->next->max)
		ft_reverse_rotate_a(a);
	else if (first->max && last->min)
	{
		ft_rotate_a(a);
		ft_swap_a(a);
	}
	else if (first->min && first->next->max)
	{
		ft_reverse_rotate_a(a);
		ft_swap_a(a);
	}
}
