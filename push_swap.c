/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalomon <fsalomon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 12:18:44 by fsalomon          #+#    #+#             */
/*   Updated: 2024/02/24 10:48:27 by fsalomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


/* PROJET VALIDE
axe d'amelioration possible : 

-integrer une variable len a la structure stack 
	->calculer la len de a  une fois au debut
	->modifier la len lors des appels des fonction push a et push b
	->limite le nombre de calcul effectuer rendrais le programme plus rapide
	
- creer un fichier main.c uniquement avec le main (plus clair)
- certains cas de 5 valeurs font 2 coups inutiles (voir pourquoi)
- ameliorer le makefile afin que les objets soit creer dans un dossier obj 
*/

int	ft_parsing(int argc, char **argv, t_stack **a)
{
	char	**numbers;
	int		words_nb;
	int		result_create_stack;

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
	result_create_stack = ft_check_create_stack(words_nb, numbers, a);
	if (result_create_stack == 1)
		return (ft_free_tab(numbers, words_nb), 1);
	else if (result_create_stack == -1)
		exit(ft_malloc_error(numbers, words_nb));
	return (ft_free_tab(numbers, words_nb), 0);
}

int	ft_check_if_already_sorted(t_stack **a)
{
	unsigned int	size;
	unsigned int	i;
	unsigned int	sorted;

	size = ft_get_stack_size(a);
	i = 0;
	sorted = 1;
	while (i < size - 1)
	{
		if ((*a)->number > (*a)->next->number)
			sorted = 0;
		i++;
		(*a) = (*a)->next;
	}
	(*a) = (*a)->next;
	return (sorted);
}

void	ft_sort(t_stack **a, t_stack **b)
{
	ft_sort_first_part(a, b);
	ft_sort_second_part(a, b);
	return ;
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int		result_parsing;

	b = NULL;
	result_parsing = ft_parsing(argc, argv, &a);
	if (result_parsing == 1)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	else if (result_parsing == -1)
		return (0);
	if (ft_check_if_already_sorted(&a))
	{
		ft_lstclear(&a);
		return (0);
	}
	if (ft_get_stack_size(&a) <= 3)
		ft_input_three(&a);
	else
		ft_sort(&a, &b);
	ft_sort_final(&a);
	ft_final_clear(&a, &b);
	return (0);
}
