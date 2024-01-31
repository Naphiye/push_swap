/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commande_ps.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalomon <fsalomon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 14:45:07 by fsalomon          #+#    #+#             */
/*   Updated: 2024/01/31 13:38:52 by fsalomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_swap_a(t_stack **a)
{
	t_stack	*tmp;

	tmp = (*a);
	(*a)->prev->next = (*a)->next;
	(*a) = (*a)->next;
	tmp->prev = (*a);
	tmp->next = (*a)->next;
	(*a)->next = tmp;
	write(1, "sa\n", 3);
}

void	ft_swap_b(t_stack **b)
{
	t_stack	*tmp;

	tmp = (*b);
	(*b)->prev->next = (*b)->next;
	(*b) = (*b)->next;
	tmp->prev = (*b);
	tmp->next = (*b)->next;
	(*b)->next = tmp;
	write(1, "sb\n", 3);
}

void	ft_swap_ab(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	tmp = (*a);
	(*a)->prev->next = (*a)->next;
	(*a) = (*a)->next;
	tmp->prev = (*a);
	tmp->next = (*a)->next;
	(*a)->next = tmp;
	tmp = (*b);
	(*b)->prev->next = (*b)->next;
	(*b) = (*b)->next;
	tmp->prev = (*b);
	tmp->next = (*b)->next;
	(*b)->next = tmp;
	write(1, "ss\n", 3);
}

void	ft_push_b(t_stack **src, t_stack **dest)
{
	t_stack	*to_push;

	to_push = ft_remove_first_node(src);
	to_push = ft_lstnew(to_push->number);
	ft_add_first_node(dest, to_push);
	write(1, "pb\n", 3);
}

void	ft_push_a(t_stack **src, t_stack **dest)
{
	t_stack	*to_push;

	to_push = ft_remove_first_node(src);
	to_push = ft_lstnew(to_push->number);
	ft_add_first_node(dest, to_push);
	write(1, "pa\n", 3);
}
