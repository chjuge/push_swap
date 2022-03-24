/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_args.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 15:29:51 by mproveme          #+#    #+#             */
/*   Updated: 2022/03/24 13:59:52 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

long int	*transform_args(char **strs, int count)
{
	long int	*arr;
	int			i;

	i = 0;
	arr = malloc(sizeof(long int) * count);
	while (i < count)
	{
		arr[i] = ft_atoi(strs[i]);
		i++;
	}
	deep_free(strs);
	return (arr);
}
