/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdaphine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 03:40:58 by gdaphine          #+#    #+#             */
/*   Updated: 2020/11/07 13:22:41 by gdaphine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	ft_char(char c, char const *set)
{
	size_t	l;

	l = 0;
	while (set[l])
	{
		if (set[l] == c)
			return (1);
		l++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ptr;
	size_t	i;
	size_t	s;
	size_t	end;

	s = 0;
	if (s1 == 0)
		return (0);
	while (s1[s] && ft_char(s1[s], set))
		s++;
	end = ft_strlen(s1);
	while (end > s && ft_char(s1[end - 1], set))
		end--;
	ptr = (char *)malloc(sizeof(*s1) * (end - s + 1));
	if (!ptr)
		return (0);
	i = 0;
	while (s < end)
		ptr[i++] = s1[s++];
	ptr[i] = 0;
	return (ptr);
}
