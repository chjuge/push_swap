/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 12:33:35 by mproveme          #+#    #+#             */
/*   Updated: 2022/03/28 12:56:44 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	sort_3(t_elem **head, int mode)
{
	int	x;
	int	y;
	int	z;

	x = (*head)->value;
	y = (*head)->next->value;
	z = (*head)->prev->value;
	if (x < y && x < z && y > z)
	{
		swap_a(head, mode);
		rotate_a(head, mode);
	}
	else if (x > y && x < z && y < z)
		swap_a(head, mode);
	else if (x < y && x > z && y > z)
		rotate_rev_a(head, mode);
	else if (x > y && x > z && y < z)
		rotate_a(head, mode);
	else if (x > y && x > z && y > z)
	{
		swap_a(head, mode);
		rotate_rev_a(head, mode);
	}
}
