/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_other_functions_2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdaphine <gdaphine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 01:56:42 by gdaphine          #+#    #+#             */
/*   Updated: 2021/04/15 01:56:46 by gdaphine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub.h"

int	ft_sum_par_pars(t_window *w)
{
	if ((w->par_pars[0] + w->par_pars[1] + w->par_pars[2]
			+ w->par_pars[3] + w->par_pars[4] + w->par_pars[5]
			+ w->par_pars[6] + w->par_pars[7]) == 8)
		return (1);
	return (0);
}

int	ft_after_texture(t_window *w, char *flag)
{
	flag[w->a_num[1]] = ' ';
	while (flag[w->a_num[1]] != 0 && ft_isspace(flag[w->a_num[1]]) != 0)
		w->a_num[1]++;
	if (flag[w->a_num[1]] != 0)
		return (ft_errors_cub(2));
	return (1);
}

int	ft_res_file(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '.' && str[i])
		i++;
	if (ft_strlen(&str[i]) < 4)
		return (-1);
	if (str[i] == '.' && str[i + 1] == 'c'
		&& str[i + 2] == 'u' && str[i + 3] == 'b')
		return (1);
	return (-1);
}

int	ft_check_after_res(t_window *w, char *flag)
{
	while (flag[w->a_num[0]])
	{
		if (ft_isspace(flag[w->a_num[0]]) != 1)
			return (ft_errors_cub(5));
		w->a_num[0]++;
	}
	w->par_pars[0] = 1;
	return (1);
}

int	ft_check_digits_fc(t_window *w, char *flag, int i)
{
	while (flag[w->a_num[0]] != ',' && flag[w->a_num[0]])
	{
		if (ft_isdigit(flag[w->a_num[0]]) == 1)
			return (ft_errors_cub(i));
		w->a_num[0]++;
	}
	return (1);
}
