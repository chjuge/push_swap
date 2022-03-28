/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_appropriate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 16:47:55 by mproveme          #+#    #+#             */
/*   Updated: 2022/03/28 11:59:48 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

static t_elem	*find_min_el(t_elem **head_a)
{
	t_elem	*min;
	t_elem	*tmp;

	min = *head_a;
	tmp = (*head_a)->next;
	while (tmp != *head_a)
	{
		if (tmp->value < min->value)
			min = tmp;
		tmp = tmp->next;
	}
	return (min);
}

static int	find_stack_len(t_elem **head)
{
	int		len;
	t_elem	*tmp;

	len = 1;
	tmp = (*head)->next;
	while (tmp != *head)
	{
		len++;
		tmp = tmp->next;
	}
	return (len);
}

t_elem	*find_appropriate(int value, t_elem **head_a)
{
	t_elem	*tmp;
	int		len;

	tmp = *head_a;
	len = find_stack_len(head_a);
	while (!(tmp->prev->value < value && value < tmp->value))
	{
		// printf("hi!\n");
		tmp = tmp->next;
		len--;
		if (len == 0)
			return (find_min_el(head_a));
	}
	return (tmp);
}
