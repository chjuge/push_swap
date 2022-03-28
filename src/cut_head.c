/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cut_head.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 12:25:49 by mproveme          #+#    #+#             */
/*   Updated: 2022/03/28 18:16:19 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

t_elem	*cut_head(t_elem **head)
{
	t_elem	*tmp;
	t_elem	*tmp_prev;
	t_elem	*tmp_next;

	tmp = *head;
	tmp_next = tmp->next;
	tmp_prev = tmp->prev;
	tmp->next = 0;
	tmp->prev = 0;
	if (tmp_next == tmp)
	{
		*head = 0;
		return (tmp);
	}
	tmp_prev->next = tmp_next;
	tmp_next->prev = tmp_prev;
	*head = tmp_next;
	return (tmp);
}
