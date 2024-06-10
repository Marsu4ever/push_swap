/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list_of_three_nodes_stack_b.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorpela <mkorpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 14:52:41 by mkorpela          #+#    #+#             */
/*   Updated: 2024/02/01 15:39:29 by mkorpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	is_max_at_top(t_node *stack)
{
	stack = go_to_top_of_stack(stack);
	if (stack -> number < stack->next->number)
		return (false);
	if (stack -> number < stack->next->next->number)
		return (false);
	return (true);
}

static void	sort_top_two_nodes_stack_b(t_node *stack)
{
	if (is_max_at_top(stack))
		return ;
	else
	{
		sb_swap_top_two_numbers(&stack);
		return ;
	}
}

static bool	is_min_in_second_node(t_node *stack)
{
	stack = go_to_top_of_stack(stack);
	stack = stack->next;
	if (stack -> number > stack->previous->number)
		return (false);
	if (stack -> number > stack->next->number)
		return (false);
	return (true);
}

static bool	check_if_min_at_bottom_of_stack(t_node *stack)
{
	stack = go_to_bottom_of_stack(stack);
	if (stack->number > stack->previous->number)
		return (false);
	if (stack->number > stack->previous->previous->number)
		return (false);
	return (true);
}

void	sort_list_of_three_nodes_stack_b(t_node *stack_b)
{
	if (check_if_min_at_bottom_of_stack(stack_b))
	{
		sort_top_two_nodes_stack_b(stack_b);
	}
	else
	{
		if (is_min_in_second_node(stack_b))
		{
			rrb_bottom_number_to_top(&stack_b);
			if (is_max_at_top(stack_b))
				return ;
			else
			{
				sb_swap_top_two_numbers(&stack_b);
				return ;
			}
		}
		else
		{
			rb_top_number_to_bottom(&stack_b);
			sort_top_two_nodes_stack_b(stack_b);
		}
	}
}
