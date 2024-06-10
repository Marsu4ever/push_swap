/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_for_empty_string.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorpela <mkorpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 13:43:51 by mkorpela          #+#    #+#             */
/*   Updated: 2024/02/01 10:23:34 by mkorpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	only_whitespaces_in_string(char *argv)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (argv[i] != '\0')
	{
		if (argv[i] == 32 || (argv[i] >= 9 && argv[i] <= 13))
			i++;
		else
		{
			j++;
			i++;
		}
	}
	if (j == 0 && i != 0)
		return (true);
	return (false);
}

int	check_for_empty_string(char **argv)
{
	if (argv[1][0] == '\0' || only_whitespaces_in_string(argv[1]))
		return (1);
	return (0);
}
