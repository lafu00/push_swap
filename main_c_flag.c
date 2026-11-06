/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_c_flag.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rehlich <rehlich@student.42malaga.com >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/05 18:17:49 by rehlich           #+#    #+#             */
/*   Updated: 2026/11/06 12:14:36 by rehlich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		joined = ft_strjoin(temp, " ");
		free(temp);
		if (!joined)
			return (NULL);
		temp = ft_strjoin(joined, argv[i++]);
		free(joined);
	}
	if (!temp)
		return (NULL);
	total = ft_split(temp, ' ');
	free(temp);
	if (!total)
		return (NULL);
	return (total);
}

int	if_flags(char **total)
{
	int	i;
	int	strategy;
	int	bench;
	int	count;

	count = 0;
	while (total[count])
		count++;
	strategy = 0;
	bench = 0;
	i = 0;
	while (i < count)
	{
		if (ft_strncmp(total[i], "--bench", 8) == 0)
			bench = 10;
		else if (ft_strncmp(total[i], "--simple", 9) == 0)
			strategy = 1;
		else if (ft_strncmp(total[i], "--medium", 9) == 0)
			strategy = 2;
		else if (ft_strncmp(total[i], "--complex", 10) == 0)
			strategy = 3;
		else if (ft_strncmp(total[i], "--adaptive", 11) == 0)
			strategy = 4;
		i++;
	}
	return (bench + strategy);
}

int	main(int argc, char **argv)
{
	int		flag;
	char	**total;
	int		i;

	flag = 0;
	if (argc == 1)
		return (0);
	total = matrix(argc, argv);
	if (!total)
		return (1);
	flag = if_flags(total);
	i = 0;
	printf("Flag: %i\n", flag);
	while (total[i])
	{
		printf("Total: %s\n", total[i]);
		free(total[i]);
		i++;
	}
	free(total);
	return (0);
}
