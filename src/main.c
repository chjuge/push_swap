/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 12:41:54 by mproveme          #+#    #+#             */
/*   Updated: 2022/03/28 12:16:58 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

int	main(int argc, char **argv)
{
	t_store	store;

	if (argc < 2)
		return (1);
	if (!parse_args(argc, argv, &store))
		return (0);
	if (store.count == 1 || check_is_sorted(&store.a, store.count))
	{
		return (0);
	}
	if (store.count <= 5)
		mini_sort(&store, 1);
	else
	{
		big_sort(&store, 1);
	}
	return (0);
}
