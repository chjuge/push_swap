/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   score_to_zero.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 16:54:19 by mproveme          #+#    #+#             */
/*   Updated: 2022/03/28 12:57:16 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

static void	zero_one(t_elem *el)
{
	el->score_a_r = 0;
	el->score_b_r = 0;
	el->score_ab_r = 0;
	el->score_a_rr = 0;
	el->score_b_rr = 0;
	el->score_ab_rr = 0;
	el->final_score = 0;
	el->route = 0;
}

void	score_to_zero(t_elem **head_b)
{
	t_elem	*tmp;

	tmp = *head_b;
	zero_one(tmp);
	tmp = tmp->next;
	while (tmp != *head_b)
	{
		zero_one(tmp);
		tmp = tmp->next;
	}
}
