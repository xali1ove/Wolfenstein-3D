/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdaphine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 23:23:50 by gdaphine          #+#    #+#             */
/*   Updated: 2020/11/07 12:05:15 by gdaphine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *arr, int c, size_t n)
{
	unsigned char	*a;
	unsigned char	s;

	a = (unsigned char *)arr;
	s = (unsigned char)c;
	while (n--)
	{
		if (*a == s)
			return (a);
		a++;
	}
	return (NULL);
}
