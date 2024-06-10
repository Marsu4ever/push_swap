/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_commands.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorpela <mkorpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 14:33:14 by mkorpela          #+#    #+#             */
/*   Updated: 2024/02/05 09:44:56 by mkorpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_node	*top_number_to_bottom(t_node *stack)
{
	t_node	*temp_first_node;
	t_node	*temp_last_node;

	stack = go_to_bottom_of_stack(stack);
	temp_last_node = stack;
	stack = go_to_top_of_stack(stack);
	temp_first_node = stack;
	stack->previous = temp_last_node;
	stack->next = NULL;
	stack = stack->previous;
	stack->next = temp_first_node;
	while (stack->previous != temp_first_node)
	{
		stack = stack->previous;
	}
	stack->previous = NULL;
	stack = go_to_top_of_stack(stack);
	return (stack);
}

void	ra_top_number_to_bottom(t_node **stack_a)
{
	*stack_a = top_number_to_bottom(*stack_a);
	write(1, "ra\n", 3);
}

void	rb_top_number_to_bottom(t_node **stack_b)
{
	*stack_b = top_number_to_bottom(*stack_b);
	write(1, "rb\n", 3);
}

void	rr_top_number_to_bottom(t_node **stack_a, t_node **stack_b)
{
	*stack_a = top_number_to_bottom(*stack_a);
	*stack_b = top_number_to_bottom(*stack_b);
	write(1, "rr\n", 3);
}
