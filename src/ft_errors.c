/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdaphine <gdaphine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 01:58:18 by gdaphine          #+#    #+#             */
/*   Updated: 2021/04/15 01:58:22 by gdaphine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub.h"

int	ft_errors_cub(int sig)
{
	if (sig == 0)
		write(1, "Error\nno valid configuration file\n", 34);
	if (sig == 1)
		write(1, "Error\nno valid configuration file\n", 34);
	if (sig == 2)
		write(1, "Error\nno valid texture\n", 23);
	if (sig == 4)
		write(1, "Error\nno valid texture\n", 23);
	if (sig == 5)
		write(1, "Error\nno valid resolution\n", 26);
	if (sig == 6)
		write(1, "Error\nno valid floor\n", 21);
	if (sig == 7)
		write(1, "Error\nno valid cell\n", 20);
	if (sig == 8)
		write(1, "Error\nmap not valid\n", 20);
	if (sig == 9)
		write(1, "Error\nno correct line\n", 22);
	return (-1);
}

int	ft_errors_memory(int sig)
{
	if (sig == 0)
		write(1, "Error\nno memory\n", 16);
	if (sig == 1)
		write(1, "Error\ntexture file not valid\n", 29);
	return (-1);
}

int	ft_error_w_free(int sig, char **f)
{
	int	i;

	i = 0;
	if (sig == 0)
		write(1, "Error\nmap not valid\n", 20);
	if (sig == 1)
		write(1, "Error\nno valid cell\n", 20);
	if (sig == 2)
		write(1, "Error\nno valid floor\n", 21);
	if (sig != 0)
	{
		while (f[i])
		{
			free(f[i]);
			i++;
		}
		free(f);
		return (-1);
	}
	free(*f);
	return (-1);
}

int	ft_error_w_close(int *f)
{
	close(*f);
	return (-1);
}
