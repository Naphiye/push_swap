/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commande_rotate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalomon <fsalomon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 11:33:56 by fsalomon          #+#    #+#             */
/*   Updated: 2024/01/30 13:42:37 by fsalomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_rotate_a(t_stack **a)
{
	*a = (*a)->next;
	write(1, "ra\n", 3);
}

void	ft_rotate_b(t_stack **b)
{
	*b = (*b)->next;
	write(1, "rb\n", 3);
}

void	ft_rotate_ab(t_stack **a, t_stack **b)
{
	*a = (*a)->next;
	*b = (*b)->next;
	write(1, "rr\n", 3);
}
