/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_for_duplicates_in_string.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorpela <mkorpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 13:57:24 by mkorpela          #+#    #+#             */
/*   Updated: 2024/02/03 16:17:50 by mkorpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	if_only_zeroes_then_increment_to_null(char *string, int *i)
{
	int	j;

	j = 0;
	if (string[*i] == '-')
	{
		(*i)++;
		j++;
	}
	while (string[*i] == '0')
	{
		(*i)++;
		j++;
	}
	if (string[*i] == '\0')
		return ;
	while (j > 0)
	{
		(*i)--;
		j--;
	}
	return ;
}

static void	increment_sign(char **s1, char **s2, int *i, int *j)
{
	if ((*s1)[*i] == '+')
	{
		(*i)++;
	}
	if ((*s2)[*j] == '+')
	{
		(*j)++;
	}
	if ((*s1)[*i] == '-' && (*s2)[*j] == '-')
	{
		(*i)++;
		(*j)++;
	}
}

static int	ft_strcmp_numbers(char *s1, char *s2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	increment_sign(&s1, &s2, &i, &j);
	if_only_zeroes_then_increment_to_null(s1, &i);
	if_only_zeroes_then_increment_to_null(s2, &j);
	while (s1[i] == '0')
		i++;
	while (s2[j] == '0')
		j++;
	while (s1[i] != '\0' || s2[j] != '\0')
	{
		if (s1[i] - s2[j] != 0)
			return (s1[i] - s2[j]);
		i++;
		j++;
	}
	return (0);
}

int	check_for_duplicates_in_string(char **argv)
{
	int	i;
	int	j;
	int	argument_count;

	i = 1;
	j = 2;
	argument_count = count_arguments(argv);
	while (i < argument_count - 1)
	{
		while (argv[j])
		{
			if (ft_strcmp_numbers(argv[i], argv[j]) == 0)
			{
				return (1);
			}
			j++;
		}
		i++;
		j = i + 1;
	}
	return (0);
}
