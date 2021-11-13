/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_screen_3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdaphine <gdaphine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 01:58:48 by gdaphine          #+#    #+#             */
/*   Updated: 2021/04/15 01:58:51 by gdaphine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub.h"

int	ft_sprite_search(t_window *w)
{
	t_sprt	*sprt;
	t_sprt	*new;

	sprt = w->sprt;
	new = NULL;
	while (sprt)
	{
		if ((int)sprt->y != w->ray->map[0] || (int)sprt->x != w->ray->map[1])
		{
			if (sprt->next != NULL)
				sprt = sprt->next;
			else
				break ;
		}
		else
			return (1);
	}
	sprt = w->sprt;
	while (sprt->next)
		sprt = sprt->next;
	new = ft_creat_sprt(w);
	if (!new)
		return (ft_errors_memory(0));
	sprt->next = new;
	return (1);
}

void	ft_wall_steper(t_window *w)
{
	if (w->ray->sidedist[0] < w->ray->sidedist[1])
	{
		w->ray->sidedist[0] += w->ray->deltadist[0];
		w->ray->map[0] += w->ray->step[0];
		w->ray->side = 0;
	}
	else
	{
		w->ray->sidedist[1] += w->ray->deltadist[1];
		w->ray->map[1] += w->ray->step[1];
		w->ray->side = 1;
	}
}

unsigned int	ft_color_creater(int *c)
{
	return ((c[0] * 65536) + (c[1] * 256) + c[2]);
}

int	ft_start_ray(t_window *w)
{
	while (w->map[w->ray->map[0]][w->ray->map[1]] != '1' && w->ray->map[0] >= 0
			&& w->ray->map[0] < w->par->m[0] - 1 && w->ray->map[1] >= 0
			&& (int)ft_strlen(w->map[w->ray->map[0]]))
	{
		if (w->map[w->ray->map[0]][w->ray->map[1]] == '2')
		{
			if ((ft_write_sprite(w)) < 0)
				return (-1);
		}
		ft_wall_steper(w);
	}
	if (w->ray->side == 0)
		w->ray->wall = (w->ray->map[0] - w->ray->nul[0]
				+ (1 - w->ray->step[0]) / 2) / w->ray->raydir[0];
	else
		w->ray->wall = (w->ray->map[1] - w->ray->nul[1]
				+ (1 - w->ray->step[1]) / 2) / w->ray->raydir[1];
	return (1);
}
