/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lerodrig <lerodrig@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 12:01:53 by lerodrig          #+#    #+#             */
/*   Updated: 2026/11/04 15:33:30 by lerodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int		i;
	int		j;
	long	value;
	char	*temp;
	char	*joined;
	char	**total;

	if (argc < 2)
		return (0);
	temp = ft_strdup("");
	if (!temp)
		return (1);
	i = 1;
	while (i < argc || (argc == 2 && argv[1] == NULL))
	{
		joined = ft_strjoin(temp, argv[i]);
		free(temp);
		if (!joined)
			return (1);
		temp = joined;
		if (i < argc - 1)
		{
			joined = ft_strjoin(temp, " ");
			free(temp);
			if (!joined)
				return (1);
			temp = joined;
		}
		i++;
	}
	total = ft_split(temp, ' ');
	free(temp);
	if (!total)
		return (1);
	i = 0;
	while (total[i])
	{
		if (!is_valid_number(total[i]))
		{
			write(2, "Error\n", 6);
			j = 0;
			while (total[j])
			{
				free(total[j]);
				j++;
			}
			free(total);
			return (1);
		}
		value = ft_atol(total[i]);
		if (value < INT_MIN || value > INT_MAX)
		{
			write(2, "Error\n", 6);
			j = 0;
			while (total[j])
			{
				free(total[j]);
				j++;
			}
			free(total);
			return (1);
		}
		i++;
	}
	i = 0;
	while (total[i])
	{
		printf("Total: %ld\n", ft_atol(total[i]));
		free(total[i]);
		i++;
	}
	free(total);
	return (0);
}
/*
while (argv[i])
{
j = 0;
if (argv[i][j] == '-' || argv[i][j] == '+')
j++;
if (argv[i][j] == '\0')
{
write(2, "Error\n", 6);
return (1);
}
while (argv[i][j])
{
if (argv[i][j] < '0' || argv[i][j] > '9')
{
write(2, "Error\n", 6);
return (1);
}
j++;
}
i++;
}
return (0);
*/
