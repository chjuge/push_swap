/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 12:41:54 by mproveme          #+#    #+#             */
/*   Updated: 2022/03/26 19:59:20 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

int	main(int argc, char **argv)
{
	t_store	store;

	if (argc < 2)
		return (1);
	// printf("-------1\n");
	if (!parse_args(argc, argv, &store))
		return (0);
	// printf("successfull parsed \n");
	show_stack(&store.a);
	printf("count: %d max: %d min: %d med: %d\n", store.count, store.max, store.min, store.median);
	if (store.count == 1 || check_is_sorted(&store.a, store.count))
	{
		// printf("sorted or count == 1\n");
		// full_free(&store);
		return (0);
	}
	// printf("store.count:	%d\n", store.count);
	if (store.count <= 3)
		mini_sort(&store, 1);
	else
		big_sort(&store, 1);
	// full_free(&store);
	return (0);
}
