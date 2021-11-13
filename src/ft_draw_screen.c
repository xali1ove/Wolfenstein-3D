/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_screen.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdaphine <gdaphine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 01:58:40 by gdaphine          #+#    #+#             */
/*   Updated: 2021/04/15 01:58:43 by gdaphine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub.h"

int	ft_draw_rays(t_window *w)
{
	w->ray->map[0] = (int)w->ray->nul[0];
	w->ray->map[1] = (int)w->ray->nul[1];
	w->ray->deltadist[0] = fabs(1 / w->ray->raydir[0]);
	w->ray->deltadist[1] = fabs(1 / w->ray->raydir[1]);
	ft_correct_dir(w);
	if ((ft_start_ray(w)) < 0)
		return (-1);
	return (1);
}

static void	ft_image_creater(t_window *w, int *i)
{
	char	*dst;

	dst = NULL;
	while (i[4] < w->par->r[1])
	{
		if (i[4] >= i[2] && i[4] <= i[3])
		{
			dst = w->data->addr + (i[4] * w->data->line_length
					+ i[0] * (w->data->bits_per_pixel / 8));
			*(unsigned int *)dst = ft_ch_color(w);
		}
		else if (i[4] > i[3])
		{
			dst = w->data->addr + (i[4] * w->data->line_length
					+ i[0] * (w->data->bits_per_pixel / 8));
			*(unsigned int *)dst = ft_color_creater(w->par->f);
		}
		else if (i[4] < i[2])
		{
			dst = w->data->addr + (i[4] * w->data->line_length
					+ i[0] * (w->data->bits_per_pixel / 8));
			*(unsigned int *)dst = ft_color_creater(w->par->c);
		}
		i[4]++;
	}
}

static int	ft_prerelease(t_window *w, int *i)
{
	w->ray->camera[0] = 2 * i[0] / (double)w->par->r[0] - 1;
	w->ray->raydir[0] = w->ray->dir[0] + w->ray->plane[0] * w->ray->camera[0];
	w->ray->raydir[1] = w->ray->dir[1] + w->ray->plane[1] * w->ray->camera[0];
	if ((ft_draw_rays(w)) < 0)
		return (-1);
	i[1] = (int)(w->par->r[1] / w->ray->wall);
	i[2] = -i[1] / 2 + w->par->r[1] / 2;
	if (i[2] < 0)
		i[2] = 0;
	i[3] = i[1] / 2 + w->par->r[1] / 2;
	if (i[3] >= w->par->r[1])
		i[3] = w->par->r[1] - 1;
	w->zbuf[i[0]] = w->ray->wall;
	if (w->ray->side == 0)
		w->wall[0] = w->ray->nul[1] + w->ray->wall * w->ray->raydir[1];
	else
		w->wall[0] = w->ray->nul[0] + w->ray->wall * w->ray->raydir[0];
	w->wall[0] -= floor(w->wall[0]);
	ft_ch_tex(w, i);
	return (1);
}

static int	ft_cyc_draw_screen(t_window *w, int *i)
{
	while (i[0] < w->par->r[0])
	{
		if ((ft_prerelease(w, i)) < 0)
			return (-1);
		i[4] = 0;
		ft_image_creater(w, i);
		i[0]++;
	}
	return (1);
}

int	ft_draw_main_screen(t_window *w)
{
	int		i[5];

	i[0] = 0;
	if (w->sshot == 0)
	{
		if (w->data->img)
			mlx_destroy_image(w->mlx->mlx, w->data->img);
	}
	w->data->img = mlx_new_image(w->mlx->mlx, w->par->r[0] + 1,
			w->par->r[1] + 1);
	w->data->addr = mlx_get_data_addr(w->data->img, &w->data->bits_per_pixel,
			&w->data->line_length, &w->data->endian);
	w->zbuf = malloc(sizeof(double) * w->par->r[0]);
	if (!w->zbuf)
		return (ft_errors_memory(0));
	if ((ft_cyc_draw_screen(w, i)) < 0)
		return (ft_close(w));
	if ((ft_draw_sprite(w)) < 0)
		return (ft_close(w));
	if (w->sshot == 1)
		return (ft_screenshot_write(w));
	free(w->zbuf);
	ft_new_position(w);
	mlx_put_image_to_window(w->mlx->mlx, w->mlx->mlw, w->data->img, 0, 0);
	return (1);
}
