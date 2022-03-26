/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 13:55:39 by mproveme          #+#    #+#             */
/*   Updated: 2022/03/26 20:41:21 by mproveme         ###   ########.fr       */
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

char	**deep_copy(char **strs, int len)
{
	char	**new_strs;
	int		i;

	// show_lines(strs, len);
	new_strs = malloc(sizeof(char*) * len + 1);
	i = 0;
	new_strs[len] = NULL;
	while (i < len)
	{
		// printf("strs: %s\n",strs[i]);
		new_strs[i] = ft_strdup(strs[i]);
		// printf("new: %s\n",new_strs[i]);
		i++;
	}
	// printf("new[0]: %s\n",new_strs[0]);
	// printf("new[0]: %s\n",new_strs[0]);
	// printf("!!!!!!!!!!!!!\n");
	// show_lines(new_strs, len);
	return (new_strs);
}

static char **adjasting_input(int *len, int argc, char **argv)
{
	char	**strs;

	if (argc > 2) 
	{
		*len = argc - 1;
		// show_lines(argv+1, argc-1);
		// strs = deep_copy(argv + 1, *len);
		return (argv + 1);
	}
	else
	{
		strs = ft_split(argv[1], ' ');
		*len = find_lines_count(strs);
	}
	// show_lines(strs, *len);
	return (strs);
}



int	parse_args(int argc, char **argv, t_store *store)
{
	char		**strs;
	int	 		len;
	long int	*arr_un;
	long int	*arr_sort;

	// printf("padaet tut - 1\n");
	strs = adjasting_input(&len, argc, argv);
	// show_lines(strs, len);
	if (!check_input(len, strs))
	{
		ft_putstr_fd("Error (wrong input)\n", 2);
		if (argc == 2)
			deep_free(strs);
		return 0;
	}
	// printf("padaet tut - 2\n");
	// show_lines(strs, len);
	arr_un = transform_args(strs, len, argc);
	// show_array(arr1, len);
	// printf("padaet tut - 3\n");
	if (!check_for_doubles(arr_un, len) ||
		!check_for_max_min_int(arr_un, len))
	{
		free(arr_un);
		ft_putstr_fd("Error\n", 2);
		return 0;
	}
	// printf("padaet tut - 4\n");
	arr_sort = bubble_sort(arr_un, len);

	show_array(arr_un, len);
	printf("--------\n");
	show_array(arr_sort, len);
	
	printf("padaet tut - 5\n");
	*store = fill_store(arr_un, arr_sort, len);

	printf("padaet tut - 6\n");
	free(arr_un);
	printf("padaet tut - 7\n");
	free(arr_sort);
	// printf("successfull parsed \n");
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