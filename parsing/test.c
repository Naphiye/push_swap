/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalomon <fsalomon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:18:36 by fsalomon          #+#    #+#             */
/*   Updated: 2024/01/31 16:33:51 by fsalomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_test_print(t_stack *a)
{
	unsigned int	i;
	unsigned int	size;

	i = 0;
	size = ft_get_stack_size(&a);
	while (i < size)
	{
		printf("number = %ld \n", a->number);
		printf("cout = %d \n", a->cost);
		printf("adress next %p \n", a->next);
		if (a->min)
			printf("THE MINIMUM \n");
		if (a->max)
			printf("THE MAXIMUM \n");
		printf("\n");
		a = a->next;
		i++;
	}
	return ;
}

void	ft_print_target(t_stack *a)
{
	unsigned int	i;
	unsigned int	size;

	i = 0;
	size = ft_get_stack_size(&a);
	while (i < size)
	{
		printf("la valeur %ld target %ld \n", a->number, a->target->number);
		a = a->next;
		i++;
	}
	return ;
}

void	ft_print_argv(char **numbers)
{
	int	i;

	i = 0;
	while (numbers[i] != 0)
	{
		printf("%s\n", numbers[i]);
		i ++;
	}
}
