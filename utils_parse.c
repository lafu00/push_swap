/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   utils_parse.c                                     :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: rehlich <rehlich@student.42malaga.com>    #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/04 13:35:11 by rehlich          #+#    #+#              */
/*   Updated: 2026/11/06 20:22:35 by rehlich         ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	check_spaces(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
			str[i] = ' ';
		else if (str[i] == '\\' && (str[i + 1] == 't' || str[i + 1] == 'n'
					|| str[i + 1] == 'v' || str[i + 1] == 'f'
		|| str[i + 1] == 'r'))
		{
			str[i] = ' ';
			str[i + 1] = ' ';
			i++;
		}
		i++;
	}
}

char	**matrix(int argc, char **argv)
{
	int		i;
	char	*joined;
	char	*temp;
	char	**total;

	if (argc < 2)
		return (NULL);
	temp = ft_strdup(argv[1]);
	i = 2;
	while (temp && i < argc)
	{
		check_spaces(temp);
		joined = ft_strjoin(temp, " ");
		free(temp);
		if (!joined)
			return (NULL);
		temp = ft_strjoin(joined, argv[i++]);
		free(joined);
	}
	if (temp)
		check_spaces(temp);
	total = ft_split(temp, ' ');
	return (free(temp), total);
}

static int	check_flag_type(char *str, int *bench, int *strategy)
{
	if (ft_strncmp(str, "--bench", 8) == 0)
	{
		*bench = 10;
		return (1);
	}
	if (ft_strncmp(str, "--simple", 9) == 0)
		return (*strategy = 1, 1);
	if (ft_strncmp(str, "--medium", 9) == 0)
		return (*strategy = 2, 1);
	if (ft_strncmp(str, "--complex", 10) == 0)
		return (*strategy = 3, 1);
	if (ft_strncmp(str, "--adaptive", 11) == 0)
		return (*strategy = 4, 1);
	return (0);
}

int	extract_flags(char **total)
{
	int	i;
	int	j;
	int	bench;
	int	strategy;

	bench = 0;
	strategy = 4;
	i = 0;
	while (total[i])
	{
		if (check_flag_type(total[i], &bench, &strategy))
		{
			free(total[i]);
			j = i;
			while (total[j])
			{
				total[j] = total[j + 1];
				j++;
			}
			continue ;
		}
		i++;
	}
	return (bench + strategy);
}

void	free_matrix(char **total)
{
	int	i;

	if (!total)
		return ;
	i = 0;
	while (total[i])
	{
		free(total[i]);
		i++;
	}
	free(total);
}
