/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flood_fill_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdaphine <gdaphine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 01:58:01 by gdaphine          #+#    #+#             */
/*   Updated: 2021/04/15 01:58:04 by gdaphine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub.h"

int	ft_check_udlr(t_window *w, int y, int x)
{
	if (x > (int)ft_strlen(w->copy_map[y - 1]) - 1)
		return (-1);
	if (x > (int)ft_strlen(w->copy_map[y + 1]) - 1)
		return (-1);
	if (w->copy_map[y - 1][x] == '\0' || w->copy_map[y - 1][x] == ' ')
		return (-1);
	if (w->copy_map[y + 1][x] == '\0' || w->copy_map[y + 1][x] == ' ')
		return (-1);
	if (w->copy_map[y][x - 1] == '\0' || w->copy_map[y][x - 1] == ' ')
		return (-1);
	if (w->copy_map[y][x + 1] == '\0' || w->copy_map[y][x + 1] == ' ')
		return (-1);
	return (1);
}

int	ft_check_corner(t_window *w, int y, int x)
{
	if (w->copy_map[y + 1][x + 1] == '\0' || w->copy_map[y + 1][x + 1] == ' ')
		return (-1);
	if (w->copy_map[y + 1][x - 1] == '\0' || w->copy_map[y + 1][x - 1] == ' ')
		return (-1);
	if (w->copy_map[y - 1][x - 1] == '\0' || w->copy_map[y - 1][x - 1] == ' ')
		return (-1);
	if (w->copy_map[y - 1][x + 1] == '\0' || w->copy_map[y - 1][x + 1] == ' ')
		return (-1);
	return (1);
}

int	ft_check_fild_map(t_window *w, int y, int x)
{
	if (y < w->par->m[0] - 1 && y > 0)
	{
		if (x < (int)ft_strlen(w->copy_map[y]) && x > 0)
		{
			if (ft_check_corner(w, y, x) > 0)
			{
				if (ft_check_udlr(w, y, x) > 0)
					return (1);
			}
		}
	}
	return (ft_errors_cub(8));
}

int	ft_check_copy_map(t_window *w)
{
	w->a_num[0] = 0;
	w->a_num[1] = 0;
	while (w->a_num[0] < w->par->m[0])
	{
		while (w->copy_map[w->a_num[0]][w->a_num[1]])
		{
			if (w->copy_map[w->a_num[0]][w->a_num[1]] == 'x'
				|| w->copy_map[w->a_num[0]][w->a_num[1]] == '2'
				|| w->copy_map[w->a_num[0]][w->a_num[1]] == '0')
			{
				if (ft_check_fild_map(w, w->a_num[0], w->a_num[1]) < 0)
					return (-1);
			}
			w->a_num[1]++;
		}
		w->a_num[1] = 0;
		w->a_num[0]++;
	}
	return (1);
}
