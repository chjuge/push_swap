/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_args.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 15:29:51 by mproveme          #+#    #+#             */
/*   Updated: 2022/03/26 20:39:55 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

long int	*transform_args(char **strs, int count, int argc)
{
	long int	*arr;
	int			i;

	i = 0;
	arr = malloc(sizeof(long int) * count);
	while (i < count)
	{
		arr[i] = ft_atoi(strs[i]);
		// printf("strs[i]	%s	arr[i] =	%d\n", strs[i], (int)arr[i]);
		i++;
	}
	if (argc == 2)
		deep_free(strs);
	return (arr);
}
