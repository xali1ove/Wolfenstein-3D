/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdaphine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 23:57:34 by gdaphine          #+#    #+#             */
/*   Updated: 2021/04/24 02:34:08 by gdaphine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_issp(char p)
{
	if (p == ' ' || p == '\n' || p == '\v'
		|| p == '\t' || p == '\f' || p == '\r')
		return (1);
	else
		return (0);
}

int	ft_atoi(const char *str)
{
	long	nbr;
	long	ptr;
	size_t	i;

	nbr = 0;
	ptr = 1;
	i = 0;
	while (str[i] && ft_issp(str[i]) == 1)
		i++;
	if (str[i] == '-')
		ptr = -1;
	if ((str[i] == '-') || (str[i] == '+'))
		i++;
	while (str[i] && ('0' <= str[i]) && (str[i] <= '9'))
	{
		nbr = (nbr * 10) + (str[i] - '0');
		if (nbr > 2147483648 && ptr == 1)
			return (-1);
		if (nbr > 2147483648 && ptr == -1)
			return (0);
		i++;
	}
	return (nbr * ptr);
}
