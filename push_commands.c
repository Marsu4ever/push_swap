/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_commands.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorpela <mkorpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 14:31:08 by mkorpela          #+#    #+#             */
/*   Updated: 2024/02/01 15:36:14 by mkorpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_top_number_stack_1_to_2(t_node **stack_1, t_node **stack_2)
{
	t_node	*detaching_node;
	int		number_of_nodes_in_stack_1;

	number_of_nodes_in_stack_1 = number_of_nodes_in_stack(*stack_1);
	*stack_1 = go_to_top_of_stack(*stack_1);
	*stack_2 = go_to_top_of_stack(*stack_2);
	detaching_node = *stack_1;
	if ((*stack_1)->next != NULL)
	{
		*stack_1 = (*stack_1)->next;
		(*stack_1)->previous = NULL;
	}
	if (*stack_2 == NULL)
	{
		*stack_2 = detaching_node;
		(*stack_2)->next = NULL;
	}
	else
	{
		detaching_node->next = *stack_2;
		(*stack_2)->previous = detaching_node;
	}
	if (number_of_nodes_in_stack_1 == 1)
		*stack_1 = NULL;
	*stack_2 = go_to_top_of_stack(*stack_2);
}

void	pb_a_to_b(t_node **stack_a, t_node **stack_b)
{
	push_top_number_stack_1_to_2(stack_a, stack_b);
	write(1, "pb\n", 3);
}

void	pa_b_to_a(t_node **stack_b, t_node **stack_a)
{
	push_top_number_stack_1_to_2(stack_b, stack_a);
	write(1, "pa\n", 3);
}
