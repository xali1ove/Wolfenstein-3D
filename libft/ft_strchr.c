/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdaphine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 02:43:40 by gdaphine          #+#    #+#             */
/*   Updated: 2020/11/07 12:41:26 by gdaphine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int ch)
{
	char	*p;
	char	s;

	p = (char *)str;
	s = (char)ch;
	while (*p && !(*p == s))
		p++;
	if (*p == s)
		return (p);
	else
		return (NULL);
}
