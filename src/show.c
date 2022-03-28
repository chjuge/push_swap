/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 17:36:52 by mproveme          #+#    #+#             */
/*   Updated: 2022/03/28 12:57:01 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	show_is_sorted(t_elem **head_a)
{
	t_elem	*tmp;
	int		flag;

	flag = 1;
	tmp = *head_a;
	while (tmp->next != *head_a)
	{
		if (tmp->value > tmp->next->value)
		{
			flag = 0;
			break ;
		}
		tmp = tmp->next;
	}
	if (flag)
		ft_putstr_fd("sorted, OK!\n", 1);
	else
		ft_putstr_fd("not sorted, KO!\n", 1);
}
