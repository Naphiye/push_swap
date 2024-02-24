/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalomon <fsalomon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 14:36:35 by fsalomon          #+#    #+#             */
/*   Updated: 2024/02/14 10:39:12 by fsalomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_lstnew(long number)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->number = number;
	new->cost = 0;
	new->prev = NULL;
	new->next = NULL;
	new->target = NULL;
	new->min = 0;
	new->max = 0;
	new->index = 0;
	new->cheapest = 0;
	return (new);
}

void	ft_lstclear(t_stack **lst)
{
	t_stack	*tmp;
	t_stack	*first;

	if (!lst || !*lst)
		return ;
	first = *lst;
	tmp = NULL;
	while (tmp != first)
	{
		tmp = (*lst)->next;
		free(*lst);
		*lst = tmp;
	}
	lst = NULL;
}

void	ft_clear_target(t_stack **lst)
{
	unsigned int	i;

	i = 0;
	while (i < (ft_get_stack_size(lst)))
	{
		(*lst)->target = NULL;
		(*lst) = (*lst)->next;
		i ++;
	}
	return ;
}

unsigned int	ft_get_stack_size(t_stack **lst)
{
	t_stack			*tmp;
	unsigned int	i;

	tmp = *lst;
	i = 1;
	if (!(*lst))
		return (0);
	while (tmp->next != (*lst))
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}
