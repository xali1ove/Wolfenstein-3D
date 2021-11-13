/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flood_fill.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdaphine <gdaphine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 01:57:52 by gdaphine          #+#    #+#             */
/*   Updated: 2021/04/15 01:57:55 by gdaphine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub.h"

static int	ft_req_copy_map(t_window *w, int y, int x)
{
	if (w->copy_map[y][x] != '0')
		return (0);
	if (w->copy_map[y][x] == '0' ||
		w->copy_map[y][x] == '2')
		w->copy_map[y][x] = 'x';
	if (x > 0)
		ft_req_copy_map(w, y, x - 1);
	if (x < (int)ft_strlen(w->copy_map[y]))
		ft_req_copy_map(w, y, x + 1);
	if (y > 0)
		ft_req_copy_map(w, y - 1, x);
	if (y < w->par->m[0] - 1)
		ft_req_copy_map(w, y + 1, x);
	if (y < w->par->m[0] - 1 && x < (int)ft_strlen(w->copy_map[y]))
		ft_req_copy_map(w, y + 1, x + 1);
	if (x > 0 && y > 0)
		ft_req_copy_map(w, y - 1, x - 1);
	if (y > 0 && x < (int)ft_strlen(w->copy_map[y]))
		ft_req_copy_map(w, y - 1, x + 1);
	if (x > 0 && y < w->par->m[0] - 1)
		ft_req_copy_map(w, y + 1, x - 1);
	return (1);
}

static int	ft_check_valid(t_window *w)
{
	w->copy_map[w->par->pl[0] - 1][w->par->pl[1] - 1] = '0';
	ft_req_copy_map(w, w->par->pl[0] - 1, w->par->pl[1] - 1);
	if ((ft_check_copy_map(w)) < 0)
		return (-1);
	return (1);
}

static int	ft_free_copy_map(t_window *w, int err)
{
	int	i;

	i = 0;
	while (w->copy_map[i])
	{
		free(w->copy_map[i]);
		i++;
	}
	free(w->copy_map);
	if (err == 1)
		return (-1);
	return (1);
}

static int	ft_valid_map_next(t_window *w)
{
	int	i;

	i = 0;
	w->copy_map = malloc(sizeof(char *) * w->par->m[0] + sizeof(char *));
	if (!w->copy_map)
		return (ft_errors_memory(0));
	while (i < w->par->m[0])
	{
		w->copy_map[i] = ft_strdup(w->map[i]);
		if (!w->copy_map[i])
			return (ft_free_copy_map(w, 1));
		i++;
	}
	w->copy_map[i] = NULL;
	if ((ft_check_valid(w)) < 0)
		return (ft_free_copy_map(w, 1));
	return (ft_free_copy_map(w, 0));
}

int	ft_map_valid(t_window *w)
{
	int	i;
	int	y;

	i = 0;
	y = 0;
	while (i < w->par->m[0])
	{
		while (w->map[i][y])
		{
			if (w->map[i][y] != '0' && w->map[i][y] != '1' &&
			w->map[i][y] != '2'
				&& ft_isspace(w->map[i][y]) == 0 && w->map[i][y])
			{
				w->par->pl[0] = i + 1;
				w->par->pl[1] = y + 1;
				w->par->pl[2] += 1;
			}
			y++;
		}
		y = 0;
		i++;
	}
	if (w->par->pl[2] != 1)
		return (ft_errors_cub(8));
	return (ft_valid_map_next(w));
}
