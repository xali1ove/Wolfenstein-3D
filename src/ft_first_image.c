/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_first_image.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdaphine <gdaphine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 01:58:09 by gdaphine          #+#    #+#             */
/*   Updated: 2021/04/15 01:58:12 by gdaphine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub.h"

static void	ft_we_start(t_window *w, int s)
{
	if (s == 0)
	{
		w->ray->dir[0] = 0;
		w->ray->dir[1] = -1;
		w->ray->plane[0] = -0.66;
		w->ray->plane[1] = 0;
	}
	if (s == 1)
	{
		w->ray->dir[0] = 0;
		w->ray->dir[1] = 1;
		w->ray->plane[0] = 0.66;
		w->ray->plane[1] = 0;
	}
}

static void	ft_ns_start(t_window *w, int s)
{
	if (s == 0)
	{
		w->ray->dir[0] = -1;
		w->ray->dir[1] = 0;
		w->ray->plane[0] = 0;
		w->ray->plane[1] = 0.66;
	}
	if (s == 1)
	{
		w->ray->dir[0] = 1;
		w->ray->dir[1] = 0;
		w->ray->plane[0] = 0;
		w->ray->plane[1] = -0.66;
	}
}

void	ft_first_image(t_window *w)
{
	w->par->pl[1] -= 1;
	w->par->pl[0] -= 1;
	if (w->map[w->par->pl[0]][w->par->pl[1]] == 'N')
		ft_ns_start(w, 0);
	else if (w->map[w->par->pl[0]][w->par->pl[1]] == 'W')
		ft_we_start(w, 0);
	else if (w->map[w->par->pl[0]][w->par->pl[1]] == 'S')
		ft_ns_start(w, 1);
	else
		ft_we_start(w, 1);
	w->ray->nul[0] = w->par->pl[0] + 0.5;
	w->ray->nul[1] = w->par->pl[1] + 0.5;
}
