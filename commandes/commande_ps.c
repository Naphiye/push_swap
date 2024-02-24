/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commande_ps.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalomon <fsalomon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 14:45:07 by fsalomon          #+#    #+#             */
/*   Updated: 2024/02/14 10:39:36 by fsalomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_swap_a(t_stack **a)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	if ((*a)->next == *a)
		return ;
	tmp = ft_remove_first_node(a);
	tmp2 = ft_remove_first_node(a);
	ft_add_first_node(a, tmp);
	ft_add_first_node(a, tmp2);
	write(1, "sa\n", 3);
}

void	ft_swap_b(t_stack **b)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	if ((*b)->next == *b)
		return ;
	tmp = ft_remove_first_node(b);
	tmp2 = ft_remove_first_node(b);
	ft_add_first_node(b, tmp);
	ft_add_first_node(b, tmp2);
	write(1, "sb\n", 3);
}

void	ft_swap_ab(t_stack **a, t_stack **b)
{
	ft_swap_a(a);
	ft_swap_b(b);
	write(1, "ss\n", 3);
}

void	ft_push_a(t_stack **src, t_stack **dest)
{
	t_stack	*to_push;
	t_stack	*tmp;

	to_push = ft_remove_first_node(src);
	tmp = to_push;
	to_push = ft_lstnew(to_push->number);
	ft_add_first_node(dest, to_push);
	free(tmp);
	write(1, "pa\n", 3);
}

void	ft_push_b(t_stack **src, t_stack **dest)
{
	t_stack	*to_push;
	t_stack	*tmp;

	to_push = ft_remove_first_node(src);
	tmp = to_push;
	to_push = ft_lstnew(to_push->number);
	ft_add_first_node(dest, to_push);
	free(tmp);
	write(1, "pb\n", 3);
}
