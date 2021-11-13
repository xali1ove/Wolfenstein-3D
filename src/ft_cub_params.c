/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdaphine <gdaphine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 01:59:22 by gdaphine          #+#    #+#             */
/*   Updated: 2021/04/15 01:59:26 by gdaphine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub.h"

int	ft_texture_parser(t_window *w, char *flag)
{
	int	fd;

	w->a_num[0] = 2;
	fd = 0;
	while ((ft_isspace(flag[w->a_num[0]])) != 0)
		w->a_num[0]++;
	w->a_num[1] = w->a_num[0];
	while ((ft_isspace(flag[w->a_num[1]])) != 1 && flag[w->a_num[1]] != 0)
		w->a_num[1]++;
	if (flag[w->a_num[1]] != 0)
		flag[w->a_num[1]] = 0;
	else
		w->a_num[1] = 0;
	fd = open(&flag[w->a_num[0]], O_RDONLY);
	if (fd < 0)
		return (ft_errors_cub(2));
	close(fd);
	fd = ft_texture_writer(w, &flag[w->a_num[0]], flag);
	if (fd < 0)
		return (-1);
	if (w->a_num[1] != 0)
		if ((ft_after_texture(w, flag)) < 0)
			return (-1);
	return (1);
}

int	ft_resolution_parser(t_window *w, char *flag)
{
	w->a_num[0] = 1;
	w->a_num[1] = 0;
	while (flag[w->a_num[0]])
	{
		if (ft_isspace(flag[w->a_num[0]]) == 0
			&& ft_isdigit(flag[w->a_num[0]]) == 0)
			w->a_num[1] = 1;
		w->a_num[0]++;
	}
	if (w->a_num[1] == 1)
		return (ft_errors_cub(5));
	w->a_num[0] = 1;
	if (ft_resolution_writer(w, flag, 0) < 0)
		return (-1);
	while (ft_isspace(flag[w->a_num[0]]) != 1 && flag[w->a_num[0]])
		w->a_num[0]++;
	if (flag[w->a_num[0]] == 0)
		return (ft_errors_cub(5));
	if (ft_resolution_writer(w, flag, 1) < 0)
		return (-1);
	while (ft_isspace(flag[w->a_num[0]]) != 1 && flag[w->a_num[0]])
		w->a_num[0]++;
	return (ft_check_after_res(w, flag));
}

int	ft_sprite_parser(t_window *w, char *flag)
{
	int	fd;

	w->a_num[0] = 1;
	fd = 0;
	while ((ft_isspace(flag[w->a_num[0]])) != 0)
		w->a_num[0]++;
	w->a_num[1] = w->a_num[0];
	while (flag[w->a_num[1]] != 0 && ft_isspace(flag[w->a_num[1]]) != 1)
		w->a_num[1]++;
	if (flag[w->a_num[1]] != 0)
		flag[w->a_num[1]] = 0;
	else
		w->a_num[1] = 0;
	fd = open(&flag[w->a_num[0]], O_RDONLY);
	if (fd < 0)
		return (ft_errors_cub(2));
	close(fd);
	w->par->s = ft_strdup(&flag[w->a_num[0]]);
	if (!w->par->s)
		return (ft_errors_memory(0));
	if (w->a_num[1] != 0)
		if ((ft_after_texture(w, flag)) < 0)
			return (-1);
	w->par_pars[5] = 1;
	return (1);
}

int	ft_floor_parser(t_window *w, char *flag)
{
	w->a_num[0] = 1;
	w->a_num[1] = 0;
	w->a_num[2] = 0;
	while (flag[w->a_num[0]])
	{
		if (flag[w->a_num[0]] == ',')
			w->a_num[1]++;
		if (ft_isspace(flag[w->a_num[0]]) != 1 && flag[w->a_num[0]] != ','
			&& ft_isdigit(flag[w->a_num[0]]) != 1)
			return (ft_errors_cub(6));
		w->a_num[0]++;
	}
	if (w->a_num[1] != 2)
		return (ft_errors_cub(6));
	w->a_num[0] = 1;
	w->a_num[2] = 0;
	if (ft_f_c_write(w, flag, w->par->f, 6) < 0)
		return (ft_errors_cub(6));
	if (w->a_num[2] != 3)
		return (ft_errors_cub(6));
	w->par_pars[6] = 1;
	return (1);
}

int	ft_cell_parser(t_window *w, char *flag)
{
	w->a_num[0] = 1;
	w->a_num[1] = 0;
	w->a_num[2] = 0;
	while (flag[w->a_num[0]])
	{
		if (flag[w->a_num[0]] == ',')
			w->a_num[1]++;
		if (ft_isspace(flag[w->a_num[0]]) != 1 && flag[w->a_num[0]] != ','
			&& ft_isdigit(flag[w->a_num[0]]) != 1)
			return (ft_errors_cub(7));
		w->a_num[0]++;
	}
	if (w->a_num[1] != 2)
		return (ft_errors_cub(7));
	w->a_num[0] = 1;
	w->a_num[2] = 0;
	if (ft_f_c_write(w, flag, w->par->c, 7) < 0)
		return (ft_errors_cub(7));
	if (w->a_num[2] != 3)
		return (ft_errors_cub(7));
	w->par_pars[7] = 1;
	return (1);
}
