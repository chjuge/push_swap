/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_args.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 15:29:51 by mproveme          #+#    #+#             */
/*   Updated: 2022/03/28 15:10:04 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

int	*transform_args(char **strs, int count)
{
	int	*arr;
	int	i;

	i = 0;
	arr = malloc(sizeof(int) * count);
	while (i < count)
	{
		arr[i] = ft_atoi(strs[i]);
		i++;
	}
	deep_free(strs);
	return (arr);
}
