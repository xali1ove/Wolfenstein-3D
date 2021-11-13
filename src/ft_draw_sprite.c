/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_sprite.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdaphine <gdaphine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 01:58:31 by gdaphine          #+#    #+#             */
/*   Updated: 2021/04/15 01:58:34 by gdaphine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub.h"

static void	ft_wrt_sprite(t_window *w, int *h, int *we)
{
	char	*dst;

	dst = NULL;
	we[5] = h[3] * 256 - w->par->r[1] * 128 + h[0] * 128;
	w->tex[1] = ((we[5] * w->sp->x) / h[0]) / 256;
	dst = w->data->addr + (h[3] * w->data->line_length + we[1]
			* (w->data->bits_per_pixel / 8));
	if (((*(int *)(w->sp->addr + (w->tex[1] * w->sp->line_length
					+ w->tex[0] * (w->sp->bits_per_pixel / 8))))) > 0)
		*(unsigned int *)dst = (*(int *)(w->sp->addr
					+ (w->tex[1] * w->sp->line_length
						+ w->tex[0] * (w->sp->bits_per_pixel / 8))));
}

static void	ft_write_sprt(t_window *w, double *sprite, int *h, int *we)
{
	while (we[1] < we[2])
	{
		h[3] = h[1];
		w->tex[0] = (int)(256 * (we[1] - (-we[0] / 2 + we[4]))
				* w->sp->y / we[0]) / 256;
		if (sprite[4] > 0 && we[1] > 0 && we[1] < w->par->r[0]
			&& sprite[4] < w->zbuf[we[1]])
		{
			while (h[3] < h[2])
			{
				ft_wrt_sprite(w, h, we);
				h[3]++;
			}
		}
		we[1]++;
	}
}

static void	ft_sprite_create(t_window *w, t_sprt *sprt, double *sprite)
{
	sprite[0] = sprt->y - w->ray->nul[0];
	sprite[1] = sprt->x - w->ray->nul[1];
	sprite[2] = 1.0 / (w->ray->plane[0] * w->ray->dir[1]
			- w->ray->dir[0] * w->ray->plane[1]);
	sprite[3] = sprite[2] * (w->ray->dir[1] * sprite[0]
			- w->ray->dir[0] * sprite[1]);
	sprite[4] = sprite[2] * (-w->ray->plane[1] * sprite[0]
			+ w->ray->plane[0] * sprite[1]);
}

static void	ft_check_sprt(t_window *w, t_sprt *sprt)
{
	double	sprite[5];
	int		h[5];
	int		we[6];

	ft_sprite_create(w, sprt, sprite);
	we[4] = (int)((w->par->r[0] / 2) * (1 + sprite[3] / sprite[4]));
	h[3] = (int)(w->par->r[1] / (sprite[4]));
	h[0] = fabs((double)h[3]);
	h[1] = -h[0] / 2 + w->par->r[1] / 2;
	if (h[1] < 0)
		h[1] = 0;
	h[2] = h[0] / 2 + w->par->r[1] / 2;
	if (h[2] >= w->par->r[1])
		h[2] = w->par->r[1] - 1;
	we[3] = (int)(w->par->r[0] / (sprite[4]));
	we[0] = fabs((double)we[3]);
	we[1] = -we[0] / 2 + we[4];
	if (we[1] < 0)
		we[1] = 0;
	we[2] = we[0] / 2 + we[4];
	if (we[2] >= w->par->r[0])
		we[2] = w->par->r[0] - 1;
	ft_write_sprt(w, sprite, h, we);
}

int	ft_draw_sprite(t_window *w)
{
	t_sprt	*sprt;
	t_sprt	*next;

	if (!(w->sprt))
		return (1);
	ft_sort_sprites(w);
	sprt = w->sprt;
	while (sprt)
	{
		ft_check_sprt(w, sprt);
		sprt = sprt->next;
	}
	sprt = w->sprt;
	next = sprt->next;
	while (next)
	{
		free(sprt);
		sprt = next;
		next = next->next;
	}
	free(sprt);
	w->sprt = NULL;
	return (1);
}
