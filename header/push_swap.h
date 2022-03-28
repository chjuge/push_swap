/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 12:41:51 by mproveme          #+#    #+#             */
/*   Updated: 2022/03/28 13:08:09 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>

typedef struct s_elem {
	struct s_elem	*next;
	struct s_elem	*prev;
	int				value;
	int				score_a_r;
	int				score_b_r;
	int				score_ab_r;
	int				score_a_rr;
	int				score_b_rr;
	int				score_ab_rr;
	int				final_score;
	int				route;
}	t_elem;

typedef struct s_store {
	t_elem	*a;
	t_elem	*b;
	t_elem	*min_score;
	int		count;
	int		median;
	int		max;
	int		min;
}	t_store;

void		ft_putstr_fd(char *s, int fd);
size_t		ft_strlen(const char *s);
char		*ft_strdup(const char *str);
int			ft_isdigit(int c);
int			ft_strncmp(const char *s1, const char *s2, size_t len);
void		*ft_memcpy(void *dst, const void *src, size_t n);
int			find_lines_count(char **strs);
int			ft_atoi(const char *str);
char		**ft_split(char const *s, char c);
char		**deep_copy(char **strs, int len);
int			check_input(int len, char **arr);
int			parse_args(int argc, char **argv, t_store *store);
int			*transform_args(char **argv, int len, int argc);
int			check_for_doubles(int *arr, int len);
int			check_for_max_min_int(long *arr, int len);
int			check_is_sorted(t_elem **head_a, int len);
int			*bubble_sort(int *arr_old, int len);
void		fill_stack_a(t_elem **head_a, int *arr, int len);
void		deep_free(char **strs);
void		add_front(t_elem **list, t_elem *new);
t_elem		*cut_head(t_elem **head);
t_elem		*find_appropriate(int value, t_elem **head_a);
void		find_score(t_elem **head_a, t_elem **head_b, t_elem *elem_b);
int			to_head_r(t_elem **elem, t_elem **head);
int			to_head_rr(t_elem **elem, t_elem **head);
t_elem		*find_min_score(t_elem **head_b);
void		adjust_cmds(t_elem *elem);
void		push_a(t_elem **head_a, t_elem **head_b, int mode);
void		push_b(t_elem **head_a, t_elem **head_b, int mode);
void		rotate_a(t_elem **head_a, int mode);
void		rotate_b(t_elem **head_b, int mode);
void		rotate_rr(t_elem **head_a, t_elem **head_b, int mode);
void		rotate_rev_a(t_elem **head_a, int mode);
void		rotate_rev_b(t_elem **head_b, int mode);
void		rotate_rrr(t_elem **head_a, t_elem **head_b, int mode);
void		swap_a(t_elem **head_a, int mode);
void		swap_b(t_elem **head_b, int mode);
void		swap_ss(t_elem **head_a, t_elem **head_b, int mode);
int			get_max(int *arr, int len);
int			get_min(int *arr);
int			get_med(int *arr, int len);
t_store		fill_store(int *arr_un, int *arr_sor, int count);
void		fill_stack_b(t_store *store, int mode);
void		find_all_scores(t_elem **head_a, t_elem **head_b);
void		execute_cmds(t_elem *el, t_elem **head_a,
				t_elem **head_b, int mode);
void		big_sort(t_store *store, int mode);
void		mini_sort(t_store *store, int mode);
void		sort_3(t_elem **head, int mode);
void		full_free(t_store *store);
void		score_to_zero(t_elem **head_b);
void		final_rotates(t_elem **head_a, int m);
void		show_is_sorted(t_elem **head_a);
void		sort_fast(t_store *store, int mode);
t_elem		*ft_lstnew(int value);
void		add_back(t_elem **lst, t_elem *new);
void		add_front(t_elem **head, t_elem *new);
char		**adjasting_input(int *len, int argc, char **argv);
int			route_calc(int a, int b);
void		find_route(t_elem *el);
void		adjust_by_route(t_elem *el, int x, int route);

#endif
