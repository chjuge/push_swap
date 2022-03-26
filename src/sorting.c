/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 18:45:19 by mproveme          #+#    #+#             */
/*   Updated: 2022/03/26 19:12:05 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	big_sort(t_store *store, int mode)
{
	// printf("big sort\n");
	fill_stack_b(store, mode);
	show_stack(&store->a);
	printf("--------\n");
	show_stack(&store->b);
	// printf("big sort ----111\n");
	sort_3(&store->a, mode);
	printf("--------\n");
	show_stack(&store->a);
	// while ((store->b) != 0)
	// {
	// 	find_all_scores(store->a, store->b);
	// 	store->min_score = find_min_score(store->b);
	// 	adjust_cmds(store->min_score);
	// 	execute_cmds(store->min_score, store->a, store->b, mode);
	// 	push_a(store->a, store->b, mode);
	// }
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

void	mini_sort(t_store *store, int mode)
{
	if (store->count == 2)
		swap_a(&store->a, mode);
	else 
		sort_3(&store->a, mode);	
}