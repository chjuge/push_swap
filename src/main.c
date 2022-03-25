/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 12:41:54 by mproveme          #+#    #+#             */
/*   Updated: 2022/03/25 19:04:44 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

int	main(int argc, char **argv)
{
	t_store	store;

	if (argc < 2)
	{
		ft_putstr_fd("Wrong number of params\n", 2);
		return (1);
	}
	if (!parse_args(argc, argv, &store))
		return (1);
	if (store.count > 3)
		big_sort(&store);
	else
		mini_sort(&store);
	return (0);
}
