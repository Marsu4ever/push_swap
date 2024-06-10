/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_smallest_current_value.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorpela <mkorpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 05:31:42 by mkorpela          #+#    #+#             */
/*   Updated: 2024/02/01 15:35:35 by mkorpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_smallest_current_value(t_node **stack_a)
{
	long	smallest_value;
	t_node	*temp_stack;

	temp_stack = *stack_a;
	smallest_value = 2147483648;
	while (temp_stack)
	{
		if (smallest_value > temp_stack->number && temp_stack->index == -1)
		{
			smallest_value = temp_stack->number;
		}
		temp_stack = temp_stack->next;
	}
	return (smallest_value);
}
