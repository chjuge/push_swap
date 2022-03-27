/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_appropriate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 16:47:55 by mproveme          #+#    #+#             */
/*   Updated: 2022/03/27 14:05:12 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

t_elem	*find_appropriate(int value, t_elem **head_a)
{
	t_elem	*tmp;

	tmp = *head_a;
	while (!(tmp->prev->value < value && value < tmp->value))
			tmp = tmp->next;
	return (tmp);
}
