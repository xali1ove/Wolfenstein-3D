/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdaphine <gdaphine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 01:54:37 by gdaphine          #+#    #+#             */
/*   Updated: 2021/04/15 01:54:43 by gdaphine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub.h"

int	ft_close_before(t_window *w)
{
	ft_free_map(w);
	free(w->par->no);
	free(w->par->so);
	free(w->par->we);
	free(w->par->ea);
	free(w->par->s);
	free(w->map);
	free(w->mlx);
	free(w->data);
	free(w->no);
	free(w->so);
	free(w->we);
	free(w->ea);
	free(w->sp);
	free(w->ray);
	free(w->par);
	free(w);
	return (0);
}

static int	ft_check_args(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc < 2 || argc > 3)
	{
		write(1, "Error\nunknown arguments\n", 24);
		return (0);
	}
	if (argc == 3 && (ft_strncmp(&argv[2][i], "--save", 1000000)) != 0)
	{
		write(1, "Error\nunknown arguments\n", 24);
		return (0);
	}
	i = ft_strlen(argv[1]) - 1;
	while (argv[1][i] != '.')
		i--;
	if (ft_strlen(&argv[1][i]) != 4
		&& ft_strncmp(&argv[1][i], ".cub", 1000000) != 0)
	{
		write(1, "Error\nunknown file extension\n", 29);
		return (0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_window	*w;

	w = NULL;
	if ((ft_check_args(argc, argv)) == 0)
		return (0);
	w = new_lstwindow(argc);
	if (!w)
		return (0);
	w->exam = 1;
	if ((ft_cub_pars(argv, w)) < 0)
		return (ft_close_before(w));
	if ((ft_map_valid(w)) < 0)
		return (ft_close_before(w));
	ft_first_image(w);
	w->mlx->mlx = mlx_init();
	if (w->sshot == 0)
		ft_without_screen(w);
	else
		ft_with_screen(w);
	return (0);
}
