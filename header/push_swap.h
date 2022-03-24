/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 12:41:51 by mproveme          #+#    #+#             */
/*   Updated: 2022/03/24 15:18:17 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>

typedef struct	s_elem {
	struct s_elem	*next;
	struct s_elem	*prev;
	int				value;
	int				index;
	int				score_a_r;
	int				score_a_rr;
	int				score_b_r;
	int				score_b_rr;
	int				score_rrr;
}	t_elem;

typedef struct s_store {
	t_elem	*a;
	t_elem	*b;
	long	*arr1;
	long	*arr2;
	int		len;
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
int			parse_args(int argc, char **argv);
long int	*transform_args(char **argv, int len);
int			check_for_doubles(int *arr, int len);
int			check_for_max_min_int(int *arr, int len);
int			check_is_sorted(int *arr, int len);
long int	*bubble_sort(int *arr_old, int len);
void		fill_stack(t_elem *stack, long *arr, int len);

#endif
