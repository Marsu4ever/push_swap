/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorpela <mkorpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 13:19:24 by mkorpela          #+#    #+#             */
/*   Updated: 2024/02/01 17:47:36 by mkorpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	result_of_base_to_exponent(int exponent)
{
	int	result;

	if (exponent == 0)
	{
		return (1);
	}
	result = 2 * result_of_base_to_exponent(exponent - 1);
	return (result);
}

static int	find_number_of_bits(int number_of_nodes_in_list)
{
	int	exponent;

	exponent = 0;
	while (result_of_base_to_exponent(exponent) < number_of_nodes_in_list)
	{
		exponent++;
	}
	return (exponent);
}

void	push_everything_from_stack_b_to_a(t_node **stack_a, t_node **stack_b)
{
	while (number_of_nodes_in_stack(*stack_b))
	{
		pa_b_to_a(stack_b, stack_a);
	}
}

static void	check_bit_if_pb_or_ra(t_node **stack_a, t_node **stack_b, int *i)
{
	int	j;
	int	number_of_nodes;

	j = 0;
	number_of_nodes = number_of_nodes_in_stack(*stack_a);
	while (j < number_of_nodes && is_it_sorted(stack_a, stack_b) == 0)
	{
		if (((((*stack_a)->index) >> *i) & 1) == 0)
			pb_a_to_b(stack_a, stack_b);
		else
			ra_top_number_to_bottom(stack_a);
		j++;
	}
}

void	radix_sort(t_node **stack_a, t_node **stack_b)
{
	int	i;
	int	j;
	int	number_of_bits;
	int	number_of_nodes;

	i = 0;
	number_of_nodes = number_of_nodes_in_stack(*stack_a);
	number_of_bits = find_number_of_bits(number_of_nodes);
	while ((i < number_of_bits) && is_it_sorted(stack_a, stack_b) == 0)
	{
		check_bit_if_pb_or_ra(stack_a, stack_b, &i);
		*stack_b = go_to_top_of_stack(*stack_b);
		j = 0;
		number_of_nodes = number_of_nodes_in_stack(*stack_b);
		i++;
		while ((j < number_of_nodes) && is_it_sorted(stack_a, stack_b) == 0)
		{
			pa_b_to_a(stack_b, stack_a);
			j++;
		}
		*stack_a = go_to_top_of_stack(*stack_a);
		push_everything_from_stack_b_to_a(stack_a, stack_b);
	}
}
