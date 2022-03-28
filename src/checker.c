/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 15:56:34 by mproveme          #+#    #+#             */
/*   Updated: 2022/03/28 18:18:17 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

static void	error_free(t_store *store)
{
	full_free(store);
	ft_putstr_fd("Error\n", 2);
}

static void	ko_free(t_store *store)
{
	full_free(store);
	ft_putstr_fd("KO\n", 1);
}

static void	ok_free(t_store *store)
{
	full_free(store);
	ft_putstr_fd("OK\n", 1);
}

int	main(int argc, char **argv)
{
	t_store	store;

	if (argc < 2)
		return (1);
	if (!parse_args(argc, argv, &store))
		return (0);
	if (!read_cmds(&store))
	{
		error_free(&store);
		return (1);
	}
	if (store.b != 0)
	{
		ko_free(&store);
		return (0);
	}
	if (!check_is_sorted(&store.a, store.count))
	{
		ko_free(&store);
		return (0);
	}
	ok_free(&store);
	return (0);
}
