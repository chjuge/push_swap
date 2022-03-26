/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 14:16:18 by mproveme          #+#    #+#             */
/*   Updated: 2022/03/26 14:20:03 by mproveme         ###   ########.fr       */
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
	new_el -> next = 0;
	new_el -> prev = 0;
	new_el -> score_a_r = -1;
	new_el -> score_b_r = -1;
	new_el -> score_ab_r = -1;
	new_el -> score_a_rr = -1;
	new_el -> score_b_rr = -1;
	new_el -> score_ab_rr = -1;
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

void	add_front(t_elem **list, t_elem *new)
{
	t_elem *tmp;
	t_elem *tmp_prev;

	if (!(*list))
	{
		*list = new;
		return ;
	}
	tmp = *list;
	tmp_prev = tmp_prev;

	tmp->prev = new;
	tmp_prev->next = new;

	new->next = tmp;
	new->prev = tmp_prev;

	*list = new;
}

t_elem	*cut_head(t_elem **head)
{
	t_elem *tmp;
	t_elem *tmp_prev;
	t_elem *tmp_next;

	tmp = *head;
	tmp_next = tmp->next;
	tmp_prev = tmp->prev;
	tmp->next = 0;
	tmp->prev = 0;
	if (tmp_next == tmp_prev)
	{
		*head = 0;
		return (tmp);
	}
	tmp_prev->next = tmp_next;
	tmp_next->prev = tmp_prev;
	*head = tmp_next;
	return (tmp);
}

void	fill_stack_a(t_elem **head_a, long *arr, int len)
{
	int	i;
	t_elem	*tmp;
	t_elem	*h;

	i = 1;
	h = *head_a;
	if (!h)
	{
		tmp = ft_lstnew(arr[0], 0);
		*head_a = tmp;
		// show_elem(stack);
	}
	while (i < len)
	{
		tmp = ft_lstnew(arr[i], i);
		ft_add_back(head_a, tmp);
		// show_elem(tmp);
		i++;
	}
	// show_elem(stack);
	// show_elem(stack->next);
	// show_elem(stack->next->next);
	// show_elem(stack->next->next->next);
}

