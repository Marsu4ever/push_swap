/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_commands.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorpela <mkorpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 14:25:38 by mkorpela          #+#    #+#             */
/*   Updated: 2024/02/29 10:21:17 by mkorpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa_swap_top_two_numbers(t_node **stack_a)
{
	*stack_a = swap_top_two_numbers(*stack_a);
	write(1, "sa\n", 3);
}

void	sb_swap_top_two_numbers(t_node **stack_b)
{
	*stack_b = swap_top_two_numbers(*stack_b);
	write(1, "sb\n", 3);
}

void	sss_swap_top_two_nums_both_stacks(t_node **stack_a, t_node **stack_b)
{
	*stack_a = swap_top_two_numbers(*stack_a);
	*stack_b = swap_top_two_numbers(*stack_b);
	write(1, "sss\n", 4);
}
