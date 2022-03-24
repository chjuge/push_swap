/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 13:55:39 by mproveme          #+#    #+#             */
/*   Updated: 2022/03/24 15:19:47 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

static int	find_lines_count(char **strs)
{
	int i;

	i = 0;
	while (strs[i])
		i++;
	return (i);
}

static char **deep_copy(char **strs)
{
	char	**new_strs;
	int		lines;
	int		i;

	lines = find_lines_count(strs) + 1;
	new_strs = malloc(sizeof(char*) * lines);
	i = 0;
	while (i < lines)
	{
		new_strs[i] = ft_strdup(strs[i]);
		i++;
	}
	new_strs[i] = 0;
	return (new_strs);
}

static char **adjasting_input(int *len, int argc, char **argv)
{
	char	**strs;

	if (argc > 2) 
	{
		*len = argc - 1;
		strs = deep_copy(argv + 1);
	}
	else
	{
		strs = ft_split(argv[1], " ");
		*len = find_lines_count(strs);
	}
	return (strs);
}

void	deep_free(char **strs)
{
	int	lines;
	int	i;

	lines = find_lines_count(strs);
	i = 0;
	while (i < lines)
	{
		free(strs[i]);
		i++;
	}
	free(strs);
}

int	parse_args(int argc, char **argv)
{
	long int	*arr1;
	long int	*arr2;
	int	 		len;
	char		**strs;
	t_elem		*a;

	strs = adjasting_input(&len, argc, argv);
	if (!check_input(len, strs))
	{
		ft_putstr_fd("Error (wrong input)", 2);
		return (0);
	}
	arr1 = transform_args(strs, len);
	if (!check_for_doubles(arr1, len) ||
		!check_for_max_min_int(arr1, len))
	{
		free(arr1);
		ft_putstr_fd("Error", 2);
		return (0);
	}
	arr2 = bubble_sort(arr1, len);
	fill_stack(a, arr1, len);
	return (1);
}
