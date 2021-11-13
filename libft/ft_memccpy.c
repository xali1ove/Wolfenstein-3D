/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdaphine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 21:59:39 by gdaphine          #+#    #+#             */
/*   Updated: 2020/11/07 12:04:10 by gdaphine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *source, int c, size_t n)
{
	unsigned char	set;
	unsigned char	*d;
	unsigned char	*v;

	set = (unsigned char)c;
	d = (unsigned char *)dest;
	v = (unsigned char *)source;
	while (n--)
	{
		*d++ = *v++;
		if (*(d - 1) == set)
			return (d);
	}
	return (NULL);
}
