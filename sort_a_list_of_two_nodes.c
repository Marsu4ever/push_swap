/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_a_list_of_two_nodes.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorpela <mkorpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 14:41:06 by mkorpela          #+#    #+#             */
/*   Updated: 2024/02/01 15:38:06 by mkorpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_list_of_two_nodes_stack_b(t_node *stack_b)
{
	int	num1;
	int	num2;

	stack_b = go_to_top_of_stack(stack_b);
	num1 = stack_b->number;
	num2 = stack_b->next->number;
	if (num1 > num2)
		;
	else
	{
		sb_swap_top_two_numbers(&stack_b);
	}
}

void	sort_list_of_two_nodes_stack_a(t_node *stack_a)
{
	int	num1;
	int	num2;

	num1 = stack_a->number;
	stack_a = stack_a->next;
	num2 = stack_a->number;
	if (num1 < num2)
		;
	else
	{
		sa_swap_top_two_numbers(&stack_a);
	}
}
