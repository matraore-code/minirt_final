/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matraore <matraore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 16:12:13 by matraore          #+#    #+#             */
/*   Updated: 2020/12/22 17:48:56 by matraore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlenl(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strdupl(const char *str)
{
	int		i;
	char	*dest;

	i = 0;
	dest = (char *)malloc(ft_strlenl(str) + 1);
	if (dest == NULL)
		return (0);
	while (str[i] != '\0')
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_substrl(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	i = 0;
	str = 0;
	if (s)
	{
		if (start > ft_strlenl(s))
			len = 0;
		str = malloc(sizeof(char) * (len + 1));
		if (str == NULL)
			return (0);
		while (i < len)
		{
			str[i] = s[start + i];
			i++;
		}
		str[i] = '\0';
	}
	return (str);
}

char	*ft_strchrl(const char *s, int c)
{
	while (*s)
	{
		if (*s == c)
			return ((char *)s);
		++s;
	}
	if (c == '\0')
		return ((char *)s);
	return (0);
}

char	*ft_strjoinl(char *s1, char const *s2)
{
	char	*str;
	int		i;
	int		j;
	int		len;

	i = -1;
	j = 0;
	if (s1 == 0 || s2 == 0)
		return (0);
	len = ft_strlenl(s1) + ft_strlenl((char *)s2);
	str = malloc(len * sizeof(char) + 1);
	if (str == NULL)
		return (0);
	while (s1[++i])
		str[i] = s1[i];
	while (s2[j])
	{
		str[i] = s2[j];
		j++;
		i++;
	}
	str[len] = '\0';
	return (str);
}
