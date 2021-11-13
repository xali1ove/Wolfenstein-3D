/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdaphine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 22:33:08 by gdaphine          #+#    #+#             */
/*   Updated: 2020/11/07 13:07:13 by gdaphine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	char	*p1;
	size_t	kek_len;
	size_t	j;
	size_t	i;

	p1 = (char *)s1;
	kek_len = ft_strlen(s2);
	if (!kek_len)
		return (p1);
	if (ft_strlen(s1) < kek_len || n < kek_len)
		return (NULL);
	i = 0;
	while (p1[i] && i <= n - kek_len)
	{
		j = 0;
		while (s2[j] && s2[j] == p1[i + j])
			j++;
		if (j == kek_len)
			return (&p1[i]);
		i++;
	}
	return (NULL);
}
