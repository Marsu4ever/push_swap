/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list_of_numbers.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorpela <mkorpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 14:17:29 by mkorpela          #+#    #+#             */
/*   Updated: 2024/02/05 09:55:56 by mkorpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	set_index_value(t_node **stack_a, int smallest_value, int *i)
{
	t_node	*temp_stack;

	temp_stack = *stack_a;
	while (temp_stack)
	{
		if (smallest_value == temp_stack->number && temp_stack->index == -1)
		{
			temp_stack->index = (*i);
			(*i)++;
		}
		temp_stack = temp_stack->next;
	}
}

static void	add_index_of_number_value(t_node **stack_a)
{
	int		i;
	long	smallest_value;

	i = 0;
	smallest_value = 2147483648;
	*stack_a = go_to_top_of_stack(*stack_a);
	while (i < number_of_nodes_in_stack(*stack_a))
	{
		smallest_value = find_smallest_current_value(stack_a);
		set_index_value(stack_a, smallest_value, &i);
	}
	go_to_top_of_stack(*stack_a);
}

static t_node	*add_node_to_stack_and_link(t_node *stack_a, t_node *new_node)
{
	if (!stack_a)
	{
		stack_a = new_node;
		new_node->next = NULL;
		new_node->previous = NULL;
	}
	else
	{
		stack_a->next = new_node;
		new_node->previous = stack_a;
		new_node->next = NULL;
		stack_a = stack_a->next;
	}
	return (stack_a);
}

static t_node	*create_node_with_number(char *argv, int *i)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->number = ft_atoi(argv);
	new_node->index = -1;
	new_node->previous = NULL;
	new_node->next = NULL;
	(*i)++;
	return (new_node);
}

t_node	*create_lst_of_numbers(char *argv[], t_node *stack_a, bool malloc_argv)
{
	int		i;
	t_node	*new_node;

	i = 1;
	while (argv[i] != NULL)
	{
		new_node = create_node_with_number(argv[i], &i);
		if (!new_node)
		{
			free_argv_made_with_malloc(argv, malloc_argv);
			return (NULL);
		}
		stack_a = add_node_to_stack_and_link(stack_a, new_node);
	}
	add_index_of_number_value(&stack_a);
	while (stack_a->previous != NULL)
		stack_a = stack_a->previous;
	return (stack_a);
}
