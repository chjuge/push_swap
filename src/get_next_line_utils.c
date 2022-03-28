/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 15:59:49 by mproveme          #+#    #+#             */
/*   Updated: 2022/03/28 17:25:58 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

int	find_end_of_line(char *remainder)
{
	int	i;

	i = 0;
	while (remainder[i])
	{
		if (remainder[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

int	read_file(char **remainder, int fd)
{
	char	*buf;
	int		buf_len;
	int		check_end;
	int		count;

	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (0);
	check_end = -1;
	count = 0;
	buf_len = read(fd, buf, BUFFER_SIZE);
	buf[buf_len] = '\0';
	while (buf_len && check_end == -1)
	{
		check_end = find_end_of_line(buf);
		*remainder = create_new_remainder(*remainder, buf, buf_len);
		if (check_end < 0)
			buf_len = read(fd, buf, BUFFER_SIZE);
		count++;
	}
	free(buf);
	return (count);
}

int	find_len_next_line(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
	{
		i++;
	}
	if (str[i] == '\0')
		i--;
	return (i);
}
