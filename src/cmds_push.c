/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmds_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 12:42:37 by mproveme          #+#    #+#             */
/*   Updated: 2022/03/28 12:47:09 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	push(t_elem **head1, t_elem **head2)
{
	t_elem	*tmp1;

	if (!(*head1))
		return ;
	tmp1 = cut_head(head1);
	add_front(head2, tmp1);
}

void	push_a(t_elem **head_a, t_elem **head_b, int mode)
{
	if (mode)
		ft_putstr_fd("pa\n", 1);
	push(head_b, head_a);
}

void	push_b(t_elem **head_a, t_elem **head_b, int mode)
{
	if (mode)
		ft_putstr_fd("pb\n", 1);
	push(head_a, head_b);
}
