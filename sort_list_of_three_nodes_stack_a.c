/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list_of_three_nodes_stack_a.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorpela <mkorpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 14:50:16 by mkorpela          #+#    #+#             */
/*   Updated: 2024/02/01 15:38:21 by mkorpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	is_min_at_top(t_node *stack_a)
{
	stack_a = go_to_top_of_stack(stack_a);
	if (stack_a -> number > stack_a->next->number)
		return (false);
	if (stack_a -> number > stack_a->next->next->number)
		return (false);
	return (true);
}

static void	sort_top_two_nodes_stack_a(t_node *stack_a)
{
	if (is_min_at_top(stack_a))
	{
		return ;
	}
	else
	{
		sa_swap_top_two_numbers(&stack_a);
		return ;
	}
}

static bool	is_max_in_second_node(t_node *stack_a)
{
	stack_a = go_to_top_of_stack(stack_a);
	stack_a = stack_a->next;
	if (stack_a -> number < stack_a->previous->number)
		return (false);
	if (stack_a -> number < stack_a->next->number)
		return (false);
	return (true);
}

static bool	check_if_max_at_bottom_of_stack(t_node *stack_a)
{
	stack_a = go_to_bottom_of_stack(stack_a);
	if (stack_a->number < stack_a->previous->number)
		return (false);
	if (stack_a->number < stack_a->previous->previous->number)
		return (false);
	return (true);
}

void	sort_list_of_three_nodes_stack_a(t_node *stack_a)
{
	if (check_if_max_at_bottom_of_stack(stack_a))
	{
		sort_top_two_nodes_stack_a(stack_a);
	}
	else
	{
		if (is_max_in_second_node(stack_a))
		{
			rra_bottom_number_to_top(&stack_a);
			if (is_min_at_top(stack_a))
				return ;
			else
			{
				sa_swap_top_two_numbers(&stack_a);
				return ;
			}
		}
		else
		{
			ra_top_number_to_bottom(&stack_a);
			sort_top_two_nodes_stack_a(stack_a);
		}
	}
}
