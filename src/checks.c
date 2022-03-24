/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 17:00:18 by mproveme          #+#    #+#             */
/*   Updated: 2022/03/23 17:28:02 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

int	check_for_doubles(int *arr, int len)
{
	int	i;
	int j;

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

int	check_for_max_min_int(int *arr, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (arr[i] > INT32_MAX || arr[i] < INT32_MIN)
			return (0);
		i++;
	}
	return (1);
}

int	check_is_sorted(int *arr, int len)
{
	int	i;

	i = 1;
	while (i < len)
	{
		if (arr[i] < arr[i-1])
			return (0);
		i++;
	}
	return (1);
}
