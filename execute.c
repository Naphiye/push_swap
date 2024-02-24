/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalomon <fsalomon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 15:31:36 by fsalomon          #+#    #+#             */
/*   Updated: 2024/02/14 08:50:17 by fsalomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ra_max(t_stack **a, t_stack **b, int ra, int rb)
{
	int	i;

	i = 0;
	while (i < rb)
	{
		ft_rotate_ab(a, b);
		i++;
	}
	while (i < ra)
	{
		ft_rotate_a(a);
		i++;
	}
}

void	ft_rra_max(t_stack **a, t_stack **b, int rra, int rrb)
{
	int	i;

	i = 0;
	while (i < rrb)
	{
		ft_reverse_rotate_ab(a, b);
		i++;
	}
	while (i < rra)
	{
		ft_reverse_rotate_a(a);
		i++;
	}
}

void	ft_excute_ra_rb(t_stack **a, t_stack **b, int ra, int rb)
{
	int	i;

	i = 0;
	if (ra > rb)
		ft_ra_max(a, b, ra, rb);
	else
	{
		while (i < ra)
		{
			ft_rotate_ab(a, b);
			i++;
		}
		while (i < rb)
		{
			ft_rotate_b(b);
			i++;
		}
	}
}

void	ft_excute_rra_rrb(t_stack **a, t_stack **b, int rra, int rrb)
{
	int	i;

	i = 0;
	if (rra > rrb)
	{
		ft_rra_max(a, b, rra, rrb);
	}
	else
	{
		while (i < rra)
		{
			ft_reverse_rotate_ab(a, b);
			i++;
		}
		while (i < rrb)
		{
			ft_reverse_rotate_b(b);
			i++;
		}
	}
}
