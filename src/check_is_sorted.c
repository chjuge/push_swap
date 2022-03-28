/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_is_sorted.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 13:04:35 by mproveme          #+#    #+#             */
/*   Updated: 2022/03/28 12:31:36 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

int	check_is_sorted(t_elem **head_a, int len)
{
	t_elem	*tmp;

	tmp = *head_a;
	while (len > 0 && tmp->next && tmp->next != tmp)
	{
		if (tmp->value > tmp->next->value)
			return (0);
		len--;
		tmp = tmp->next;
	}
	return (1);
}
