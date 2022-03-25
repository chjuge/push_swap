/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 12:41:51 by mproveme          #+#    #+#             */
/*   Updated: 2022/03/25 19:56:35 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>

typedef struct	s_elem {
	t_elem	*next;
	t_elem	*prev;
	int		value;
	int		index;
	int		score_a_r;
	int		score_b_r;
	int		score_ab_r;
	int		score_a_rr;
	int		score_b_rr;
	int		score_ab_rr;
	int		final_score;
	int		route;
}	t_elem;

typedef struct s_store {
	t_elem	**a;
	t_elem	**b;
	t_elem	*min_score;
	int		count;
	int		median;
	int		max;
	int		min;
}	t_store;

void		ft_putstr_fd(char *s, int fd);
size_t		ft_strlen(const char *s);
int			ft_strncmp(const char *s1, const char *s2, size_t len);
char		*ft_strdup(const char *str);
void		*ft_memcpy(void *dst, const void *src, size_t n);
int			ft_isdigit(int c);
int			ft_atoi(const char *str);
char		**ft_split(char const *s, char c);

int			check_input(int len, char **arr);
int			parse_args(int argc, char **argv, t_store *store);
long int	*transform_args(char **argv, int len);
int			check_for_doubles(long *arr, int len);
int			check_for_max_min_int(long *arr, int len);
int			check_is_sorted(int *arr, int len);
long int	*bubble_sort(long *arr_old, int len);

void		fill_stack_a(t_elem **head_a, long *arr, int len);
void		show_stack(t_elem **head, int len);
void		deep_free(char **strs);
int			find_lines_count(char **strs);
void 		show_lines(char **strs, int lines);
void		show_array(long *arr, int len);
void		show_elem(t_elem *el);
void		add_front(t_elem **list, t_elem *new);
t_elem		*cut_head(t_elem **head);
t_elem		*find_appropriate(int value, t_elem **head_a);
void		find_score(t_elem **head_a, t_elem **head_b, t_elem *elem_b);

int			to_head_r(t_elem **elem, t_elem **head);
int			to_head_rr(t_elem **elem, t_elem **head);

t_elem		*find_min_score(t_elem **head_b);
void		adjust_cmds(t_elem *elem);

void		push_a(t_elem **a, t_elem **b, int mode);
void		push_b(t_elem **a, t_elem **b, int mode);
void		rotate_a(t_elem **head, int mode);
void		rotate_b(t_elem **head, int mode);
void		rotate_rr(t_elem **a, t_elem **b, int mode);
void		rotate_rev_a(t_elem **head, int mode);
void		rotate_rev_b(t_elem **head, int mode);
void		rotate_rrr(t_elem **a, t_elem **b, int mode);
void		swap_a(t_elem *stack, int mode);
void		swap_b(t_elem *stack, int mode);
void		swap_ss(t_elem *stack1, t_elem *stack2, int mode);

int			get_max(long *arr, int len);
int			get_min(long *arr);
int			get_med(long *arr, int len);

t_store		fill_store(long *arr_un, long *arr_sor, int count);
void		fill_stack_b(t_store *store);

void		find_all_scores(t_elem **head_a, t_elem **head_b);

void		execute_cmds(t_elem *el, t_elem **head_a, t_elem **head_b, int mode);

void		big_sort(t_store *store);

#endif
