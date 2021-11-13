/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_position.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdaphine <gdaphine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 01:56:52 by gdaphine          #+#    #+#             */
/*   Updated: 2021/04/15 01:56:57 by gdaphine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub.h"

static void	ft_rot_left(t_window *w)
{
	w->ray->old[0] = w->ray->dir[0];
	w->ray->dir[0] = w->ray->dir[0] * cos(w->ms[1])
		- w->ray->dir[1] * sin(w->ms[1]);
	w->ray->dir[1] = w->ray->old[0] * sin(w->ms[1])
		+ w->ray->dir[1] * cos(w->ms[1]);
	w->ray->old[1] = w->ray->plane[0];
	w->ray->plane[0] = w->ray->plane[0] * cos(w->ms[1])
		- w->ray->plane[1] * sin(w->ms[1]);
	w->ray->plane[1] = w->ray->old[1] * sin(w->ms[1])
		+ w->ray->plane[1] * cos(w->ms[1]);
}

static void	ft_rot_right(t_window *w)
{
	w->ray->old[0] = w->ray->dir[0];
	w->ray->dir[0] = w->ray->dir[0] * cos(-w->ms[1])
		- w->ray->dir[1] * sin(-w->ms[1]);
	w->ray->dir[1] = w->ray->old[0] * sin(-w->ms[1])
		+ w->ray->dir[1] * cos(-w->ms[1]);
	w->ray->old[1] = w->ray->plane[0];
	w->ray->plane[0] = w->ray->plane[0] * cos(-w->ms[1])
		- w->ray->plane[1] * sin(-w->ms[1]);
	w->ray->plane[1] = w->ray->old[1] * sin(-w->ms[1])
		+ w->ray->plane[1] * cos(-w->ms[1]);
}

static void	ft_move_up(t_window *w)
{
	int	y;
	int	x;

	y = (int)(w->ray->nul[0] + w->ray->dir[0] * w->ms[0]);
	x = (int)(w->ray->nul[1] + w->ray->dir[1] * w->ms[0]);
	if ((y >= 0 && y < w->par->m[0]) && (int)(w->ray->nul[1])
			< (int)ft_strlen(w->map[y]) && (int)(w->ray->nul[1]) >= 0
			&& w->map[y][(int)(w->ray->nul[1])] != '1')
		w->ray->nul[0] += w->ray->dir[0] * w->ms[0];
	if (x < (int)ft_strlen(w->map[(int)w->ray->nul[0]])
		&& x >= 0 && w->map[(int)(w->ray->nul[0])][x] != '1')
		w->ray->nul[1] += w->ray->dir[1] * w->ms[0];
}

static void	ft_move_down(t_window *w)
{
	int	y;
	int	x;

	y = (int)(w->ray->nul[0] - w->ray->dir[0] * w->ms[0]);
	x = (int)(w->ray->nul[1] - w->ray->dir[1] * w->ms[0]);
	if ((y >= 0 && y < w->par->m[0]) && (int)(w->ray->nul[1])
			< (int)ft_strlen(w->map[y]) && (int)(w->ray->nul[1]) >= 0
			&& w->map[y][(int)(w->ray->nul[1])] != '1')
		w->ray->nul[0] -= w->ray->dir[0] * w->ms[0];
	if (x < (int)ft_strlen(w->map[(int)(w->ray->nul[0])]) && x >= 0
		&& w->map[(int)(w->ray->nul[0])][x] != '1')
		w->ray->nul[1] -= w->ray->dir[1] * w->ms[0];
}

int	ft_new_position(t_window *w)
{
	if (w->key_press[0] == 1)
		ft_move_up(w);
	if (w->key_press[1] == 1)
		ft_move_down(w);
	if (w->key_press[2] == 1)
		ft_move_left(w);
	if (w->key_press[3] == 1)
		ft_move_right(w);
	if (w->key_press[4] == 1)
		ft_rot_left(w);
	if (w->key_press[5] == 1)
		ft_rot_right(w);
	return (0);
}
