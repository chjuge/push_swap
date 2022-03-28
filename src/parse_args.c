/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 13:55:39 by mproveme          #+#    #+#             */
/*   Updated: 2022/03/28 12:58:16 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

int	parse_args(int argc, char **argv, t_store *store)
{
	char	**strs;
	int		len;
	int		*arr_un;
	int		*arr_sort;

	strs = adjasting_input(&len, argc, argv);
	if (!check_input(len, strs))
	{
		ft_putstr_fd("Error (wrong input)\n", 2);
		if (argc == 2)
			return (0);
	}
	arr_un = transform_args(strs, len, argc);
	if (!check_for_doubles(arr_un, len))
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	arr_sort = bubble_sort(arr_un, len);
	*store = fill_store(arr_un, arr_sort, len);
	return (1);
}
