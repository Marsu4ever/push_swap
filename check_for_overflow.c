/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_for_overflow.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorpela <mkorpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 13:49:18 by mkorpela          #+#    #+#             */
/*   Updated: 2024/02/01 11:09:09 by mkorpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_strcmp_numbers_int_max_and_min(char *s1, char *s2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (s1[0] == '+')
		i++;
	if (s2[0] == '+')
		i++;
	while (s1[i] != '\0' && s2[j] != '\0')
	{
		if (s1[i] - s2[j] > 0)
		{
			return (s1[i] - s2[j]);
		}
		if (s1[i] - s2[j] < 0)
			return (0);
		i++;
		j++;
	}
	return (0);
}

static int	compare_against_int_max_and_min(int digit_count, char **argv, int i)
{
	char	*int_max;
	char	*int_min;
	char	*max_value;
	int		j;

	int_max = "2147483647";
	int_min = "-2147483648";
	max_value = int_max;
	j = 0;
	if (digit_count <= 9)
		return (0);
	if (digit_count == 10)
	{
		while (argv[i][j] == 32 || (argv[i][j] >= 9 && argv[i][j] <= 13))
			j++;
		if (argv[i][j] == '-')
			max_value = int_min;
		if (ft_strcmp_numbers_int_max_and_min(argv[i] + j, max_value) > 0)
		{
			return (1);
		}
		j++;
	}
	return (0);
}

static int	num_greater_than_10_dig(char **argv, int *i, int *j, int *dig_count)
{
	while (argv[*i][*j] != '\0')
	{
		while (argv[*i][*j] == 32 || (argv[*i][*j] >= 9 && argv[*i][*j] <= 13))
			(*j)++;
		if (argv[*i][*j] == '+' || argv[*i][*j] == '-')
			(*j)++;
		while (argv[*i][*j] >= '0' && argv[*i][*j] <= '9')
		{
			(*dig_count)++;
			(*j)++;
			if ((*dig_count) > 10)
				return (1);
		}
		while (argv[*i][*j] == 32 || (argv[*i][*j] >= 9 && argv[*i][*j] <= 13))
			(*j)++;
	}
	return (0);
}

int	check_for_overflow(char **argv)
{
	int	i;
	int	j;
	int	digit_count;

	digit_count = 0;
	i = 1;
	j = 0;
	while (argv[i])
	{
		if (num_greater_than_10_dig(argv, &i, &j, &digit_count) == 1)
			return (1);
		if (compare_against_int_max_and_min(digit_count, argv, i) == 1)
			return (1);
		j = 0;
		digit_count = 0;
		i++;
	}
	return (0);
}
