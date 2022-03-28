/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 17:00:18 by mproveme          #+#    #+#             */
/*   Updated: 2022/03/28 14:55:31 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

int	check_for_doubles(int *arr, int len)
{
	int	i;
	int	j;

	i = 0;
	while (i < len)
	{
		j = 0;
		while (j < i)
		{
			if (arr[i] == arr[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static int	check_bounds(char *str)
{
	int	len;

	if (str[0] == '-')
	{
		len = ft_strlen(str);
		if (len >= 11)
			if (ft_strncmp(str + 1, "2147483648", len) > 0)
				return (0);
	}
	else
	{
		len = ft_strlen(str);
		if (len >= 10)
			if (ft_strncmp(str, "2147483647", len) > 0)
				return (0);
	}
	return (1);
}

int	check_for_max_min_int(char **strs, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (!check_bounds(strs[i]))
		{
			return (0);
		}
		i++;
	}
	return (1);
}
