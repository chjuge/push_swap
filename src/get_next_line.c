/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 15:59:38 by mproveme          #+#    #+#             */
/*   Updated: 2022/03/28 17:07:34 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

char	*get_next_line(int fd)
{
	static char	*remainder;
	char		*next_line;

	if (fd < 0 || fd > 256 || read(fd, NULL, 0) < 0)
		return (0);
	if (remainder)
	{
		if ((find_end_of_line(remainder)) != -1)
		{
			next_line = cut_from_remainder(&remainder);
			return (next_line);
		}
		if ((read_file(&remainder, fd)) || remainder[0] != '\0')
		{
			next_line = cut_from_remainder(&remainder);
			return (next_line);
		}
		free(remainder);
	}
	if ((read_file(&remainder, fd)))
	{
		next_line = cut_from_remainder(&remainder);
		return (next_line);
	}
	return (0);
}

char	*create_new_remainder(char *old_rem, char *buf, int buf_len)
{
	char	*new_rem;
	int		len_old_rem;
	int		len_new_rem;

	len_old_rem = ft_strlen(old_rem);
	len_new_rem = len_old_rem + buf_len;
	new_rem = malloc(len_new_rem + 1);
	if (!new_rem)
		return (0);
	if (len_old_rem)
		ft_memcpy(new_rem, old_rem, len_old_rem);
	ft_memcpy(new_rem + len_old_rem, buf, buf_len);
	new_rem[len_new_rem] = '\0';
	free(old_rem);
	return (new_rem);
}

char	*cut_from_remainder(char **old_rem)
{
	int		len_old_rem;
	int		len_new_rem;
	int		len_next_line;
	char	*next_line;
	char	*new_rem;

	len_old_rem = ft_strlen(*old_rem);
	len_next_line = find_len_next_line(*old_rem) + 1;
	len_new_rem = len_old_rem - len_next_line;
	next_line = malloc(len_next_line + 1);
	ft_memcpy(next_line, *old_rem, len_next_line);
	next_line[len_next_line] = '\0';
	new_rem = malloc(len_new_rem + 1);
	ft_memcpy(new_rem, (*old_rem) + len_next_line, len_new_rem);
	new_rem[len_new_rem] = '\0';
	free(*old_rem);
	*old_rem = new_rem;
	return (next_line);
}
