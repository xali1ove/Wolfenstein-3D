/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdaphine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 03:39:32 by gdaphine          #+#    #+#             */
/*   Updated: 2020/11/07 13:23:29 by gdaphine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int ch)
{
	char	*p;
	char	s;

	p = (char *)str + ft_strlen(str);
	s = (char)ch;
	while (p >= str)
	{
		if (*p == s)
			return (p);
		p--;
	}
	return (NULL);
}
