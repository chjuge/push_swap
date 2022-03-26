/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmds_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 12:42:37 by mproveme          #+#    #+#             */
/*   Updated: 2022/03/26 17:54:27 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void push(t_elem **head1, t_elem **head2)
{
	t_elem *tmp1;

	if (!(*head1))
		return ;
	tmp1 = cut_head(head1);
	// printf("add_front\n");s
	add_front(head2, tmp1);
}

void	push_a(t_elem **a, t_elem **b, int mode)
{
	if (mode)
		ft_putstr_fd("pa\n", 1);
	push(b, a);
}

void	push_b(t_elem **a, t_elem **b, int mode)
{
	if (mode)
		ft_putstr_fd("pb\n", 1);
	push(a, b);
}