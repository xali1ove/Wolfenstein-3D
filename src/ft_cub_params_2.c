/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub_params_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdaphine <gdaphine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 01:59:35 by gdaphine          #+#    #+#             */
/*   Updated: 2021/04/24 09:15:22 by gdaphine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub.h"

int	ft_true_end(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((ft_isspace(str[i])) == 0)
			return (-1);
		i++;
	}
	return (1);
}

static int	ft_texture_input2(t_window *w, char *flag, int i)
{
	if (i == 2)
	{
		w->par->we = ft_strdup(flag);
		if (!w->par->we)
			return (0);
	}
	if (i == 3)
	{
		w->par->ea = ft_strdup(flag);
		if (!w->par->ea)
			return (0);
	}
	return (1);
}

static int	ft_texture_input(t_window *w, char *flag, int i)
{
	w->par_pars[i + 1] = 1;
	if (i == 0)
	{
		w->par->no = ft_strdup(flag);
		if (!w->par->no)
			return (ft_errors_memory(0));
	}
	if (i == 1)
	{
		w->par->so = ft_strdup(flag);
		if (!w->par->so)
			return (ft_errors_memory(0));
	}
	if (!ft_texture_input2(w, flag, i))
		return (ft_errors_memory(0));
	return (1);
}

int	ft_resolution_writer(t_window *w, char *flag, int i)
{
	while (ft_isspace(flag[w->a_num[0]]) != 0)
		w->a_num[0]++;
	if (ft_isdigit(flag[w->a_num[0]]) == 1
		&& ft_isdigit(flag[w->a_num[0] + 1]) == 1
		&& ft_isdigit(flag[w->a_num[0] + 2]) == 1
		&& ft_isdigit(flag[w->a_num[0] + 3]) == 1
		&& ft_isdigit(flag[w->a_num[0] + 4]) == 1)
	{
		if (ft_isdigit(flag[w->a_num[0] + 5]) == 1)
		{
			flag[w->a_num[0] + 5] = 0;
			w->par->r[i] = ft_atoi(&flag[w->a_num[0]]);
			flag[w->a_num[0] + 5] = '1';
		}
		else
			w->par->r[i] = ft_atoi(&flag[w->a_num[0]]);
		w->a_num[0] += 5;
	}
	else
		w->par->r[i] = ft_atoi(&flag[w->a_num[0]]);
	if (w->par->r[i] == 0)
		return (ft_errors_cub(5));
	return (1);
}

int	ft_texture_writer(t_window *w, char *flag, char *start)
{
	if (start[0] == 'N' && start[1] == 'O' && w->par_pars[1] == 0)
		return (ft_texture_input(w, flag, 0));
	else if (start[0] == 'S' && start[1] == 'O' && w->par_pars[2] == 0)
		return (ft_texture_input(w, flag, 1));
	else if (start[0] == 'W' && start[1] == 'E' && w->par_pars[3] == 0)
		return (ft_texture_input(w, flag, 2));
	else if (start[0] == 'E' && start[1] == 'A' && w->par_pars[4] == 0)
		return (ft_texture_input(w, flag, 3));
	else
		return (ft_errors_cub(4));
	return (1);
}
