/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_store.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 18:11:44 by mproveme          #+#    #+#             */
/*   Updated: 2022/03/26 14:06:32 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

t_store	fill_store(long *arr_un, long *arr_sor, int count)
{
	t_store store;

	store.a = 0;
	store.b = 0;
	store.min_score = 0;
	store.count = count;
	store.max = get_max(arr_sor, count);
	store.min = get_min(arr_sor);
	store.median = get_med(arr_sor, count);
	fill_stack_a(store.a, arr_un, count);
	return (store);
}