/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_a_list_of_4_to_6_nodes.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorpela <mkorpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 14:46:49 by mkorpela          #+#    #+#             */
/*   Updated: 2024/02/05 11:05:10 by mkorpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	return_index_of_last_node(t_node *stack)
{
	int	i;

	if (stack == NULL)
	{
		return (-1);
	}
	i = 0;
	stack = go_to_top_of_stack(stack);
	while (stack->next)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}

static int	index_of_node_with_min_value(t_node *stack)
{
	int	i;

	if (stack == NULL)
	{
		return (-1);
	}
	i = 0;
	stack = go_to_top_of_stack(stack);
	while (stack->next && stack->index != 0)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}

static void	rotate_stack_a_to_lowest_value(t_node **stack)
{
	int		index_of_last_node;
	int		index_of_min_node;
	int		median_index;
	t_node	*temp;

	*stack = go_to_top_of_stack(*stack);
	temp = *stack;
	index_of_min_node = index_of_node_with_min_value(temp);
	index_of_last_node = return_index_of_last_node(temp);
	median_index = index_of_last_node / index_of_min_node;
	if (index_of_min_node <= median_index)
	{
		while ((temp)->index != 0)
		{
			ra_top_number_to_bottom(&temp);
		}
	}
	else
	{
		while ((temp)->index != 0)
		{
			rra_bottom_number_to_top(&temp);
		}
	}
}

void	sort_up_to_six_numbers(t_node **stack_a, t_node **stack_b)
{
	while (number_of_nodes_in_stack(*stack_a) > 3)
	{
		if ((*stack_a)->index > 2)
		{
			pb_a_to_b(stack_a, stack_b);
		}
		else
		{
			ra_top_number_to_bottom(stack_a);
		}
	}
	if (number_of_nodes_in_stack(*stack_b) == 2)
	{
		sort_list_of_two_nodes_stack_b(*stack_b);
	}
	if (number_of_nodes_in_stack(*stack_b) == 3)
	{
		sort_list_of_three_nodes_stack_b(*stack_b);
	}
	sort_list_of_three_nodes_stack_a(*stack_a);
	push_everything_from_stack_b_to_a(stack_a, stack_b);
	rotate_stack_a_to_lowest_value(stack_a);
}
