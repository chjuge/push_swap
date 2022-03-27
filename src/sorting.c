/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 18:45:19 by mproveme          #+#    #+#             */
/*   Updated: 2022/03/27 20:56:46 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void		final_rotates(t_elem **head_a, int m)
{
	int		r;
	int		rr;
	t_elem	*tmp;

	tmp = *head_a;
	while (tmp->value != m)
		tmp = tmp->next;
	r = to_head_r(&tmp, head_a);
	rr = to_head_rr(&tmp, head_a);
	if (r < rr)
	{
		while (r-- > 0)
			rotate_a(head_a, 1);
	}
	else
	{
		while (rr-- > 0)
			rotate_rev_a(head_a, 1);
	}
}

void	big_sort(t_store *store, int mode)
{
	// printf("big sort\n");

	fill_stack_b(store, mode);

	// printf("--------\n");
	// show_stack(&store->a);
	// printf("--------\n");

	

	// printf("big sort ----111\n");
	sort_3(&store->a, mode);


	// printf("--------\n");
	// show_stack(&store->a);
	// printf("--------\n");

	// show_stack(&store->b);
	// printf("--------\n");

	while (store->b != 0)
	{
		score_to_zero(&store->b);
		find_all_scores(&store->a, &store->b);
		// show_final_score(store->b->next);
		store->min_score = find_min_score(&store->b);
		// printf("<<<--------\nminscore elem: %d\n------->>>>\n", store->min_score->value);
		// show_route(store->min_score);
		// printf("--------\n");
		// adjust_cmds(store->min_score);
		// show_route(store->min_score);
		execute_cmds(store->min_score, &store->a, &store->b, mode);
		// push_a(&store->a, &store->b, mode);
	}
	final_rotates(&store->a, store->min);



	// printf("--------\n");
	// show_stack(&store->a);
	// printf("--------\n");
	// printf("--------\n");
	// show_stack(&store->b);
	// printf("--------\n");
}

void	sort_3(t_elem **head, int mode)
{
	int	x;
	int	y;
	int	z;

	x = (*head)->value;
	y = (*head)->next->value;
	z = (*head)->prev->value;
	if (x < y && x < z && y > z)
	{
		swap_a(head, mode);
		rotate_a(head, mode);
	}
	else if (x > y && x < z && y < z)
		swap_a(head, mode);
	else if (x < y && x > z && y > z)
		rotate_rev_a(head, mode);
	else if (x > y && x > z && y < z)
		rotate_a(head, mode);
	else if (x > y && x > z && y > z)
	{
		swap_a(head, mode);
		rotate_rev_a(head, mode);
	}
}

static void	sort_fast(t_store *store, int mode)
{
	// printf("count = %d\n", store->count);
	while (store->count > 3)
	{
		push_b(&store->a, &store->b, mode);
		store->count--;
	}
		sort_3(&store->a, mode);
		while (store->b != 0)
	{
		printf("!!!!!!\n");
		score_to_zero(&store->b);
		// printf("!!!!!!\n");
		show_stack(&store->a);
		printf("!!!!!!\n");
		show_stack(&store->b);
		find_all_scores(&store->a, &store->b);
		printf("!!!!!!\n");
		store->min_score = find_min_score(&store->b);
		printf("!!!!!!\n");
		execute_cmds(store->min_score, &store->a, &store->b, mode);
	}
	final_rotates(&store->a, store->min);
}

void	mini_sort(t_store *store, int mode)
{
	if (store->count == 2)
		swap_a(&store->a, mode);
	else if (store->count == 3)
		sort_3(&store->a, mode);
	else
		sort_fast(store, mode);	
}