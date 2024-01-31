/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalomon <fsalomon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 12:22:41 by fsalomon          #+#    #+#             */
/*   Updated: 2024/01/31 16:59:00 by fsalomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "lib_ft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	long			number;
	int				cost;
	int				min;
	int				max;
	int				index;
	struct s_stack	*target;
	struct s_stack	*prev;
	struct s_stack	*next;
}					t_stack;

unsigned int		ft_get_stack_size(t_stack **lst);
int					ft_malloc_error(char **numbers, int argc);
int					ft_parsing(int argc, char **argv, t_stack **a);
int					ft_check_create_stack(int words_nb, char **numbers,
						t_stack **a);
int					ft_check_error(int argc, char **argv, long *number_list);
int					ft_check_char(int argc, char **argv);
int					ft_check_int(int argc, char **argv, long *number_list);
int					ft_closest_max(t_stack **a, t_stack **b, t_stack **target);
int					ft_closest_min(t_stack **a, t_stack **b, t_stack **target);
long				ft_atol(const char *nptr);
long				*ft_fill_int_tab(int argc, long *number_list, char **argv);
t_stack				*ft_fill_list(int argc, long *number_list);
t_stack				*ft_lstnew(long number);
t_stack				*ft_remove_last_node(t_stack **lst);
t_stack				*ft_remove_first_node(t_stack **lst);
t_stack				*ft_find_min(t_stack **b, unsigned int size_b);
t_stack				*ft_find_max(t_stack **b, unsigned int size_b);
char				**ft_set_args(char **argv, int argc);
void				ft_free_tab(char **number_list, int argc);
void				ft_test_print(t_stack *a);
void				ft_print_argv(char **numbers);
void				ft_lstclear(t_stack **lst);
void				ft_add_last_node(t_stack **list, t_stack *new_node);
void				ft_add_first_node(t_stack **list, t_stack *new_node);
void				ft_swap_a(t_stack **a);
void				ft_swap_b(t_stack **b);
void				ft_swap_ab(t_stack **a, t_stack **b);
void				ft_push_a(t_stack **src, t_stack **dest);
void				ft_push_b(t_stack **src, t_stack **dest);
void				ft_rotate_a(t_stack **a);
void				ft_rotate_b(t_stack **b);
void				ft_rotate_ab(t_stack **a, t_stack **b);
void				ft_reverse_rotate_a(t_stack **a);
void				ft_reverse_rotate_b(t_stack **b);
void				ft_reverse_rotate_ab(t_stack **a, t_stack **b);
void				ft_init_min_and_max(t_stack **a, unsigned int lst_size);
void				ft_sort_three_b(t_stack **b);
void				ft_init_target(t_stack **a, t_stack **b);
void				ft_print_target(t_stack *a);

#endif