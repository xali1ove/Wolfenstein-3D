/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorter_sprites.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdaphine <gdaphine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 01:56:10 by gdaphine          #+#    #+#             */
/*   Updated: 2021/04/15 01:56:15 by gdaphine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub.h"

static void	ft_sorter_end(t_window *w, t_sprt *f, t_sprt *s, t_sprt *t)
{
	w->a_num[0] = 0;
	t = w->sprt;
	while (w->a_num[0] < w->exam)
	{
		s = t;
		t = t->next;
		w->a_num[0]++;
	}
	s->next = f;
	f->next = t;
}

static void	ft_sorter(t_window *w, t_sprt *f)
{
	t_sprt	*s;
	t_sprt	*t;

	s = NULL;
	t = NULL;
	w->a_num[0] = 0;
	while (w->a_num[0] < w->a_num[1])
	{
		s = f;
		f = f->next;
		t = f->next;
		w->a_num[0]++;
	}
	s->next = t;
	if (w->exam == 0)
	{
		f->next = w->sprt;
		w->sprt = f;
	}
	else
		ft_sorter_end(w, f, s, t);
}

static void	ft_first_part_sort(t_window *w, t_sprt *first)
{
	w->a_num[0] = 0;
	w->a_num[1] = 0;
	w->a_num[2] = 0;
	while (first)
	{
		if (w->a_num[0] < first->distance)
		{
			w->a_num[0] = first->distance;
			w->a_num[1] = w->a_num[2];
		}
		w->a_num[2]++;
		first = first->next;
	}
}

static t_sprt	*ft_shift_struc(t_window *w, t_sprt *first)
{
	w->a_num[0] = 0;
	while (w->a_num[0] < w->exam)
	{
		first = first->next;
		w->a_num[0]++;
	}
	return (first);
}

void	ft_sort_sprites(t_window *w)
{
	t_sprt	*first;

	first = w->sprt;
	w->exam = 0;
	while (first)
	{
		ft_first_part_sort(w, first);
		first = w->sprt;
		first = ft_shift_struc(w, first);
		if (w->a_num[1] != 0)
			ft_sorter(w, first);
		w->exam++;
		first = w->sprt;
		first = ft_shift_struc(w, first);
	}
}
