/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_string_into_argv_with_arguments.c           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorpela <mkorpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 14:15:17 by mkorpela          #+#    #+#             */
/*   Updated: 2024/02/03 16:02:34 by mkorpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	*create_new_string_that_contains_argv0(char **argv)
{
	char	*new_string;
	int		len_argv0;
	int		len_string;
	int		i;

	len_argv0 = ft_strlen_int(argv[0]);
	len_string = ft_strlen_int(argv[1]);
	new_string = (char *)malloc((len_argv0 + len_string + 2) * sizeof(char));
	if (new_string == NULL)
	{
		return (NULL);
	}
	i = 0;
	new_string = string_copy(new_string, argv[0], &i);
	new_string[i] = ' ';
	i++;
	new_string = string_copy(new_string, argv[1], &i);
	new_string[i] = '\0';
	return (new_string);
}

char	**change_string_into_argv_with_arguments(char **argv)
{
	char	delimiter;
	char	*new_string;
	char	**new_argv;

	new_string = create_new_string_that_contains_argv0(argv);
	if (!new_string)
		return (NULL);
	delimiter = ' ';
	new_argv = ft_split(new_string, delimiter);
	if (new_argv == NULL)
	{
		free(new_string);
		write(2, "Error\n", 6);
		return (NULL);
	}
	free(new_string);
	return (new_argv);
}
