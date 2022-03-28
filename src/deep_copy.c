/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deep_copy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 12:20:22 by mproveme          #+#    #+#             */
/*   Updated: 2022/03/28 12:20:57 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

char	**deep_copy(char **strs, int len)
{
	char	**new_strs;
	int		i;

	new_strs = malloc(sizeof(char *) * len + 1);
	i = 0;
	new_strs[len] = NULL;
	while (i < len)
	{
		new_strs[i] = ft_strdup(strs[i]);
		i++;
	}

	return (new_strs);
}
