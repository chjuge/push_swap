/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   full_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 13:08:58 by mproveme          #+#    #+#             */
/*   Updated: 2022/03/28 18:15:07 by mproveme         ###   ########.fr       */
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
	t_elem	**head_b;

	head_a = &store->a;
	head_b = &store->b;
	while ((*head_b) != 0)
	{
		tmp = cut_head(head_b);
		delete_elem(tmp);
	}
	while ((*head_a) != 0)
	{
		tmp = cut_head(head_a);
		delete_elem(tmp);
	}
}
