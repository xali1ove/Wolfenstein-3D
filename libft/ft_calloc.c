/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdaphine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 01:07:18 by gdaphine          #+#    #+#             */
/*   Updated: 2020/11/07 11:52:10 by gdaphine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t num, size_t size)
{
	char			*ptr;
	unsigned int	j;
	unsigned int	i;

	j = num * size;
	ptr = malloc(j);
	if (!ptr)
		return (NULL);
	i = 0;
	while (j--)
	{
		ptr[i] = 0;
		i++;
	}
	return ((void *)ptr);
}
