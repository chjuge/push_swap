/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_score.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 14:42:04 by mproveme          #+#    #+#             */
/*   Updated: 2022/03/27 19:40:15 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

static int	min(int x, int y)
{
	if (x < y)
		return (x);
	return (y);
}

static void	adjust_by_route(t_elem *el, int x, int route)
{
	el->final_score = x;
	el->route = route;
	if (route == 1)
	{
		el->score_a_rr = 0;
		el->score_b_rr = 0;
		el->score_ab_rr = 0;
		while (el->score_a_r > 0 && el->score_b_r > 0)
		{
			el->score_a_r--;
			el->score_b_r--;
			el->score_ab_r++;
		}
	}
	else if (route == 4)
	{
		el->score_a_r = 0;
		el->score_b_r = 0;
		el->score_ab_r = 0;
		while (el->score_a_rr > 0 && el->score_b_rr > 0)
		{
			el->score_a_rr--;
			el->score_b_rr--;
			el->score_ab_rr++;
		}
	}
	else if (route == 2)
	{
		el->score_a_rr = 0;
		el->score_b_r = 0;
		el->score_ab_r = 0;
		el->score_ab_rr = 0;
	}
	else
	{
		el->score_a_r = 0;
		el->score_b_rr = 0;
		el->score_ab_r = 0;
		el->score_ab_rr = 0;
	}
}

int	route_calc(int a, int b)
{
	int	res;

	res = a + b;
	while (a > 0 && b > 0)
	{
		res--;
		a--;
		b--;
	}
	return (res);
}

static void	find_route(t_elem *el)
{
	int	x1;	
	int	x2;	
	int	x3;	
	int	x4;
	int m;

	// x1 = el->score_a_r + el->score_b_r + el->score_ab_r;
	x1 = route_calc(el->score_a_r, el->score_b_r);
	// x4 = el->score_a_rr + el->score_b_rr + el->score_ab_rr;
	x4 = route_calc(el->score_a_rr, el->score_b_rr);
	x2 = el->score_a_r + el->score_b_rr;
	x3 = el->score_a_rr + el->score_b_r;
	m = min(min(x1, x2),min(x3, x4));
	if (m == x1)
		adjust_by_route(el, x1, 1);
	else if (m == x2)
		adjust_by_route(el, x2, 2);
	else if (m == x3)
		adjust_by_route(el, x3, 3);
	else
		adjust_by_route(el, x4, 4);
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
	// printf("value:	%d\n", el->value);
	// printf("appropriate: %d\n", tmp_a->value);
	// printf("a_r:	%d\n", el->score_a_r);
	// printf("b_r:	%d\n", el->score_b_r);
	// printf("ab_r:	%d\n", el->score_ab_r);
	// printf("a_rr:	%d\n", el->score_a_rr);
	// printf("b_rr:	%d\n", el->score_b_rr);
	// printf("ab_rr:	%d\n", el->score_ab_rr);
	// printf("route:	%d\n", el->route);
	// printf("f_score:	%d\n\n", el->final_score);

	// adjust_cmds(el);	
	// printf("value:	%d\n", el->value);
	// printf("appropriate: %d\n", tmp_a->value);
	// printf("a_r:		%d\n", el->score_a_r);
	// printf("b_r:		%d\n", el->score_b_r);
	// printf("ab_r:		%d\n", el->score_ab_r);
	// printf("a_rr:		%d\n", el->score_a_rr);
	// printf("b_rr:		%d\n", el->score_b_rr);
	// printf("ab_rr:		%d\n", el->score_ab_rr);
	// printf("route:		%d\n", el->route);
	// printf("f_score:	%d\n\n", el->final_score);
	find_route(el);

	// printf("value:	%d\n", el->value);
	// printf("appropriate: %d\n", tmp_a->value);
	// printf("a_r:		%d\n", el->score_a_r);
	// printf("b_r:		%d\n", el->score_b_r);
	// printf("ab_r:		%d\n", el->score_ab_r);
	// printf("a_rr:		%d\n", el->score_a_rr);
	// printf("b_rr:		%d\n", el->score_b_rr);
	// printf("ab_rr:		%d\n", el->score_ab_rr);
	// printf("route:		%d\n", el->route);
	// printf("f_score:	%d\n\n", el->final_score);
	// find_optimum(&el);
	// printf("----------------------\n");
	// printf("a_r:	%d\n", el->score_a_r);
	// printf("b_r:	%d\n", el->score_b_r);
	// printf("a_rr:	%d\n", el->score_a_rr);
	// printf("b_rr:	%d\n", el->score_b_rr);
	// printf("ab_r:	%d\n", el->score_ab_r);
	// printf("ab_rr:	%d\n", el->score_ab_rr);
	// printf("route:	%d\n", el->route);
	// printf("----------------------\n");
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