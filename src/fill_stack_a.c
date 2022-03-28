/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 14:16:18 by mproveme          #+#    #+#             */
/*   Updated: 2022/03/28 12:29:34 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	fill_stack_a(t_elem **head_a, int *arr, int len)
{
	int	i;
	t_elem	*tmp;
	t_elem	*h;

	i = 1;
	if (!(*head_a))
	{
		tmp = ft_lstnew(arr[0]);
		*head_a = tmp;
	}
	h = *head_a;
	while (i < len)
	{
		tmp = ft_lstnew(arr[i]);
		add_back(head_a, tmp);
		i++;
	}
}

