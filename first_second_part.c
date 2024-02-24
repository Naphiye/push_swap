/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_second_part.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalomon <fsalomon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 15:21:58 by fsalomon          #+#    #+#             */
/*   Updated: 2024/02/17 15:27:05 by fsalomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_init_all(t_stack **a, t_stack **b, unsigned int size_a,
		unsigned int size_b)
{
	ft_init_to_zero_min_max(a, size_a);
	ft_init_to_zero_min_max(b, size_b);
	ft_init_min_and_max(a, size_a);
	ft_init_min_and_max(b, size_b);
	ft_init_index(a);
	ft_init_index(b);
	ft_init_target(a, b);
	ft_init_cost_a(a);
}

void	ft_sort_first_part(t_stack **a, t_stack **b)
{
	unsigned int	size_a;
	unsigned int	size_b;

	ft_push_b(a, b);
	ft_push_b(a, b);
	size_a = ft_get_stack_size(a);
	size_b = ft_get_stack_size(b);
	ft_init_min_and_max(b, size_b);
	ft_init_min_and_max(a, size_a);
	while (size_a > 3)
	{
		ft_init_all(a, b, size_a, size_b);
		ft_push_the_cheapest_b(a, b);
		size_a = ft_get_stack_size(a);
		size_b = ft_get_stack_size(b);
		if (ft_check_if_already_sorted(a))
			break ;
	}
	return ;
}

void	ft_sort_second_part(t_stack **a, t_stack **b)
{
	unsigned int	size_a;
	unsigned int	size_b;

	size_a = ft_get_stack_size(a);
	size_b = ft_get_stack_size(b);
	ft_init_min_and_max(a, size_a);
	if (size_a > 1)
		ft_sort_three_a(a);
	while (size_b >= 1)
	{
		ft_init_to_zero_min_max(a, size_a);
		ft_init_to_zero_min_max(b, size_b);
		ft_init_min_and_max(a, size_a);
		ft_init_min_and_max(b, size_b);
		ft_init_index(a);
		ft_init_index(b);
		ft_init_target_b(a, b);
		ft_init_cost_b(b);
		ft_push_the_cheapest_a(a, b);
		size_a = ft_get_stack_size(a);
		size_b = ft_get_stack_size(b);
	}
	return ;
}
