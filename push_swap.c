/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorpela <mkorpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 10:47:30 by mkorpela          #+#    #+#             */
/*   Updated: 2024/02/05 11:32:24 by mkorpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	zero_or_single_argument(int argc, char **argv)
{
	if (argc == 1)
		exit (0);
	if (argc == 2 && check_if_single_argument(argv))
	{
		if (check_for_empty_string(argv) == 1)
		{
			exit (write_error_and_return_1());
		}
		if (check_for_only_digits_and_sign_and_whitespace(argv) == 1)
			exit (write_error_and_return_1());
		if (check_for_overflow(argv) == 1)
			exit (write_error_and_return_1());
		exit (0);
	}
	return ;
}

static int	error_handing_for_many_args(char **argv, bool malloc_argv)
{
	if (check_for_only_digits_and_sign_and_whitespace(argv) == 1)
	{
		free_argv_made_with_malloc(argv, malloc_argv);
		return (1);
	}
	if (check_for_duplicates_in_string(argv) == 1)
	{
		free_argv_made_with_malloc(argv, malloc_argv);
		return (1);
	}
	if (check_for_overflow(argv) == 1)
	{
		free_argv_made_with_malloc(argv, malloc_argv);
		return (1);
	}
	return (0);
}

static void	sorting_algorithms(t_node *stack_a, t_node *stack_b, int argc)
{
	if (argc == 3)
		sort_list_of_two_nodes_stack_a(stack_a);
	if (argc == 4)
		sort_list_of_three_nodes_stack_a(stack_a);
	if (argc > 4 && argc < 8 && !is_it_sorted_stack_a(&stack_a))
		sort_up_to_six_numbers(&stack_a, &stack_b);
	if (argc >= 8)
		radix_sort(&stack_a, &stack_b);
}

static void	free_all(t_node **a, t_node **b, char **argv, bool malloc_argv)
{
	free_stack_nodes(a);
	free_stack_nodes(b);
	free_argv_made_with_malloc(argv, malloc_argv);
}

int	main(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*stack_b;
	bool	malloc_argv;

	stack_a = NULL;
	stack_b = NULL;
	malloc_argv = false;
	zero_or_single_argument(argc, argv);
	if (argc == 2 && !check_if_single_argument(argv))
	{
		argv = change_string_into_argv_with_arguments(argv);
		if (argv == NULL)
			return (1);
		malloc_argv = true;
		argc = count_arguments(argv);
	}
	if (error_handing_for_many_args(argv, malloc_argv) == 1)
		return (write_error_and_return_1());
	stack_a = create_lst_of_numbers(argv, stack_a, malloc_argv);
	if (stack_a == NULL)
		return (1);
	sorting_algorithms(stack_a, stack_b, argc);
	free_all(&stack_a, &stack_b, argv, malloc_argv);
	return (0);
}
