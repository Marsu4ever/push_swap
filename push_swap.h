/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorpela <mkorpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 10:45:00 by mkorpela          #+#    #+#             */
/*   Updated: 2024/02/05 11:09:54 by mkorpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>
# include "./libft/libft.h"

typedef struct s_node
{
	int				number;
	int				index;
	struct s_node	*next;
	struct s_node	*previous;
}	t_node;

char	**change_string_into_argv_with_arguments(char **argv);
int		check_for_duplicates_in_string(char **argv);
int		check_for_empty_string(char **argv);
int		check_for_only_digits_and_sign_and_whitespace(char **argv);
int		check_for_overflow(char **argv);
bool	check_if_single_argument(char **argv);
t_node	*create_lst_of_numbers(char *argv[], t_node *stack_a, bool malloc_argv);
int		find_smallest_current_value(t_node **stack_a);
void	free_argv_made_with_malloc(char **argv, bool created_argv_with_malloc);
void	free_stack_nodes(t_node **stack_a);
bool	is_it_sorted(t_node **stack_a, t_node **stack_b);
bool	is_it_sorted_stack_a(t_node **stack_a);
void	pa_b_to_a(t_node **stack_b, t_node **stack_a);
void	pb_a_to_b(t_node **stack_a, t_node **stack_b);
void	push_everything_from_stack_b_to_a(t_node **stack_a, t_node **stack_b);
void	radix_sort(t_node **stack_a, t_node **stack_b);
void	rra_bottom_number_to_top(t_node **stack_a);
void	rrb_bottom_number_to_top(t_node **stack_b);
void	rrr_bottom_nums_to_top_both_stacks(t_node **stack_a, t_node **stack_b);
void	ra_top_number_to_bottom(t_node **stack_a);
void	rb_top_number_to_bottom(t_node **stack_b);
void	rr_top_number_to_bottom(t_node **stack_a, t_node **stack_b);
void	sort_up_to_six_numbers(t_node **stack_a, t_node **stack_b);
void	sort_up_to_six_numbers(t_node **stack_a, t_node **stack_b);
void	sort_list_of_two_nodes_stack_a(t_node *stack_a);
void	sort_list_of_two_nodes_stack_b(t_node *stack_b);
void	sort_list_of_three_nodes_stack_a(t_node *stack_a);
void	sort_list_of_three_nodes_stack_b(t_node *stack_b);
void	sa_swap_top_two_numbers(t_node **stack_a);
void	sb_swap_top_two_numbers(t_node **stack_b);
void	sss_swap_top_two_nums_both_stacks(t_node **stack_a, t_node **stack_b);
t_node	*swap_top_two_numbers(t_node *stack);
int		write_error_and_return_1(void);
int		ft_strlen_int(const char *s);
char	*string_copy(char *dest, char *source, int *i);
int		count_arguments(char **argv);
int		number_of_nodes_in_stack(t_node *stack);
t_node	*go_to_top_of_stack(t_node *stack);
t_node	*go_to_bottom_of_stack(t_node *stack_a);

#endif
