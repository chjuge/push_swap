/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_max_min_med.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 18:15:35 by mproveme          #+#    #+#             */
/*   Updated: 2022/03/25 18:20:29 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

int	get_max(long *arr, int len)
{
	return (arr[len - 1]);
}

int	get_min(long *arr)
{
	return (arr[0]);
}

int	get_med(long *arr, int len)
{
	return (arr[(len + 1)/2]);
}
