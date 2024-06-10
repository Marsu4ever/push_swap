/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_if_single_argument.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorpela <mkorpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 14:59:36 by mkorpela          #+#    #+#             */
/*   Updated: 2024/01/31 05:32:07 by mkorpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	check_if_single_argument(char **argv)
{
	int	i;

	i = 0;
	while ((argv[1][i] >= 9 && argv[1][i] <= 13) || argv[1][i] == 32)
	{
		i++;
	}
	while (argv[1][i] != 32 && argv[1][i] != '\0')
	{
		i++;
	}
	while ((argv[1][i] >= 9 && argv[1][i] <= 13) || argv[1][i] == 32)
	{
		i++;
	}
	if (argv[1][i] != '\0')
	{
		return (false);
	}
	return (true);
}
