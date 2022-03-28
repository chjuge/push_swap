/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 13:52:28 by mproveme          #+#    #+#             */
/*   Updated: 2022/03/28 14:18:37 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

int	check_input(int line_ind, char **arr)
{
	int	i;
	int	len;

	while (--line_ind > 0)
	{
		len = ft_strlen(arr[line_ind]);
		i = len - 1;
		while (i > 0)
		{
			if (!ft_isdigit(arr[line_ind][i]))
				return (0);
			i--;
		}
		if (!ft_isdigit(arr[line_ind][i])
			&& arr[line_ind][i] != '-')
			return (0);
		if (arr[line_ind][0] == '-'
			&& arr[line_ind][1] == '\0')
			return (0);
	}
	return (1);
}
