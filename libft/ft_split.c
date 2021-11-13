/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdaphine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 09:54:19 by gdaphine          #+#    #+#             */
/*   Updated: 2020/11/07 12:39:13 by gdaphine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_numstr(char const *s1, char c)
{
	int		cmp;
	int		les;

	cmp = 0;
	les = 0;
	if (*s1 == '\0')
		return (0);
	while (*s1 != '\0')
	{
		if (*s1 == c)
			les = 0;
		else if (les == 0)
		{
			les = 1;
			cmp++;
		}
		s1++;
	}
	return (cmp);
}

static int	ft_numchar(char const *s2, char c, int i)
{
	int		ln;

	ln = 0;
	while (s2[i] != c && s2[i])
	{
		ln++;
		i++;
	}
	return (ln);
}

static char	**ft_freee(char const **dst, int j)
{
	while (j > 0)
	{
		j--;
		free((void *)dst[j]);
	}
	free(dst);
	return (NULL);
}

static char	**ft_aff(char const *s, char **dst, char c, int l)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	while (s[i] != '\0' && j < l)
	{
		k = 0;
		while (s[i] == c)
			i++;
		dst[j] = (char *)malloc(sizeof(char) * ft_numchar(s, c, i) + 1);
		if (dst[j] == NULL)
			return (ft_freee((char const **)dst, j));
		while (s[i] && s[i] != c)
			dst[j][k++] = s[i++];
		dst[j][k] = '\0';
		j++;
	}
	dst[j] = 0;
	return (dst);
}

char	**ft_split(char const *s, char c)
{
	char	**dst;
	int		l;

	if (s == NULL)
		return (NULL);
	l = ft_numstr(s, c);
	dst = (char **)malloc(sizeof(char *) * (l + 1));
	if (dst == NULL)
		return (NULL);
	return (ft_aff(s, dst, c, l));
}
