/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adjasting_input.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 12:19:37 by mproveme          #+#    #+#             */
/*   Updated: 2022/03/28 12:45:11 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

char	**adjasting_input(int *len, int argc, char **argv)
{
	char	**strs;

	if (argc > 2)
	{
		*len = argc - 1;
		strs = deep_copy(argv + 1, *len);
		return (strs);
	}
	else
	{
		strs = ft_split(argv[1], ' ');
		*len = find_lines_count(strs);
	}
	return (strs);
}
