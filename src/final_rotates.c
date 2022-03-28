/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_rotates.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 12:34:21 by mproveme          #+#    #+#             */
/*   Updated: 2022/03/28 12:51:53 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	final_rotates(t_elem **head_a, int m)
{
	int		r;
	int		rr;
	t_elem	*tmp;

	tmp = *head_a;
	while (tmp->value != m)
		tmp = tmp->next;
	r = to_head_r(&tmp, head_a);
	rr = to_head_rr(&tmp, head_a);
	if (r < rr)
	{
		while (r-- > 0)
			rotate_a(head_a, 1);
	}
	else
	{
		while (rr-- > 0)
			rotate_rev_a(head_a, 1);
	}
}
