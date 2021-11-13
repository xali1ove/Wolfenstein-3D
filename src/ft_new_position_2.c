/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_position_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdaphine <gdaphine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 01:57:04 by gdaphine          #+#    #+#             */
/*   Updated: 2021/04/15 01:57:07 by gdaphine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub.h"

int	ft_close(t_window *w)
{
	mlx_destroy_window(w->mlx->mlx, w->mlx->mlw);
	ft_free_map(w);
	free(w->par->no);
	free(w->par->so);
	free(w->par->we);
	free(w->par->ea);
	free(w->par->s);
	free(w->map);
	free(w->mlx);
	free(w->data);
	free(w->no);
	free(w->so);
	free(w->we);
	free(w->ea);
	free(w->sp);
	free(w->ray);
	free(w->par);
	free(w);
	exit(0);
}

void	ft_move_left(t_window *w)
{
	int	y;
	int	x;

	y = (int)(w->ray->nul[0] - w->ray->dir[1] * w->ms[1]);
	x = (int)(w->ray->nul[1] + w->ray->dir[0] * w->ms[1]);
	if ((y >= 0 && y < w->par->m[0]) && (int)(w->ray->nul[1])
			< (int)ft_strlen(w->map[y]) && (int)(w->ray->nul[1]) >= 0
			&& w->map[y][(int)(w->ray->nul[1])] != '1')
		w->ray->nul[0] -= w->ray->dir[1] * w->ms[1];
	if (x < (int)ft_strlen(w->map[(int)w->ray->nul[0]])
		&& x >= 0 && w->map[(int)(w->ray->nul[0])][x] != '1')
		w->ray->nul[1] += w->ray->dir[0] * w->ms[1];
}

void	ft_move_right(t_window *w)
{
	int	y;
	int	x;

	y = (int)(w->ray->nul[0] + w->ray->dir[1] * w->ms[1]);
	x = (int)(w->ray->nul[1] - w->ray->dir[0] * w->ms[1]);
	if ((y >= 0 && y < w->par->m[0]) && (int)(w->ray->nul[1])
			< (int)ft_strlen(w->map[y]) && (int)(w->ray->nul[1]) >= 0
			&& w->map[y][(int)(w->ray->nul[1])] != '1')
		w->ray->nul[0] += w->ray->dir[1] * w->ms[1];
	if (x < (int)ft_strlen(w->map[(int)w->ray->nul[0]])
		&& x >= 0 && w->map[(int)(w->ray->nul[0])][x] != '1')
		w->ray->nul[1] -= w->ray->dir[0] * w->ms[1];
}
