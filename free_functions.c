/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorpela <mkorpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 14:12:22 by mkorpela          #+#    #+#             */
/*   Updated: 2024/02/01 17:23:24 by mkorpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_argv_made_with_malloc(char **argv, bool created_argv_with_malloc)
{
	int	i;

	i = 0;
	if (created_argv_with_malloc)
	{
		while (argv[i] != NULL)
		{
			free(argv[i]);
			i++;
		}
		free(argv);
	}
}

void	free_stack_nodes(t_node **stack_a)
{
	t_node	*current_node;
	t_node	*next_node;

	*stack_a = go_to_top_of_stack(*stack_a);
	current_node = *stack_a;
	next_node = NULL;
	while (current_node)
	{
		next_node = current_node->next;
		free(current_node);
		current_node = next_node;
	}
	*stack_a = NULL;
}
