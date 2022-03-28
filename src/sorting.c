/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 18:45:19 by mproveme          #+#    #+#             */
/*   Updated: 2022/03/28 12:56:18 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	big_sort(t_store *store, int mode)
{
	fill_stack_b(store, mode);
	sort_3(&store->a, mode);
	while (store->b != 0)
	{
		score_to_zero(&store->b);
		find_all_scores(&store->a, &store->b);
		store->min_score = find_min_score(&store->b);
		execute_cmds(store->min_score, &store->a, &store->b, mode);
	}
	final_rotates(&store->a, store->min);
}

void	mini_sort(t_store *store, int mode)
{
	if (store->count == 2)
		swap_a(&store->a, mode);
	else if (store->count == 3)
		sort_3(&store->a, mode);
	else
		sort_fast(store, mode);
}
