/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_commands.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorpela <mkorpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 14:36:35 by mkorpela          #+#    #+#             */
/*   Updated: 2024/02/01 15:37:34 by mkorpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_node	*bottom_number_to_top(t_node *stack)
{
	t_node	*temp_first_node;
	t_node	*temp_last_node;

	stack = go_to_top_of_stack(stack);
	temp_first_node = stack;
	stack = go_to_bottom_of_stack(stack);
	temp_last_node = stack;
	stack->previous = NULL;
	stack->next = temp_first_node;
	stack = stack->next;
	stack->previous = temp_last_node;
	while (stack->next != temp_last_node)
	{
		stack = stack->next;
	}
	stack->next = NULL;
	stack = go_to_top_of_stack(stack);
	return (stack);
}

void	rra_bottom_number_to_top(t_node **stack_a)
{
	*stack_a = bottom_number_to_top(*stack_a);
	write(1, "rra\n", 4);
}

void	rrb_bottom_number_to_top(t_node **stack_b)
{
	*stack_b = bottom_number_to_top(*stack_b);
	write(1, "rrb\n", 4);
}

void	rrr_bottom_nums_to_top_both_stacks(t_node **stack_a, t_node **stack_b)
{
	*stack_a = bottom_number_to_top(*stack_a);
	*stack_b = bottom_number_to_top(*stack_b);
	write(1, "rrr\n", 4);
}
