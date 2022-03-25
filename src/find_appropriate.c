/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_appropriate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 16:47:55 by mproveme          #+#    #+#             */
/*   Updated: 2022/03/25 16:48:14 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

t_elem	*find_appropriate(int value, t_elem **head_a)
{
	t_elem	*tmp1;
	t_elem	*tmp2;

	tmp1 = *head_a;
	tmp2 = *head_a;
	while (value > tmp1->value && value > tmp2->value)
		{
			tmp1 = tmp1->next;
			tmp2 = tmp2->prev;
		}
	if (value < tmp1->value)
		return (tmp1);
	return (tmp2);
}
