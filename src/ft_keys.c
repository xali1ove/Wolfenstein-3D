/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keys.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdaphine <gdaphine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 01:57:22 by gdaphine          #+#    #+#             */
/*   Updated: 2021/04/15 01:57:25 by gdaphine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub.h"

int	ft_key_release(int keycode, t_window *w)
{
	if (keycode == 126 || keycode == 13)
		w->key_press[0] = 0;
	if (keycode == 125 || keycode == 1)
		w->key_press[1] = 0;
	if (keycode == 0)
		w->key_press[2] = 0;
	if (keycode == 2)
		w->key_press[3] = 0;
	if (keycode == 123)
		w->key_press[4] = 0;
	if (keycode == 124)
		w->key_press[5] = 0;
	return (0);
}

int	ft_key_press(int keycode, t_window *w)
{
	if (keycode == 53)
		return (ft_close(w));
	if (keycode == 126 || keycode == 13)
		w->key_press[0] = 1;
	if (keycode == 125 || keycode == 1)
		w->key_press[1] = 1;
	if (keycode == 0)
		w->key_press[2] = 1;
	if (keycode == 2)
		w->key_press[3] = 1;
	if (keycode == 123)
		w->key_press[4] = 1;
	if (keycode == 124)
		w->key_press[5] = 1;
	return (0);
}
