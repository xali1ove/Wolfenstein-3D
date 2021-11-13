/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdaphine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 23:42:54 by gdaphine          #+#    #+#             */
/*   Updated: 2020/11/07 12:06:07 by gdaphine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *arr1, const void *arr2, size_t n)
{
	unsigned char	*fd;
	unsigned char	*rm;

	fd = (unsigned char *)arr1;
	rm = (unsigned char *)arr2;
	while (n--)
	{
		if (*fd != *rm)
			return (*fd - *rm);
		fd++;
		rm++;
	}
	return (0);
}
