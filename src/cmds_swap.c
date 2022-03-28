/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmds_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 18:52:14 by mproveme          #+#    #+#             */
/*   Updated: 2022/03/28 12:47:53 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	swap(t_elem **h)
{
	t_elem	*head;
	t_elem	*tmp_prev;
	t_elem	*tmp_next;
	t_elem	*tmp;

	head = *h;
	tmp_prev = head->prev;
	tmp_next = head->next;
	tmp = head->next->next;
	tmp->prev = head;
	tmp_prev->next = tmp_next;
	head->next = tmp;
	head->prev = tmp_next;
	tmp_next->next = head;
	tmp_next->prev = tmp_prev;
	*h = tmp_next;
}

void	swap_a(t_elem **head_a, int mode)
{
	if (mode)
		ft_putstr_fd("sa\n", 1);
	swap(head_a);
}

void	swap_b(t_elem **head_b, int mode)
{
	if (mode)
		ft_putstr_fd("sb\n", 1);
	swap(head_b);
}

void	swap_ss(t_elem **head_a, t_elem **head_b, int mode)
{
	if (mode)
		ft_putstr_fd("ss\n", 1);
	swap(head_a);
	swap(head_b);
}
