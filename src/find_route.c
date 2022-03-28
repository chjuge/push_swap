/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_route.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 13:00:59 by mproveme          #+#    #+#             */
/*   Updated: 2022/03/28 13:07:42 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

static int	min(int x, int y)
{
	if (x < y)
		return (x);
	return (y);
}

void	find_route(t_elem *el)
{
	int	x1;	
	int	x2;	
	int	x3;	
	int	x4;
	int	m;

	x1 = route_calc(el->score_a_r, el->score_b_r);
	x4 = route_calc(el->score_a_rr, el->score_b_rr);
	x2 = el->score_a_r + el->score_b_rr;
	x3 = el->score_a_rr + el->score_b_r;
	m = min(min(x1, x2), min(x3, x4));
	if (m == x1)
		adjust_by_route(el, x1, 1);
	else if (m == x2)
		adjust_by_route(el, x2, 2);
	else if (m == x3)
		adjust_by_route(el, x3, 3);
	else
		adjust_by_route(el, x4, 4);
}
