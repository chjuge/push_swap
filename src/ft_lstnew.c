/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 12:28:16 by mproveme          #+#    #+#             */
/*   Updated: 2022/03/28 12:28:31 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

t_elem	*ft_lstnew(int value)
{
	t_elem	*new_el;

	new_el = malloc(sizeof(t_elem));
	if (!new_el)
		return (0);
	new_el -> value = value;
	new_el -> next = 0;
	new_el -> prev = 0;
	new_el -> score_a_r = 0;
	new_el -> score_b_r = 0;
	new_el -> score_a_rr = 0;
	new_el -> score_b_rr = 0;
	new_el -> score_ab_r = 0;
	new_el -> score_ab_rr = 0;
	return (new_el);
}
