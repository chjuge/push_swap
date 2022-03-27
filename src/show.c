/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 17:36:52 by mproveme          #+#    #+#             */
/*   Updated: 2022/03/27 16:37:37 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	show_stack(t_elem **head)
{
	t_elem *tmp;
	
	if (!head)
	{
		printf("stack: null\n");
		return ;
	}
	tmp = *head;
		if (!tmp)
	{
		printf("stack: null\n");
		return ;
	}
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
	printf("addr strs:	%p\n", strs);
	while (i < lines)
	{
		printf("-->	%s	<--\n", strs[i]);
		printf("addr strs[i]:	%p\n", strs[i]);
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
	printf("--->elem<---- 	value:	%d\n", el->value);
	// printf("final score: %d\nroute: %d\n\n", el->final_score, el->route);
}

void	show_final_score(t_elem *el)
{
	printf("final score:	%d\n", el->final_score);
}

void	show_route(t_elem *el)
{
	printf("-----------scores:\n");
	show_elem(el);
	printf("score_a_r:	%d\n", el->score_a_r);
	printf("score_a_rr:	%d\n", el->score_a_rr);
	printf("score_b_r:	%d\n", el->score_b_r);
	printf("score_b_rr:	%d\n", el->score_b_rr);
	printf("score_ab_r:	%d\n", el->score_ab_r);
	printf("score_ab_rr:	%d\n", el->score_ab_rr);
	printf("srores ends -------------\n");
}