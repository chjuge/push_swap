/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 18:50:25 by mproveme          #+#    #+#             */
/*   Updated: 2022/03/26 17:54:11 by mproveme         ###   ########.fr       */
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
	a = &store->a;
	b = &store->b;
	// printf("okkkk\n");
	// int n = 0;
	while (cnt > 0)
	{
		el = *a;
		// printf ("n = %d\n", ++n);
		// show_elem(*a);
		if (el->value == store->max ||
			el->value == store->min ||
			el->value == store->median)
			// {
				rotate_a(a, mode);
			// printf("stack a:\n");
			// show_stack(a, cnt);}
		else
		{
		// printf ("go inside push_b\n");
			push_b(a, b, mode);
			// printf("---------\n");
			// show_stack(b, 1);
			// printf("---------\n");
		}
		cnt--;
	}
}
