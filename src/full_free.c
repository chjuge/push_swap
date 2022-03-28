/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   full_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 13:08:58 by mproveme          #+#    #+#             */
/*   Updated: 2022/03/28 12:58:57 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

static void	delete_elem(t_elem *elem)
{
	free(elem);
}

void	full_free(t_store *store)
{
	t_elem	**head_a;
	t_elem	*tmp;

	head_a = &store->a;
	if (!head_a || !(*head_a))
		return ;
	tmp = *head_a;
	while ((*head_a) != 0)
	{
		tmp = cut_head(head_a);
		delete_elem(tmp);
	}
}
