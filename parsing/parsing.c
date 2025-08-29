/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalomon <fsalomon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 15:23:10 by fsalomon          #+#    #+#             */
/*   Updated: 2024/02/20 10:14:17 by fsalomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_check_char(int argc, char **argv, long *number_list)
{
	int	i;
	int	j;

	i = 0;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if ((argv[i][j] < 48 || argv[i][j] > 57) && argv[i][j] != 32
				&& argv[i][j] != 43 && argv[i][j] != 45)
			{
				free(number_list);
				return (1);
			}
			if ((argv[i][j] == 43 || argv[i][j] == 45) && j > 0)
			{
				free(number_list);
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_check_error(int argc, char **argv, long *number_list)
{
	int	i;

	i = 0;
	if (ft_check_char(argc, argv, number_list) != 0)
		return (1);
	if (ft_check_int(argc, argv, number_list) != 0)
		return (1);
	return (0);
}

t_stack	*ft_fill_list(int argc, long *number_list)
{
	t_stack	*a;
	t_stack	*new;
	int		i;

	i = 0;
	a = NULL;
	while (i < argc)
	{
		new = ft_lstnew(number_list[i]);
		if (!new)
		{
			ft_lstclear(&a);
			return (NULL);
		}
		ft_add_last_node(&a, new);
		i++;
	}
	return (a);
}

int	ft_check_create_stack(int words_nb, char **numbers, t_stack **a)
{
	long	*number_list;

	number_list = malloc(sizeof(long) * words_nb);
	if (!number_list)
		exit(ft_malloc_error(numbers, words_nb));
	if (ft_check_error(words_nb, numbers, number_list))
		return (1);
	number_list = malloc(sizeof(long) * words_nb);
	if (!number_list)
		exit(ft_malloc_error(numbers, words_nb));
	number_list = ft_fill_int_tab(words_nb, number_list, numbers);
	*a = ft_fill_list(words_nb, number_list);
	free(number_list);
	if (!(*a))
		return (-1);
	return (0);
}

char	**ft_set_args(char **argv, int argc)
{
	int		i;
	int		j;
	char	**numbers;

	i = 0;
	numbers = malloc(sizeof(char *) * argc);
	while (i < argc - 1)
	{
		j = 0;
		while (argv[i + 1][j] != 0)
			j++;
		numbers[i] = ft_calloc(sizeof(char), j + 1);
		if (!numbers[i])
		{
			ft_free_tab(numbers, argc);
		}
		while (j >= 0)
		{
			numbers[i][j] = argv[i + 1][j];
			j--;
		}
		i++;
	}
	return (numbers);
}
