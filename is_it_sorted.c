/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_it_sorted.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorpela <mkorpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 13:40:37 by mkorpela          #+#    #+#             */
/*   Updated: 2024/02/01 15:35:45 by mkorpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	is_it_sorted_stack_a(t_node **stack_a)
{
	t_node	*temp;
	int		previous_index;

	temp = *stack_a;
	while (temp->next)
	{
		previous_index = temp->index;
		temp = temp->next;
		if (previous_index + 1 != temp->index)
			return (false);
	}
	return (true);
}

bool	is_it_sorted(t_node **stack_a, t_node **stack_b)
{
	t_node	*temp1;
	t_node	*temp2;
	int		previous_index;

	temp1 = *stack_a;
	temp2 = *stack_b;
	while (temp1->next)
	{
		previous_index = temp1->index;
		temp1 = temp1->next;
		if (previous_index + 1 != temp1->index)
			return (false);
	}
	if (temp2 != NULL || number_of_nodes_in_stack(temp2) >= 2)
	{
		while (temp2->next)
		{
			previous_index = temp2->index;
			temp2 = temp2->next;
			if (previous_index - 1 != temp2->index)
				return (false);
		}
	}
	return (true);
}
