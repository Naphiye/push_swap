/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_manip.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalomon <fsalomon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 14:07:57 by fsalomon          #+#    #+#             */
/*   Updated: 2024/01/30 10:46:44 by fsalomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_add_last_node(t_stack **lst, t_stack *new_node)
{
	if (!(*lst))
	{
		new_node->next = new_node;
		new_node->prev = new_node;
		*lst = new_node;
		return ;
	}
	new_node->next = (*lst);
	new_node->prev = (*lst)->prev;
	(*lst)->prev->next = new_node;
	(*lst)->prev = new_node;
}

void	ft_add_first_node(t_stack **lst, t_stack *new_node)
{
	if (!(*lst))
	{
		new_node->next = new_node;
		new_node->prev = new_node;
		*lst = new_node;
		return ;
	}
	new_node->next = (*lst);
	new_node->prev = (*lst)->prev;
	(*lst)->prev->next = new_node;
	(*lst)->prev = new_node;
	*lst = new_node;
}

t_stack	*ft_remove_last_node(t_stack **lst)
{
	t_stack	*to_remove;

	to_remove = (*lst)->prev;
	if (to_remove->next == to_remove && to_remove->prev == to_remove)
	{
		*lst = NULL;
		return (to_remove);
	}
	(*lst)->prev = to_remove->prev;
	(*lst)->prev->next = to_remove->next;
	to_remove->prev = NULL;
	to_remove->next = NULL;
	return (to_remove);
}

t_stack	*ft_remove_first_node(t_stack **lst)
{
	t_stack	*to_remove;

	to_remove = *lst;
	if (to_remove->next == to_remove && to_remove->prev == to_remove)
	{
		*lst = NULL;
		return (to_remove);
	}
	(*lst)->prev->next = (*lst)->next;
	(*lst)->next->prev = (*lst)->prev;
	*lst = (*lst)->next;
	to_remove->prev = NULL;
	to_remove->next = NULL;
	return (to_remove);
}
