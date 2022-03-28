/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_cmds.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 16:07:56 by mproveme          #+#    #+#             */
/*   Updated: 2022/03/28 18:18:42 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

static void	execute_str(char *s, t_store *store, int *flag)
{
	if (ft_strncmp(s, "sa", ft_strlen(s) - 1) == 0)
		swap_a(&store->a, 0);
	else if (ft_strncmp(s, "sb", ft_strlen(s) - 1) == 0)
		swap_b(&store->b, 0);
	else if (ft_strncmp(s, "ss", ft_strlen(s) - 1) == 0)
		swap_ss(&store->a, &store->b, 0);
	else if (ft_strncmp(s, "pa", ft_strlen(s) - 1) == 0)
		push_a(&store->a, &store->b, 0);
	else if (ft_strncmp(s, "pb", ft_strlen(s) - 1) == 0)
		push_b(&store->a, &store->b, 0);
	else if (ft_strncmp(s, "ra", ft_strlen(s) - 1) == 0)
		rotate_a(&store->a, 0);
	else if (ft_strncmp(s, "rb", ft_strlen(s) - 1) == 0)
		rotate_b(&store->b, 0);
	else if (ft_strncmp(s, "rr", ft_strlen(s) - 1) == 0)
		rotate_rr(&store->a, &store->b, 0);
	else if (ft_strncmp(s, "rra", ft_strlen(s) - 1) == 0)
		rotate_rev_a(&store->a, 0);
	else if (ft_strncmp(s, "rrb", ft_strlen(s) - 1) == 0)
		rotate_rev_b(&store->b, 0);
	else if (ft_strncmp(s, "rrr", ft_strlen(s) - 1) == 0)
		rotate_rrr(&store->a, &store->b, 0);
	else
		*flag = 0;
}

int	read_cmds(t_store *store)
{
	char	*tmp;
	int		flag;

	tmp = get_next_line(0);
	flag = 1;
	while (tmp && flag)
	{
		execute_str(tmp, store, &flag);
		free(tmp);
		if (flag)
			tmp = get_next_line(0);
	}
	if (!flag)
		return (0);
	return (1);
}
