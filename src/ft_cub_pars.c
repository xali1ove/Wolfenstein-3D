/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub_pars.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdaphine <gdaphine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 01:59:14 by gdaphine          #+#    #+#             */
/*   Updated: 2021/04/15 01:59:17 by gdaphine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub.h"

static int	ft_map_pars(t_list **lst, char *flag, t_window *w)
{
	t_list	*b_list;
	int		i;

	i = 0;
	b_list = NULL;
	if (*lst == NULL)
		*lst = ft_lstnew(flag);
	else
	{
		b_list = ft_lstnew(flag);
		ft_lstadd_back(lst, b_list);
	}
	if (w->map_start == 2)
		return (ft_errors_cub(8));
	w->map_start = 1;
	return (0);
}

int	ft_ref_pars(t_window *w, char *flag)
{
	int	i;

	i = 0;
	if (flag[1] == 'O' || flag[1] == 'E' || flag[1] == 'A')
		i = ft_texture_parser(w, flag);
	else if (flag[0] == 'R' && w->par_pars[0] == 0)
		i = ft_resolution_parser(w, flag);
	else if (flag[0] == 'S' && flag[1] != 'O' && w->par_pars[5] == 0)
		i = ft_sprite_parser(w, flag);
	else if (flag[0] == 'F' && w->par_pars[6] == 0)
		i = ft_floor_parser(w, flag);
	else if (flag[0] == 'C' && w->par_pars[7] == 0)
		i = ft_cell_parser(w, flag);
	else
		return (ft_errors_cub(9));
	return (i);
}

char	**ft_map_write(t_list **start_list, t_params *par)
{
	t_list	*b_list;
	int		size;
	int		i;
	char	**map;

	b_list = *start_list;
	i = 0;
	size = ft_lstsize(*start_list);
	par->m[0] = size;
	map = (char **)malloc(sizeof(char *) * size + sizeof(char *));
	if (!map)
		return (NULL);
	while (i < size)
	{
		map[i] = ft_strdup(b_list->content);
		if (!map[i])
			return (map);
		if ((int)ft_strlen(map[i]) > par->m[1])
			par->m[1] = (int)ft_strlen(map[i]);
		b_list = b_list->next;
		i++;
	}
	map[i] = NULL;
	return (map);
}

static int	ft_map_par_parser(char *flag, t_window *w, t_list **m_list)
{
	int	i;

	i = 0;
	if (flag[0] == 0)
	{
		if (w->map_start == 1)
			return (ft_error_w_free(0, &flag));
		free(flag);
		return (1);
	}
	while (ft_isspace(flag[i]) != 0)
		i++;
	if (ft_sum_par_pars(w) > 0)
	{
		if ((ft_map_pars(m_list, flag, w)) < 0)
			return (-1);
		return (1);
	}
	else
		i = ft_ref_pars(w, &flag[i]);
	free(flag);
	flag = NULL;
	return (i);
}

int	ft_cub_pars(char **argv, t_window *w)
{
	char		*flag;
	t_list		*m_list;
	int			i;
	int			fd;

	flag = NULL;
	m_list = NULL;
	w->map_start = 0;
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (ft_errors_cub(0));
	i = get_next_line(fd, &flag, 1000);
	while (i > 0)
	{
		if ((ft_map_par_parser(flag, w, &m_list)) < 0)
			return (ft_error_w_close(&fd));
		i = get_next_line(fd, &flag, 1000);
	}
	if ((ft_map_par_parser(flag, w, &m_list)) < 0)
		return (ft_error_w_close(&fd));
	close(fd);
	if ((ft_map_writer_and_i(w, i, m_list)) < 0)
		return (-1);
	return (1);
}
