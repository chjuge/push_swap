/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_max_min_med.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 18:15:35 by mproveme          #+#    #+#             */
/*   Updated: 2022/03/27 14:59:05 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

int	get_max(int *arr, int len)
{
	return (arr[len - 1]);
}

int	get_min(int *arr)
{
	return (arr[0]);
}

int	get_med(int *arr, int len)
{
	int	x;

	x = len/2;
	return (arr[x]);
}
