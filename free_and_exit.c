/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_and_exit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalomon <fsalomon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 11:46:44 by fsalomon          #+#    #+#             */
/*   Updated: 2024/02/20 10:09:27 by fsalomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_tab(char **number_list, int argc)
{
	int	i;

	i = 0;
	while (i < argc)
	{
		free(number_list[i]);
		i ++;
	}
	free(number_list);
	return ;
}

int	ft_malloc_error(char **numbers, int argc)
{
	if (numbers)
		ft_free_tab(numbers, argc);
	write(1, "malloc error\n", 13);
	return (-1);
}
