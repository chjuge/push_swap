/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmds_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 12:42:37 by mproveme          #+#    #+#             */
/*   Updated: 2022/03/25 13:08:36 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void push(t_elem **head1, t_elem **head2)
{
	t_elem *tmp1;
	t_elem *tmp2;
	t_elem *tmp_next;

	tmp1 = cut_head(head1);
	add_front(head2, tmp1);
}

void	push_a(t_elem **a, t_elem **b, int mode)
{
	if (mode)
		write(1, "pa\n", 3);
	push(b, a);
}

void	push_b(t_elem **a, t_elem **b, int mode)
{
	if (mode)
		write(1, "pb\n", 3);
	push(a, b);
}