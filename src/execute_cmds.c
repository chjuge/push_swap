/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmds.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 17:06:47 by mproveme          #+#    #+#             */
/*   Updated: 2022/03/28 12:49:10 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	execute_cmds(t_elem *el, t_elem **head_a, t_elem **head_b, int mode)
{
	while ((el->score_a_r)-- > 0)
		rotate_a(head_a, mode);
	while ((el->score_b_r)-- > 0)
		rotate_b(head_b, mode);
	while ((el->score_ab_r)-- > 0)
		rotate_rr(head_a, head_b, mode);
	while ((el->score_a_rr)-- > 0)
		rotate_rev_a(head_a, mode);
	while ((el->score_b_rr)-- > 0)
		rotate_rev_b(head_b, mode);
	while ((el->score_ab_rr)-- > 0)
		rotate_rrr(head_a, head_b, mode);
	push_a(head_a, head_b, mode);
}
