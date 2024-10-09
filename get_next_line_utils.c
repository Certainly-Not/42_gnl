/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elallema <elallema@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 17:07:52 by elallema          #+#    #+#             */
/*   Updated: 2023/03/17 17:46:56 by elallema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		j;

	if (!s1 || !s2)
	{
		if (s1)
			return ((char *)s1);
		if (s2)
			return ((char *)s2);
		return (NULL);
	}
	i = ft_strlen(s1);
	j = ft_strlen(s2);
	str = malloc(sizeof(char) * (i + j + 1));
	if (!str)
		return (NULL);
	ft_memcpy(str, s1, i);
	ft_memcpy(str + i, s2, j);
	str[i + j] = 0;
	return (str);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	if (!str)
	{
		return (0);
	}
	i = 0;
	while (str[i])
		++i;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	size;
	size_t	i;

	if (!s)
		return (NULL);
	i = ft_strlen(s);
	if (i < start)
		size = 0;
	else if (i - start < len)
		size = i - start;
	else
		size = len;
	substr = malloc(sizeof(char) * (size + 1));
	if (!substr)
		return (NULL);
	substr = ft_memcpy(substr, s + start, size);
	substr[size] = 0;
	return (substr);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*dst_tmp;
	unsigned char	*src_tmp;

	if (!dest)
		return (NULL);
	if (!src)
		return (dest);
	dst_tmp = (unsigned char *)dest;
	src_tmp = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		*(dst_tmp + i) = *(src_tmp + i);
		i++;
	}
	return (dst_tmp);
}

char	*ft_strdup(const char *src)
{
	char	*cpy;
	size_t	i;
	size_t	j;

	i = ft_strlen(src);
	cpy = malloc(sizeof(char) * (i + 1));
	if (!cpy)
		return (NULL);
	j = 0;
	while ((j < i) && src[j])
	{
		cpy[j] = src[j];
		j++;
	}
	cpy[j] = 0;
	return (cpy);
}
