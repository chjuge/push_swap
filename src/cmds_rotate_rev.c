/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmds_rotate_rev.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 12:34:37 by mproveme          #+#    #+#             */
/*   Updated: 2022/03/25 12:40:06 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	rotate_rev(t_elem **head)
{
	t_elem	*tmp;

	tmp = *head;
	tmp = tmp->prev;
	*head = tmp;
}

void	rotate_rev_a(t_elem **head, int mode)
{
	if (mode)
		write(1, "rra\n", 4);
	rotate(head);
}

void	rotate_rev_b(t_elem **head, int mode)
{
	if (mode)
		write(1, "rrb\n", 4);
	rotate(head);
}

void	rotate_rrr(t_elem **a, t_elem **b, int mode)
{
	if (mode)
		write(1, "rrr\n", 4);
	rotate_rev(a);
	rotate_rev(b);
}
