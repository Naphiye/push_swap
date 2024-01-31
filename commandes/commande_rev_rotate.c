/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commande_rev_rotate.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalomon <fsalomon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 13:07:01 by fsalomon          #+#    #+#             */
/*   Updated: 2024/01/30 13:42:34 by fsalomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_reverse_rotate_a(t_stack **a)
{
	*a = (*a)->prev;
	write(1, "rra\n", 4);
}

void	ft_reverse_rotate_b(t_stack **b)
{
	*b = (*b)->prev;
	write(1, "rrb\n", 4);
}

void	ft_reverse_rotate_ab(t_stack **a, t_stack **b)
{
	*a = (*a)->prev;
	*b = (*b)->prev;
	write(1, "rrr\n", 4);
}
