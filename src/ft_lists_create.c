/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lists_create.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdaphine <gdaphine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 01:57:12 by gdaphine          #+#    #+#             */
/*   Updated: 2021/04/15 01:57:15 by gdaphine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub.h"

static t_params	*ft_lstnew_par(void)
{
	t_params	*begin;
	int			i;

	i = 0;
	begin = malloc(sizeof(t_params));
	if (!begin)
		return (NULL);
	begin->no = NULL;
	begin->so = NULL;
	begin->we = NULL;
	begin->ea = NULL;
	begin->s = NULL;
	while (i < 3)
	{
		if (i < 2)
		{
			begin->m[i] = 0;
			begin->r[i] = 0;
		}
		begin->f[i] = 0;
		begin->c[i] = 0;
		begin->pl[i] = 0;
		i++;
	}
	return (begin);
}

static t_window	*ft_free_structs(t_window *w)
{
	if (w->ea)
		free(w->ea);
	if (w->we)
		free(w->we);
	if (w->no)
		free(w->no);
	if (w->so)
		free(w->so);
	if (w->par)
		free(w->par);
	if (w->ray)
		free(w->ray);
	if (w->data)
		free(w->data);
	if (w->mlx)
		free(w->mlx);
	if (w->sp)
		free(w->sp);
	free(w);
	write(1, "error memomry", 14);
	return (NULL);
}

static int	ft_check_wlists2(t_window *w)
{
	w->mlx = malloc(sizeof(t_screen));
	if (!w->mlx)
		return (0);
	w->data = malloc(sizeof(t_data));
	if (!w->data)
		return (0);
	w->no = malloc(sizeof(t_data));
	if (!w->no)
		return (0);
	w->so = malloc(sizeof(t_data));
	if (!w->so)
		return (0);
	w->we = malloc(sizeof(t_data));
	if (!w->we)
		return (0);
	return (1);
}

static t_window	*ft_check_wlists(t_window *w)
{
	w->par = ft_lstnew_par();
	if (!w->par)
		return (ft_free_structs(w));
	w->ray = malloc(sizeof(t_ray));
	if (!w->ray)
		return (ft_free_structs(w));
	w->ea = malloc(sizeof(t_data));
	if (!w->ea)
		return (ft_free_structs(w));
	w->sp = malloc(sizeof(t_data));
	if (!w->sp)
		return (ft_free_structs(w));
	if (!ft_check_wlists2(w))
		return (ft_free_structs(w));
	null_creater(w);
	return (w);
}

t_window	*new_lstwindow(int argc)
{
	t_window	*w;

	w = malloc(sizeof(t_window));
	if (!w)
		return (NULL);
	ft_bzero(w, sizeof(t_window));
	if (argc == 3)
		w->sshot = 1;
	if (argc == 2)
		w->sshot = 0;
	w->sprt = NULL;
	w->map = NULL;
	ft_check_wlists(w);
	return (w);
}
