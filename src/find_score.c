/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_score.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 14:42:04 by mproveme          #+#    #+#             */
/*   Updated: 2022/03/27 17:17:57 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

static int	optim_z(int x, int y, int z)
{
	while (x > 0 || y > 0)
	{
		z++;
		x--;
		y--;
	}
	return (x+y+z);
}

static int	find_route(int a, int b, int c, int d)
{
	if (a <= b && a <= c && a <= d)
		return (1);
	if (b <= a && b <= c && b <= d)
		return (2);
	if (c <= a && c <= b && c <= d)
		return (3);
	return (4);
}

static int	find_final_score(t_elem *elem)
{
	if (elem->route == 2)
		return (elem->score_a_r + elem->score_b_rr);
	if (elem->route == 3)
		return (elem->score_a_rr + elem->score_b_r);
	if (elem->route == 1)
	{
		while (elem->score_a_r > 0 && elem->score_b_r > 0)
		{
			(elem->score_a_r)--;
			(elem->score_b_r)--;
			(elem->score_ab_r)++;
		}
		return (elem->score_a_r + elem->score_b_r + elem->score_ab_r);
	}
	while (elem->score_a_rr > 0 && elem->score_b_rr > 0)
	{
		(elem->score_a_rr)--;
		(elem->score_b_rr)--;
		(elem->score_ab_rr)++;
	}
	return (elem->score_a_rr + elem->score_b_rr + elem->score_ab_rr);
}

void	find_optimum(t_elem **el)
{
	int	route1;
	int	route2;
	int	route3;
	int	route4;
	t_elem	*tmp;

	tmp = *el;
	route2 = tmp->score_a_r + tmp->score_b_rr;
	route3 = tmp->score_a_rr + tmp->score_b_r;
	route1 = optim_z(tmp->score_a_r, tmp->score_b_r, 0);
	route4 = optim_z(tmp->score_a_rr, tmp->score_b_rr, 0);
	tmp->route = find_route(route1, route2, route3, route4);
	tmp->final_score = find_final_score(tmp);
}

void	find_score(t_elem **head_a, t_elem **head_b, t_elem *el)
{
	t_elem	*tmp_a;

	tmp_a = find_appropriate(el->value, head_a);
	el->score_a_r = to_head_r(&tmp_a, head_a);
	el->score_b_r = to_head_r(&el, head_b);
	el->score_a_rr = to_head_rr(&tmp_a, head_a);
	el->score_b_rr = to_head_rr(&el, head_b);
	el->score_ab_r = 0;
	el->score_ab_rr = 0;
	printf("value:	%d\n", el->value);
	printf("appropriate: %d\n", tmp_a->value);
	printf("a_r:	%d\n", el->score_a_r);
	printf("b_r:	%d\n", el->score_b_r);
	printf("a_rr:	%d\n", el->score_a_rr);
	printf("b_rr:	%d\n", el->score_b_rr);
	printf("ab_r:	%d\n", el->score_ab_r);
	printf("ab_rr:	%d\n", el->score_ab_rr);
	printf("route:	%d\n", el->route);
	find_optimum(&el);
	printf("----------------------\n");
	printf("a_r:	%d\n", el->score_a_r);
	printf("b_r:	%d\n", el->score_b_r);
	printf("a_rr:	%d\n", el->score_a_rr);
	printf("b_rr:	%d\n", el->score_b_rr);
	printf("ab_r:	%d\n", el->score_ab_r);
	printf("ab_rr:	%d\n", el->score_ab_rr);
	printf("route:	%d\n", el->route);
	printf("----------------------\n");
	// show_final_score(el);
}

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