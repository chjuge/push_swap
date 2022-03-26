/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 17:36:52 by mproveme          #+#    #+#             */
/*   Updated: 2022/03/26 19:47:57 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	show_stack(t_elem **head)
{
	t_elem *tmp;
	
	tmp = *head;
	show_elem(tmp);
	tmp = tmp->next;
	while (tmp != *head)
	{
		show_elem(tmp);
		tmp = tmp->next;
	}
}

void show_lines(char **strs, int lines)
{
	int	i;

	i = 0;
	while (i < lines)
	{
		printf("-->	%s	<--\n", strs[i]);
		i++;
	}
}

void show_array(long *arr, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		printf("%d ", (int)arr[i]);
		i++;
	}
	printf("\n");
}

void	show_elem(t_elem *el)
{
	printf("value:	%d\n", el->value);
}
