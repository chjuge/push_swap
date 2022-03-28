/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_all_scores.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 12:59:56 by mproveme          #+#    #+#             */
/*   Updated: 2022/03/28 13:00:24 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	find_all_scores(t_elem **head_a, t_elem **head_b)
{
	t_elem	*a;
	t_elem	*b;
	t_elem	*tmp;

	a = *head_a;
	b = *head_b;
	tmp = b;
	find_score(head_a, head_b, tmp);
	tmp = tmp->next;
	while (tmp != *head_b)
	{
		find_score(head_a, head_b, tmp);
		tmp = tmp->next;
	}
}
