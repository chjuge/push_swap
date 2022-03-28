/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_head.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 16:45:39 by mproveme          #+#    #+#             */
/*   Updated: 2022/03/28 12:55:51 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

int	to_head_r(t_elem **elem, t_elem **head)
{
	t_elem	*tmp;
	int		steps;

	tmp = *elem;
	steps = 0;
	while (tmp != *head)
	{
		tmp = tmp->prev;
		steps++;
	}
	return (steps);
}

int	to_head_rr(t_elem **elem, t_elem **head)
{
	t_elem	*tmp;
	int		steps;

	tmp = *elem;
	steps = 0;
	while (tmp != *head)
	{
		tmp = tmp->next;
		steps++;
	}
	return (steps);
}
