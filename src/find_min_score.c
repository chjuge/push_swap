/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_min_score.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 16:50:36 by mproveme          #+#    #+#             */
/*   Updated: 2022/03/25 16:57:04 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

t_elem	*find_min_score(t_elem **head_b)
{
	t_elem	*min;
	t_elem	*tmp;

	min = *head_b;
	tmp = min->next;
	while (tmp != *head_b)
	{
		if (tmp->final_score < min->final_score)
			min = tmp;
		tmp = tmp->next;
	}
	return (min);
}
