/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_post_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdaphine <gdaphine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 01:56:22 by gdaphine          #+#    #+#             */
/*   Updated: 2021/04/15 01:56:26 by gdaphine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub.h"

static int	ft_open_textures_2(t_window *w)
{
	w->we->img = mlx_xpm_file_to_image(w->mlx->mlx, w->par->we,
			&w->we->x, &w->we->y);
	if (!w->we->img)
		return (ft_errors_memory(1));
	w->we->addr = mlx_get_data_addr(w->we->img, &w->we->bits_per_pixel,
			&w->we->line_length, &w->we->endian);
	w->ea->img = mlx_xpm_file_to_image(w->mlx->mlx, w->par->ea,
			&w->ea->x, &w->ea->y);
	if (!w->ea->img)
		return (ft_errors_memory(1));
	w->ea->addr = mlx_get_data_addr(w->ea->img, &w->ea->bits_per_pixel,
			&w->ea->line_length, &w->ea->endian);
	w->sp->img = mlx_xpm_file_to_image(w->mlx->mlx, w->par->s,
			&w->sp->x, &w->sp->y);
	if (!w->sp->img)
		return (ft_errors_memory(1));
	w->sp->addr = mlx_get_data_addr(w->sp->img, &w->sp->bits_per_pixel,
			&w->sp->line_length, &w->sp->endian);
	return (1);
}

static int	ft_open_textures(t_window *w)
{
	w->no->img = mlx_xpm_file_to_image(w->mlx->mlx, w->par->no,
			&w->no->x, &w->no->y);
	if (!w->no->img)
		return (ft_errors_memory(1));
	w->no->addr = mlx_get_data_addr(w->no->img, &w->no->bits_per_pixel,
			&w->no->line_length, &w->no->endian);
	w->so->img = mlx_xpm_file_to_image(w->mlx->mlx, w->par->so,
			&w->so->x, &w->so->y);
	if (!w->so->img)
		return (ft_errors_memory(1));
	w->so->addr = mlx_get_data_addr(w->so->img, &w->so->bits_per_pixel,
			&w->so->line_length, &w->so->endian);
	if ((ft_open_textures_2(w)) < 0)
		return (-1);
	return (1);
}

static	void	ft_screen_check(t_window *w)
{
	mlx_get_screen_size(w->mlx->mlx, &w->sizex, &w->sizey);
	if (w->sizex < w->par->r[0])
		w->par->r[0] = w->sizex;
	if (w->sizey < w->par->r[1])
		w->par->r[1] = w->sizey;
	w->ms[0] = w->par->r[0] / 16000.0;
	w->ms[1] = w->ms[0] * 0.7;
	w->ms[2] = w->ms[0] / 2.0;
}

int	ft_without_screen(t_window *w)
{
	ft_screen_check(w);
	w->mlx->mlw = mlx_new_window(w->mlx->mlx, w->par->r[0],
			w->par->r[1], "cub3D");
	if ((ft_open_textures(w)) < 0)
		return (ft_close(w));
	mlx_hook(w->mlx->mlw, 2, 1L << 0, ft_key_press, w);
	mlx_hook(w->mlx->mlw, 17, 0L, ft_close, w);
	mlx_key_hook(w->mlx->mlw, ft_key_release, w);
	mlx_loop_hook(w->mlx->mlx, ft_draw_main_screen, w);
	mlx_loop(w->mlx->mlx);
	return (0);
}

int	ft_with_screen(t_window *w)
{
	ft_screen_check(w);
	if ((ft_open_textures(w)) < 0)
		return (ft_close(w));
	ft_draw_main_screen(w);
	return (0);
}
