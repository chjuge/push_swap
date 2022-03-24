/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 13:52:28 by mproveme          #+#    #+#             */
/*   Updated: 2022/03/23 15:05:22 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

int	check_input(int line_ind, char **arr)
{
	int	i;
	int	len;

	while (--line_ind >= 0)
	{
		i = 0;
		len = ft_strlen(arr[line_ind]);
		while (i < len)
		{
			if (!ft_isdigit(arr[line_ind][i]))
				return (0);
			i++;
		}
	}
	return (1);
}
