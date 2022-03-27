/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 12:45:20 by mproveme          #+#    #+#             */
/*   Updated: 2022/03/27 13:08:44 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	ft_putstr_fd(char *s, int fd)
{
	write(fd, s, ft_strlen(s));
}

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *str)
{
	char	*new_str;
	int		len;
	int		i;

	len = ft_strlen(str);
	new_str = malloc(sizeof(char) * (len + 1));
	if (!new_str)
		return (0);
	i = 0;
	while (i < len)
	{
		new_str[i] = str[i];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}

int	ft_isdigit(int c)
{
	if (c < '0' || c > '9')
		return (0);
	return (1);
}

int	ft_strncmp(const char *s1, const char *s2, size_t len)
{
	unsigned char	tmp1;
	unsigned char	tmp2;

	while (len-- > 0)
	{
		tmp1 = (unsigned char) *s1++;
		tmp2 = (unsigned char) *s2++;
		if (tmp1 != tmp2)
			return (tmp1 - tmp2);
		if (tmp1 == '\0')
			return (0);
	}
	return (0);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (dst);
	if (!src && !dst)
		return (0);
	while (i < n)
	{
		((char *)(dst))[i] = ((char *)(src))[i];
		i++;
	}
	return ((char *)(dst));
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	int	i;

	if (!len || dst == src)
		return (dst);
	if (!src && !dst)
		return (0);
	if (dst > src && dst - src < (long)len)
	{
		i = len;
		while (--i >= 0)
			((char *)(dst))[i] = ((char *)(src))[i];
		return (dst);
	}
	if (src > dst && src - dst < (long)len)
	{
		i = -1;
		while (++i < (int)len)
			((char *)(dst))[i] = ((char *)(src))[i];
		return (dst);
	}
	ft_memcpy(dst, src, len);
	return (dst);
}
