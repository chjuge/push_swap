/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 14:16:18 by mproveme          #+#    #+#             */
/*   Updated: 2022/03/27 16:32:36 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

t_elem	*ft_lstnew(int value)
{
	t_elem	*new_el;

	// printf("in lst_new, value = %d\n", (int)value);
	new_el = malloc(sizeof(t_elem));
	// printf("----> 1 <----\n"); 
	if (!new_el)
		return (0);
	// printf("----> 2 <----\n");
	new_el -> value = value;
	new_el -> next = 0;
	new_el -> prev = 0;
	new_el -> score_a_r = 0;
	new_el -> score_b_r = 0;
	new_el -> score_a_rr = 0;
	new_el -> score_b_rr = 0;
	new_el -> score_ab_r = 0;
	new_el -> score_ab_rr = 0;
	// printf("----> 3 <----\n");
	return (new_el);
}

void ft_add_back(t_elem **lst, t_elem *new)
{
	t_elem	*tmp;

	// if (!lst)
	// 	return ;
	// int n = 0;
	// printf("--- %d ---\n", n++);
	tmp = *lst;
	// printf("--- %d ---\n", n++);
	// show_elem(tmp);
	if (!(tmp->next) && !(tmp->prev))
	{
		// printf("--- %d ---\n", n++);
		tmp->next = new;
		tmp->prev = new;
		new->next = tmp;
		new->prev = tmp;
		return ;
	}
	// printf("--- %d ---\n", n++);
	new->next = tmp;
	new->prev = tmp->prev;
	tmp->prev = new;
	tmp = new->prev;
	tmp->next = new;
}

void	add_front(t_elem **head, t_elem *new)
{
	t_elem *tmp;
	t_elem *tmp_prev;

	// static int n = 0;
	// printf("проход %d\n", ++n);
	if (!(*head))
	{
		*head = new;
		new->next = new;
		new->prev = new;
		return ;
	}
	tmp = *head;
	tmp_prev = tmp->prev;
	tmp->prev = new;
	tmp_prev->next = new;
	new->next = tmp;
	new->prev = tmp_prev;

	*head = new;
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

void	fill_stack_a(t_elem **head_a, int *arr, int len)
{
	int	i;
	t_elem	*tmp;
	t_elem	*h;

	// printf("voshel\n");
	i = 1;
	// printf("1!!\n");
	if (!(*head_a))
	{
		// printf("head:	%p\n", head_a);
		// printf("%d\n", (int)(arr[0]));
		// printf("--- entering lst_new1\n");
		tmp = ft_lstnew(arr[0]);
		// printf("\n\n2!!!!!!!!!\n");
		*head_a = tmp;
		// printf("tmp:	%p\n", tmp);
		// show_elem(tmp);
	}
	// printf("3\n");
	h = *head_a;
	while (i < len)
	{
	// printf("--- entering lst_new2\n");
		tmp = ft_lstnew(arr[i]);
	// printf("--- entering add_back\n");
		ft_add_back(head_a, tmp);
	// printf("---\n");
		// show_elem(tmp);
	// printf("---\n");
		i++;
	}
	// printf("4\n");
	// printf("head:	%p\n", head_a);
	// show_elem((*head_a));
	// show_elem(stack->next);
	// show_elem(stack->next->next);
	// show_elem(stack->next->next->next);
}

