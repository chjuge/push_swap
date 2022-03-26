/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 18:50:25 by mproveme          #+#    #+#             */
/*   Updated: 2022/03/26 14:12:41 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	fill_stack_b(t_store *store, int mode)
{
	int		cnt;
	t_elem	**a;
	t_elem	**b;
	t_elem	*el;

	cnt = store->count;
	a = store->a;
	b = store->b;
	el = *a;
	while (cnt > 0)
	{
		if (el->value == store->max ||
			el->value == store->min ||
			el->value == store->median)
			rotate_a(a, mode);
		else
			push_b(a, b, mode);
		cnt--;
		el = el->next;
	}
}
