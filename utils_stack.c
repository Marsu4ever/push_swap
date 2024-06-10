/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorpela <mkorpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 14:58:09 by mkorpela          #+#    #+#             */
/*   Updated: 2024/02/01 15:40:12 by mkorpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_arguments(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		i++;
	}
	return (i);
}

int	number_of_nodes_in_stack(t_node *stack)
{
	int		i;
	t_node	*temp;

	i = 0;
	stack = go_to_top_of_stack(stack);
	temp = stack;
	while (temp)
	{
		temp = temp->next;
		i++;
	}
	return (i);
}

t_node	*go_to_top_of_stack(t_node *stack)
{
	if (stack == NULL)
	{
		return (stack);
	}
	while (stack->previous)
	{
		stack = stack->previous;
	}
	return (stack);
}

t_node	*go_to_bottom_of_stack(t_node *stack_a)
{
	while (stack_a->next)
	{
		stack_a = stack_a->next;
	}
	return (stack_a);
}
