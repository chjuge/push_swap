/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 17:36:52 by mproveme          #+#    #+#             */
/*   Updated: 2022/03/26 16:46:51 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	show_stack(t_elem **head, int len)
{
	t_elem *tmp;
	
	// printf("inside 1, head:	%p\n", head);
	tmp = *head;
	// printf("inside 2\n");
	// printf("tmp:	%p\n", tmp);
	for (int i = 0; i < len; i++)
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
		printf("elem:	|	%d	|\n", (int)arr[i]);
		i++;
	}
}

void	show_elem(t_elem *el)
{
	printf("value:	%d\n", el->value);
}
