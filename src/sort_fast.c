/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_fast.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 12:35:48 by mproveme          #+#    #+#             */
/*   Updated: 2022/03/28 12:36:02 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	sort_fast(t_store *store, int mode)
{
	while (store->count > 3)
	{
		push_b(&store->a, &store->b, mode);
		store->count--;
	}
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
