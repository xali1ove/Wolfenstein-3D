/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helper.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdaphine <gdaphine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 07:23:34 by gdaphine          #+#    #+#             */
/*   Updated: 2021/04/24 09:26:55 by gdaphine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub.h"

void	null_creater(t_window *w)
{
	int	i;

	i = 0;
	w->data->img = NULL;
	w->copy_map = NULL;
	while (i++ < 9)
		w->par_pars[i] = 0;
}

int	ft_f_c_write(t_window *w, char *flag, int *arr, int i)
{
	while (flag[w->a_num[0]])
	{
		while (ft_isspace(flag[w->a_num[0]]) != 0)
			w->a_num[0]++;
		w->a_num[1] = w->a_num[0];
		while (ft_isdigit(flag[w->a_num[1]]) != 0 && flag[w->a_num[1]] != 0
			&& flag[w->a_num[1]] != ',')
			w->a_num[1]++;
		if ((w->a_num[1] - w->a_num[0]) > 3)
			return (ft_errors_cub(i));
		(arr[w->a_num[2]] = ft_atoi(&flag[w->a_num[0]]));
		if (arr[w->a_num[2]] > 255)
			return (ft_errors_cub(i));
		if (arr[w->a_num[2]] == 0 && flag[w->a_num[0]] != '0')
			return (ft_errors_cub(i));
		w->a_num[0] = w->a_num[1];
		if (ft_check_digits_fc(w, flag, i) < 0)
			return (-1);
		if (flag[w->a_num[0]] == ',')
			w->a_num[0]++;
		w->a_num[2]++;
	}
	return (1);
}
