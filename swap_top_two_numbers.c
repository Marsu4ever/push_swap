/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_top_two_numbers.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorpela <mkorpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 14:27:31 by mkorpela          #+#    #+#             */
/*   Updated: 2024/02/01 15:40:03 by mkorpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_node	*swap_a_list_of_two_nodes(t_node *stack)
{
	t_node	*temp;

	stack = go_to_top_of_stack(stack);
	temp = stack;
	temp->next->next = temp->next->previous;
	temp->next->previous = NULL;
	temp->previous = temp->next;
	temp->next = NULL;
	stack = go_to_top_of_stack(stack);
	return (stack);
}

static t_node	*swap_a_list_with_more_than_two_nodes(t_node *stack)
{
	t_node	*temp;

	temp = stack->next->next;
	stack->next->next->previous = stack;
	stack->next->next = stack->next->previous;
	stack->next->previous = NULL;
	stack->previous = stack->next;
	stack->next = temp;
	stack = go_to_top_of_stack(stack);
	return (stack);
}

t_node	*swap_top_two_numbers(t_node *stack)
{
	t_node	*temp;

	temp = stack;
	stack = go_to_top_of_stack(stack);
	if (stack->next->next == NULL)
		return (swap_a_list_of_two_nodes(stack));
	else
	{
		stack = swap_a_list_with_more_than_two_nodes(stack);
		return (stack);
	}
}
