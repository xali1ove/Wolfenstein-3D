/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdaphine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 01:59:08 by gdaphine          #+#    #+#             */
/*   Updated: 2020/11/07 13:27:16 by gdaphine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*unsub;
	unsigned int	i;

	i = 0;
	unsub = (char *)malloc(sizeof(char) * len + 1);
	if (!s || !unsub)
		return (NULL);
	if (start >= ft_strlen(s) - 1)
		return (unsub);
	while (i < len)
	{
		unsub[i] = s[i + start];
		i += 1;
	}
	unsub[i] = '\0';
	return (unsub);
}
