/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdaphine <gdaphine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 20:01:45 by gdaphine          #+#    #+#             */
/*   Updated: 2020/11/07 12:11:28 by gdaphine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	ptr;
	size_t			i;

	ptr = (unsigned char)c;
	i = 0;
	while (i < n)
		((char *)s)[i++] = ptr;
	return (s);
}
