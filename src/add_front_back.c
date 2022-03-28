/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_front_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 12:29:19 by mproveme          #+#    #+#             */
/*   Updated: 2022/03/28 12:29:39 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void add_back(t_elem **lst, t_elem *new)
{
	t_elem	*tmp;

	tmp = *lst;
	if (!(tmp->next) && !(tmp->prev))
	{
		tmp->next = new;
		tmp->prev = new;
		new->next = tmp;
		new->prev = tmp;
		return ;
	}
	new->next = tmp;
	new->prev = tmp->prev;
	tmp->prev = new;
	tmp = new->prev;
	tmp->next = new;
}

void	add_front(t_elem **head, t_elem *new)
{
	t_elem *tmp;
	t_elem *tmp_prev;

	if (!(*head))
	{
		*head = new;
		new->next = new;
		new->prev = new;
		return ;
	}
	tmp = *head;
	tmp_prev = tmp->prev;
	tmp->prev = new;
	tmp_prev->next = new;
	new->next = tmp;
	new->prev = tmp_prev;
	*head = new;
}
