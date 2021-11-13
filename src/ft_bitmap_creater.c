/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bitmap_creater.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdaphine <gdaphine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 01:59:45 by gdaphine          #+#    #+#             */
/*   Updated: 2021/04/15 01:59:51 by gdaphine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub.h"

static void	ft_fileheader(unsigned char *bmpfileheader, int *d,
							int p, t_window *w)
{
	d[0] = 54 + (3 * w->par->r[0] + p) * (w->par->r[1]);
	d[1] = 0;
	while (d[1] < 14)
	{
		bmpfileheader[d[1]] = (unsigned char)(0);
		d[1]++;
	}
	bmpfileheader[0] = (unsigned char)('B');
	bmpfileheader[1] = (unsigned char)('M');
	bmpfileheader[2] = (unsigned char)(d[0]);
	bmpfileheader[3] = (unsigned char)(d[0] >> 8);
	bmpfileheader[4] = (unsigned char)(d[0] >> 16);
	bmpfileheader[5] = (unsigned char)(d[0] >> 24);
	bmpfileheader[10] = (unsigned char)(54);
}

static void	ft_infoheader(unsigned char *bmpinfoheader, int *d, t_window *w)
{
	d[1] = 0;
	while (d[1] < 40)
	{
		bmpinfoheader[d[1]] = (unsigned char)(0);
		d[1]++;
	}
	bmpinfoheader[0] = (unsigned char)(40);
	bmpinfoheader[4] = (unsigned char)(w->par->r[0]);
	bmpinfoheader[5] = (unsigned char)(w->par->r[0] >> 8);
	bmpinfoheader[6] = (unsigned char)(w->par->r[0] >> 16);
	bmpinfoheader[7] = (unsigned char)(w->par->r[0] >> 24);
	bmpinfoheader[8] = (unsigned char)(w->par->r[1]);
	bmpinfoheader[9] = (unsigned char)((w->par->r[1]) >> 8);
	bmpinfoheader[10] = (unsigned char)((w->par->r[1]) >> 16);
	bmpinfoheader[11] = (unsigned char)((w->par->r[1]) >> 24);
	bmpinfoheader[12] = (unsigned char)(1);
	bmpinfoheader[14] = (unsigned char)(24);
}

static void	ft_pallet(unsigned char *rgb, int *d, int p, t_window *w)
{
	d[1] = 0;
	d[3] = w->par->r[1];
	while (d[1] < d[3])
	{
		d[2] = 0;
		while (d[2] < w->par->r[0])
		{
			p = (*(int *)(w->data->addr + (d[2] * w->data->bits_per_pixel / 8
							+ d[3] * w->data->line_length)));
			rgb[2] = (unsigned char)(p / 65536);
			rgb[1] = (unsigned char)((p - (rgb[1] * 65536)) / 256);
			rgb[0] = (unsigned char)(p - ((rgb[1] * 65536) + (rgb[2] * 256)));
			write(d[0], rgb, 3);
			d[2]++;
		}
		d[3]--;
	}
}

void	ft_bitmap_creater(t_window *w)
{
	unsigned char	bmpfileheader[14];
	unsigned char	bmpinfoheader[40];
	unsigned char	rgb[3];
	int				d[4];
	int				p;

	p = (4 - (w->par->r[0] * 3) % 4) % 4;
	ft_fileheader(bmpfileheader, d, p, w);
	ft_infoheader(bmpinfoheader, d, w);
	d[0] = open("./cub3d.bmp", O_CREAT | O_RDWR, 416);
	if (d[0] > 0)
	{
		write(d[0], bmpfileheader, 14);
		write(d[0], bmpinfoheader, 40);
		ft_pallet(rgb, d, p, w);
		close(d[0]);
	}
	w->sshot = 0;
}
