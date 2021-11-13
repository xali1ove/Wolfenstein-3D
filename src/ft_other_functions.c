/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_other_functions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdaphine <gdaphine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 01:56:32 by gdaphine          #+#    #+#             */
/*   Updated: 2021/04/15 01:56:36 by gdaphine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub.h"

int	ft_map_writer_and_i(t_window *w, int i, t_list *m_list)
{
	if (i < 0)
		i = ft_errors_cub(1);
	w->map = ft_map_write(&m_list, w->par);
	if (!w->map)
		i = ft_errors_cub(1);
	ft_lstclear(&m_list, free);
	return (i);
}

void	ft_free_map(t_window *w)
{
	int	i;

	i = 0;
	if (w->map)
	{
		while (i < w->par->m[0])
		{
			free(w->map[i]);
			i++;
		}
	}
}

int	ft_screenshot_write(t_window *w)
{
	ft_bitmap_creater(w);
	free(w->zbuf);
	return (ft_close_before(w));
}
