/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_lst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 14:16:18 by mproveme          #+#    #+#             */
/*   Updated: 2022/03/24 18:16:33 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

t_elem	*ft_lstnew(long value, int index)
{
	t_elem	*new_el;

	new_el = malloc(sizeof(t_elem));
	if (!new_el)
		return (0);
	new_el -> value = value;
	new_el -> index = index;
	new_el -> next = 0;
	new_el -> prev = 0;
	new_el -> score_a_r = -1;
	new_el -> score_a_rr = -1;
	new_el -> score_b_r = -1;
	new_el -> score_b_rr = -1;
	new_el -> score_rrr = -1;
	return (new_el);
}

void ft_add_back(t_elem **lst, t_elem *new)
{
	t_elem	*tmp;

	if (!lst)
		return ;
	tmp = *lst;
	if (!tmp->next && !tmp->prev)
	{
		tmp->next = new;
		tmp->prev = new;
		new->next = tmp;
		new->prev = tmp;
		return ;
	}
	new->next = tmp;
	new->prev = tmp->prev;
	tmp->prev = new;
	tmp = new->prev;
	tmp->next = new;
}

t_elem	*fill_stack(t_elem *stack, long *arr, int len)
{
	int	i;
	t_elem	*tmp;

	i = 1;
	if (!stack)
	{
		stack = ft_lstnew(arr[0], 0);
		// show_elem(stack);
	}
	while (i < len)
	{
		tmp = ft_lstnew(arr[i], i);
		ft_add_back(&stack, tmp);
		// show_elem(tmp);
		i++;
	}
	// show_elem(stack);
	// show_elem(stack->next);
	// show_elem(stack->next->next);
	// show_elem(stack->next->next->next);
	return (stack);
}

