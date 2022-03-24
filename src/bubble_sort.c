/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 15:11:24 by mproveme          #+#    #+#             */
/*   Updated: 2022/03/23 16:56:37 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

static void	swap(int *a, int *b)
{
	int tmp;
	tmp = *a;
	*b = *a;
	*a = tmp;
}

static long int	*copy_arr(int *arr_old, int len)
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

long int	*bubble_sort(int *arr_old, int len)
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
