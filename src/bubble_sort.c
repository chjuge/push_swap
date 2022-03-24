/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 15:11:24 by mproveme          #+#    #+#             */
/*   Updated: 2022/03/24 17:27:50 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

static void	swap(long *a, long *b)
{
	long tmp;
	tmp = *a;
	*b = *a;
	*a = tmp;
}

static long int	*copy_arr(long *arr_old, int len)
{
	long int	*new_arr;
	int			i;

	new_arr = malloc(sizeof(int) * len);
	i = 0;
	while (i < len)
	{
		new_arr[i] = arr_old[i];
		i++;
	}
	return (new_arr);
}

long int	*bubble_sort(long *arr_old, int len)
{
	long int	*arr_new;
	int			i;
	int 		j;

	i = 0;
	arr_new = copy_arr(arr_old, len);
	while (i < len - 1)
	{
		j = 0;
		while (j < len - i - 1)
		{
			if (arr_new[j] > arr_new[j+1])
				swap(&arr_new[j], &arr_new[j+1]);
			j++;
		}
		i++;
	}
	return (arr_new);
}
