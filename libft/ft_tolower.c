/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdaphine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 02:20:02 by gdaphine          #+#    #+#             */
/*   Updated: 2020/11/05 02:23:42 by gdaphine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_issup(int c)
{
	return ((c >= 65) && (c <= 90));
}

int	ft_tolower(int c)
{
	if (ft_issup(c))
		return (c + 32);
	return (c);
}