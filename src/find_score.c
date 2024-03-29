/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_score.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 14:42:04 by mproveme          #+#    #+#             */
/*   Updated: 2022/03/28 13:05:32 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	find_score(t_elem **head_a, t_elem **head_b, t_elem *el)
{
	t_elem	*tmp_a;

	tmp_a = find_appropriate(el->value, head_a);
	el->score_a_r = to_head_r(&tmp_a, head_a);
	el->score_b_r = to_head_r(&el, head_b);
	el->score_a_rr = to_head_rr(&tmp_a, head_a);
	el->score_b_rr = to_head_rr(&el, head_b);
	el->score_ab_r = 0;
	el->score_ab_rr = 0;
	find_route(el);
}
