/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmds_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 18:52:14 by mproveme          #+#    #+#             */
/*   Updated: 2022/03/25 12:42:03 by mproveme         ###   ########.fr       */
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

void	swap_a(t_elem *stack, int mode)
{
	if (mode)
		write(1, "sa\n", 3);
	swap(&stack);
}

void	swap_b(t_elem *stack, int mode)
{
	if (mode)
		write(1, "sa\n", 3);
	swap(&stack);
}

void	swap_ss(t_elem *stack1, t_elem *stack2, int mode)
{
	if (mode)
		write(1, "ss\n", 3);
	swap(&stack1);
	swap(&stack2);
}
