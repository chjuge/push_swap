/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 13:55:39 by mproveme          #+#    #+#             */
/*   Updated: 2022/03/26 14:04:55 by mproveme         ###   ########.fr       */
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



int	parse_args(int argc, char **argv, t_store *store)
{
	char		**strs;
	int	 		len;
	long int	*arr_un;
	long int	*arr_sort;
	// t_elem		*a;

	// a = 0;
	strs = adjasting_input(&len, argc, argv);
	if (!check_input(len, strs))
	{
		ft_putstr_fd("Error (wrong input)\n", 2);
		deep_free(strs);
		return (0);
	}
	// show_lines(strs, len);
	arr_un = transform_args(strs, len);
	// show_array(arr1, len);
	if (!check_for_doubles(arr_un, len) ||
		!check_for_max_min_int(arr_un, len))
	{
		free(arr_un);
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	arr_sort = bubble_sort(arr_un, len);
	*store = fill_store(arr_un, arr_sort, len);
	free(arr_sort);
	free(arr_un);
	return (1);
	// show_array(arr2, len);
	// a = 0;
	// 
	// show_elem(a);
	// show_elem(a->next);
	// show_elem(a->next->next);
	// show_elem(a->next->next->next);
	// printf("tut?\n");
	// show_stack(&a, len);
}