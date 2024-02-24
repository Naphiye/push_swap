/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalomon <fsalomon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 16:20:43 by fsalomon          #+#    #+#             */
/*   Updated: 2024/02/22 16:55:16 by fsalomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

long	ft_atol(const char *nptr)
{
	int		sign;
	long	total;
	int		i;

	sign = 1;
	total = 0;
	i = 0;
	while ((nptr[i] > 8 && nptr[i] < 14) || nptr[i] == 32)
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
		{
			sign = -sign;
		}
		i++;
	}
	while (nptr[i] != 0 && nptr[i] > 47 && nptr[i] < 58)
	{
		total = total * 10 + (nptr[i] - '0');
		i++;
	}
	total *= sign;
	return (total);
}

long	*ft_fill_int_tab(int argc, long *number_list, char **argv)
{
	int	i;

	i = 0;
	while (i < argc)
	{
		number_list[i] = ft_atol(argv[i]);
		i++;
	}
	return (number_list);
}

static int	ft_check_doublon(int argc, long *number_list)
{
	int	i;
	int	j;
	int	doublon;

	i = 0;
	doublon = 0;
	while (i < argc - 1)
	{
		j = i + 1;
		if (doublon)
			break ;
		while (j < argc)
		{
			if (number_list[i] == number_list[j])
			{
				doublon = 1;
				break ;
			}
			j++;
		}
		i++;
	} 
	return (doublon);
}

static int	ft_check_max(int argc, long *number_list)
{
	int	i;

	i = 0;
	while (i < argc)
	{
		if (number_list[i] > 2147483647 || number_list[i] < -2147483648)
			return (1);
		i++;
	}
	return (0);
}

int	ft_check_int(int argc, char **argv, long *number_list)
{
	int		doublon;
	int		max;
	int		i;
	char	*tmp;

	i = 0;
	while (i < argc)
	{
		tmp = ft_itoa(ft_atol(argv[i]));
		if (!tmp)
			exit(ft_malloc_error(argv, argc));
		if (ft_strncmp(tmp, argv[i], ft_strlen(tmp)))
		{
			free(tmp);
			free(number_list);
			return (1);
		}
		free(tmp);
		i++;
	}
	number_list = ft_fill_int_tab(argc, number_list, argv);
	doublon = ft_check_doublon(argc, number_list);
	max = ft_check_max(argc, number_list);
	free(number_list);
	return (doublon + max);
}
