/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_screen_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdaphine <gdaphine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 01:58:56 by gdaphine          #+#    #+#             */
/*   Updated: 2021/04/15 01:58:59 by gdaphine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub.h"

int	ft_ch_color(t_window *w)
{
	t_data	*texture;

	texture = NULL;
	if (w->ray->side == 0 && w->ray->raydir[0] <= 0)
		texture = w->no;
	if (w->ray->side == 0 && w->ray->raydir[0] > 0)
		texture = w->so;
	if (w->ray->side == 1 && w->ray->raydir[1] <= 0)
		texture = w->we;
	if (w->ray->side == 1 && w->ray->raydir[1] > 0)
		texture = w->ea;
	w->tex[1] = (int)w->texpos & (texture->x - 1);
	w->texpos += w->step;
	return ((*(int *)(texture->addr + (w->tex[1] * texture->line_length
				+ w->tex[0] * (texture->bits_per_pixel / 8)))));
}

void	ft_ch_tex(t_window *w, int *i)
{
	t_data	*texture;

	texture = NULL;
	if (w->ray->side == 0 && w->ray->raydir[0] <= 0)
		texture = w->no;
	if (w->ray->side == 0 && w->ray->raydir[0] > 0)
		texture = w->so;
	if (w->ray->side == 1 && w->ray->raydir[1] <= 0)
		texture = w->we;
	if (w->ray->side == 1 && w->ray->raydir[1] > 0)
		texture = w->ea;
	w->tex[0] = (int)(w->wall[0] * (double)texture->y);
	if (w->ray->side == 0 && w->ray->raydir[0] > 0)
		w->tex[0] = texture->y - w->tex[0] - 1;
	if (w->ray->side == 1 && w->ray->raydir[1] < 0)
		w->tex[0] = texture->y - w->tex[0] - 1;
	w->step = 1.0 * texture->x / i[1];
	w->texpos = (i[2] - w->par->r[1] / 2 + i[1] / 2) * w->step;
}

void	ft_correct_dir(t_window *w)
{
	if (w->ray->raydir[0] < 0)
	{
		w->ray->step[0] = -1;
		w->ray->sidedist[0] = (w->ray->nul[0] - w->ray->map[0])
			* w->ray->deltadist[0];
	}
	else
	{
		w->ray->step[0] = 1;
		w->ray->sidedist[0] = (w->ray->map[0] + 1.0 - w->ray->nul[0])
			* w->ray->deltadist[0];
	}
	if (w->ray->raydir[1] < 0)
	{
		w->ray->step[1] = -1;
		w->ray->sidedist[1] = (w->ray->nul[1] - w->ray->map[1])
			* w->ray->deltadist[1];
	}
	else
	{
		w->ray->step[1] = 1;
		w->ray->sidedist[1] = (w->ray->map[1] + 1.0 - w->ray->nul[1])
			* w->ray->deltadist[1];
	}
}

t_sprt	*ft_creat_sprt(t_window *w)
{
	t_sprt	*new;

	new = NULL;
	new = malloc(sizeof(t_sprt));
	if (!new)
		return (NULL);
	new->y = w->ray->map[0] + 0.5;
	new->x = w->ray->map[1] + 0.5;
	new->number = w->map[(int)new->y][(int)new->x];
	new->distance = ((w->ray->nul[0] - new->y) * (w->ray->nul[0] - new->y)
			+ (w->ray->nul[1] - new->x) * (w->ray->nul[1] - new->x));
	new->next = NULL;
	return (new);
}

int	ft_write_sprite(t_window *w)
{
	t_sprt	*sprt;
	t_sprt	*new;

	sprt = NULL;
	new = NULL;
	if (!(w->sprt))
	{
		w->sprt = ft_creat_sprt(w);
		if (!w->sprt)
			return (ft_errors_memory(0));
	}
	return (ft_sprite_search(w));
}
