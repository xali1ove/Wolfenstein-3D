/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdaphine <gdaphine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 21:00:32 by gdaphine          #+#    #+#             */
/*   Updated: 2020/11/07 12:08:43 by gdaphine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *source, size_t n)
{
	unsigned int	i;

	i = 0;
	if (dest == 0 && source == 0)
		return (0);
	while (i < n)
	{
		((char *)dest)[i] = ((const char *)source)[i];
		i++;
	}
	return (dest);
}
