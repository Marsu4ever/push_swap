/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_for_only_digits_and_sign_and_whitespa        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorpela <mkorpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 13:45:45 by mkorpela          #+#    #+#             */
/*   Updated: 2024/02/03 16:13:03 by mkorpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_if_sign_after_number(char *argv)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (argv[i] == 32 || (argv[i] <= 9 && argv[i] >= 13))
	{
		i++;
	}
	while (argv[i] != '\0')
	{
		if (argv[i] == '+' || argv[i] == '-')
			if (j != 0)
				if (argv[i - 1] >= '0' && argv[i - 1] <= '9')
					return (1);
		i++;
		j++;
	}
	return (0);
}

static int	check_digit_sign_ws(char *argv, int *dig_count, int *j, int *sign)
{
	if (argv[*j] >= '0' && argv[*j] <= '9')
	{
		(*dig_count)++;
		(*j)++;
	}
	else if (argv[*j] == '+' || argv[*j] == '-')
	{
		(*sign)++;
		(*j)++;
	}
	else if (argv[*j] == 32 || (argv[*j] >= 9 && argv[*j] <= 13))
	{
		(*j)++;
	}
	else
		return (1);
	return (0);
}

int	check_for_only_digits_and_sign_and_whitespace(char **argv)
{
	int	i;
	int	j;
	int	sign_count;
	int	dig_count;

	i = 1;
	while (argv[i] != NULL)
	{
		j = 0;
		sign_count = 0;
		dig_count = 0;
		while (argv[i][j] != '\0')
		{
			if (check_digit_sign_ws(argv[i], &dig_count, &j, &sign_count) == 1)
				return (1);
		}
		if (sign_count > 1 || (sign_count == 1 && dig_count == 0))
			return (1);
		if (check_if_sign_after_number(argv[i]) == 1)
			return (1);
		i++;
	}
	return (0);
}
