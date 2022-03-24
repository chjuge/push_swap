/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 13:55:39 by mproveme          #+#    #+#             */
/*   Updated: 2022/03/24 18:17:23 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

int	find_lines_count(char **strs)
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
		strs = ft_split(argv[1], ' ');
		*len = find_lines_count(strs);
	}
	return (strs);
}



int	parse_args(int argc, char **argv)
{
	long int	*arr1;
	long int	*arr2;
	int	 		len;
	char		**strs;
	t_elem		*a;

	a = 0;
	strs = adjasting_input(&len, argc, argv);
	if (!check_input(len, strs))
	{
		ft_putstr_fd("Error (wrong input)\n", 2);
		return (0);
	}
	// show_lines(strs, len);
	arr1 = transform_args(strs, len);
	// show_array(arr1, len);
	if (!check_for_doubles(arr1, len) ||
		!check_for_max_min_int(arr1, len))
	{
		free(arr1);
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	arr2 = bubble_sort(arr1, len);
	// show_array(arr2, len);
	a = 0;
	a = fill_stack(a, arr1, len);
	// show_elem(a);
	// show_elem(a->next);
	// show_elem(a->next->next);
	// show_elem(a->next->next->next);
	// printf("tut?\n");
	show_stack(&a, len);
	return (1);
}