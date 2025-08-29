/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_part.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalomon <fsalomon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 15:16:24 by fsalomon          #+#    #+#             */
/*   Updated: 2024/02/20 13:49:19 by fsalomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_final_rotation(t_stack **a, t_stack *head)
{
	int	i;
	int	rotation_final;

	i = 0;
	if (head->index <= (ft_get_stack_size(a) - head->index))
	{
		rotation_final = head->index;
		while (i < rotation_final)
		{
			ft_rotate_a(a);
			i++;
		}
	}
	else
	{
		rotation_final = ft_get_stack_size(a) - head->index;
		while (i < rotation_final)
		{
			ft_reverse_rotate_a(a);
			i++;
		}
	}
}

void	ft_sort_final(t_stack **a)
{
	t_stack	*head;

	ft_init_index(a);
	head = ft_find_min(a, ft_get_stack_size(a));
	if (head->index == 0)
		return ;
	ft_final_rotation(a, head);
	return ;
}

void	ft_final_clear(t_stack **a, t_stack **b)
{
	ft_clear_target(a);
	ft_lstclear(a);
	ft_lstclear(b);
	return ;
}
