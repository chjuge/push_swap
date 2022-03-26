/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmds_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 19:16:24 by mproveme          #+#    #+#             */
/*   Updated: 2022/03/26 14:24:46 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	rotate(t_elem **head)
{
	t_elem	*tmp;

	tmp = *head;
	tmp = tmp->next;
	*head = tmp;
}

void	rotate_a(t_elem **head, int mode)
{
	if (mode)
		ft_putstr_fd("ra\n", 1);
	rotate(head);
}

void	rotate_b(t_elem **head, int mode)
{
	if (mode)
		ft_putstr_fd("rb\n", 1);
	rotate(head);
}

void	rotate_rr(t_elem **a, t_elem **b, int mode)
{
	if (mode)
		ft_putstr_fd("rrr\n", 1);
	rotate(a);
	rotate(b);
}