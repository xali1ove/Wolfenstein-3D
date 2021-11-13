/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdaphine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 09:25:28 by gdaphine          #+#    #+#             */
/*   Updated: 2020/11/07 12:02:00 by gdaphine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_num(int nb)
{
	if (nb == 0)
		return (1);
	return (1 + ft_num(nb / 10));
}

static char	*ft_aff(char *s, int n, int i)
{
	unsigned int	l;

	l = 0;
	if (n == 0)
		*s = n + 48;
	else if (n < 0)
	{
		*s = '-';
		l = n * (-1);
	}
	else
		l = n;
	s[i + 1] = '\0';
	while (l != 0)
	{
		s[i] = l % 10 + 48;
		l = l / 10;
		i--;
	}
	return (s);
}

char	*ft_itoa(int n)
{
	int			l;
	char		*str;

	if (n > 0)
		l = ft_num(n) - 1;
	else
		l = ft_num(n);
	str = (char *)malloc(sizeof(char) * (l + 1));
	if (str == NULL)
		return (NULL);
	return (ft_aff(str, n, l - 1));
}
