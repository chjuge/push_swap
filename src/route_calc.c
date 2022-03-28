/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   route_calc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 13:05:17 by mproveme          #+#    #+#             */
/*   Updated: 2022/03/28 13:05:27 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

int	route_calc(int a, int b)
{
	int	res;

	res = a + b;
	while (a > 0 && b > 0)
	{
		res--;
		a--;
		b--;
	}
	return (res);
}
