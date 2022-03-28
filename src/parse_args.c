/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 13:55:39 by mproveme          #+#    #+#             */
/*   Updated: 2022/03/28 15:15:50 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

static void	error_and_free(char **strs)
{
	ft_putstr_fd("Error\n", 2);
	deep_free(strs);
}

static void	error_and_free_arr(int *arr)
{
	ft_putstr_fd("Error\n", 2);
	free(arr);
}

int	parse_args(int argc, char **argv, t_store *store)
{
	char	**strs;
	int		len;
	int		*arr_un;
	int		*arr_sort;

	strs = adjasting_input(&len, argc, argv);
	if (!check_input(len, strs)
		|| !check_for_max_min_int(strs, len))
	{
		error_and_free(strs);
		return (0);
	}
	arr_un = transform_args(strs, len);
	if (!check_for_doubles(arr_un, len))
	{
		error_and_free_arr(arr_un);
		return (0);
	}
	arr_sort = bubble_sort(arr_un, len);
	*store = fill_store(arr_un, arr_sort, len);
	return (1);
}
