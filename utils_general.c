/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_general.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorpela <mkorpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 13:59:55 by mkorpela          #+#    #+#             */
/*   Updated: 2024/02/01 16:04:02 by mkorpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	write_error_and_return_1(void)
{
	write(2, "Error\n", 6);
	return (1);
}

int	ft_strlen_int(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*string_copy(char *dest, char *source, int *i)
{
	int	j;

	j = 0;
	while (source[j])
	{
		dest[*i] = source[j];
		(*i)++;
		j++;
	}
	return (dest);
}
