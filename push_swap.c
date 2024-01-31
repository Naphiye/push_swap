/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalomon <fsalomon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 12:18:44 by fsalomon          #+#    #+#             */
/*   Updated: 2024/01/31 16:51:53 by fsalomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_parsing(int argc, char **argv, t_stack **a)
{
	char	**numbers;
	int		words_nb;

	if (argc == 1)
		return (-1);
	if (argc == 2)
	{
		numbers = ft_split(argv[1], 32);
		words_nb = count_words(0, argv[1], 32);
	}
	else
	{
		numbers = ft_set_args(argv, argc);
		words_nb = argc - 1;
	}
	if (!numbers)
		exit(ft_malloc_error(NULL, 0));
	if (ft_check_create_stack(words_nb, numbers, a))
	{
		if (ft_check_create_stack(words_nb, numbers, a) == -1)
			exit(ft_malloc_error(numbers, words_nb));
		return (ft_free_tab(numbers, words_nb), 1);
	}
	return (ft_free_tab(numbers, words_nb), 0);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	b = NULL;
	if (ft_parsing(argc, argv, &a))
	{
		if (ft_parsing(argc, argv, &a) == -1)
			return (0);
		write(2, "Error\n", 6);
		return (0);
	}
	ft_push_b(&a, &b);
	ft_push_b(&a, &b);
	ft_push_b(&a, &b);
	ft_init_min_and_max(&b, ft_get_stack_size(&b));
	ft_sort_three_b(&b);
	ft_init_target(&a, &b);
	printf("LISTE A = \n");
	ft_test_print(a);
	printf("LISTE B = \n");
	ft_test_print(b);
	ft_print_target(a);
	ft_lstclear(&a);
	ft_lstclear(&b);
	printf("%d", 5 % 2);
	return (0);
}
