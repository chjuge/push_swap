/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adjust_cmds.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 16:57:22 by mproveme          #+#    #+#             */
/*   Updated: 2022/03/25 19:29:21 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	adjust_1(t_elem *el)
{
	el->score_a_rr = 0;
	el->score_b_rr = 0;
	el->score_ab_rr = 0;
}

void	adjust_2(t_elem *el)
{
	el->score_a_rr = 0;
	el->score_b_r = 0;
	el->score_ab_rr = 0;
	el->score_ab_r = 0;
}

void	adjust_3(t_elem *el)
{
	el->score_a_r = 0;
	el->score_b_rr = 0;
	el->score_ab_rr = 0;
	el->score_ab_r = 0;
}

void	adjust_4(t_elem *el)
{
	el->score_a_r = 0;
	el->score_b_r = 0;
	el->score_ab_r = 0;
}

void	adjust_cmds(t_elem *el)
{
	if (el->route == 1)
		adjust_1(el);
	else if (el->route == 2)
		adjust_2(el);
	else if (el->route == 3)
		adjust_3(el);
	else
		adjust_4(el);
}
