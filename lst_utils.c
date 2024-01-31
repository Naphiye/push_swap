/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalomon <fsalomon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 14:36:35 by fsalomon          #+#    #+#             */
/*   Updated: 2024/01/31 16:59:21 by fsalomon         ###   ########.fr       */
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
