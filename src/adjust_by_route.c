/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adjust_by_route.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 13:03:33 by mproveme          #+#    #+#             */
/*   Updated: 2022/03/28 13:08:16 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	adjust_by_route(t_elem *el, int x, int route)
{
	el->final_score = x;
	el->route = route;
	if (route == 1)
	{
		el->score_a_rr = 0;
		el->score_b_rr = 0;
		el->score_ab_rr = 0;
		while (el->score_a_r > 0 && el->score_b_r > 0)
		{
			el->score_a_r--;
			el->score_b_r--;
			el->score_ab_r++;
		}
	}
	else if (route == 4)
	{
		el->score_a_r = 0;
		el->score_b_r = 0;
		el->score_ab_r = 0;
		while (el->score_a_rr > 0 && el->score_b_rr > 0)
		{
			el->score_a_rr--;
			el->score_b_rr--;
			el->score_ab_rr++;
		}
	}
	else if (route == 2)
	{
		el->score_a_rr = 0;
		el->score_b_r = 0;
		el->score_ab_r = 0;
		el->score_ab_rr = 0;
	}
	else
	{
		el->score_a_r = 0;
		el->score_b_rr = 0;
		el->score_ab_r = 0;
		el->score_ab_rr = 0;
	}
}
