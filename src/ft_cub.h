/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdaphine <gdaphine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 01:59:06 by gdaphine          #+#    #+#             */
/*   Updated: 2021/04/15 01:59:09 by gdaphine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CUB_H
# define FT_CUB_H

# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <fcntl.h>
# include "../mlx/minilibx_mms/mlx.h"
# include "../libft/libft.h"

typedef struct s_board
{
	int				brd[8];
	int				err[5];
	int				points[8];
	int				mark[3];
}					t_board;

typedef struct s_params
{
	int				r[2];
	void			*no;
	void			*so;
	void			*we;
	void			*ea;
	void			*s;
	int				rotate;
	int				f[3];
	int				c[3];
	int				pl[4];
	int				m[2];
}					t_params;

typedef struct s_data
{
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	int				x;
	int				y;
}					t_data;

typedef struct s_ray
{
	double			nul[2];
	double			old[2];
	double			dir[2];
	double			raydir[2];
	double			plane[2];
	double			camera[2];
	double			deltadist[2];
	double			sidedist[2];
	int				step[2];
	int				map[2];
	double			wall;
	int				side;
}					t_ray;

typedef struct s_sprt
{
	char			number;
	float			x;
	float			y;
	int				distance;
	void			*next;
}					t_sprt;

typedef struct s_screen
{
	void			*mlx;
	void			*mlw;
}					t_screen;

typedef struct s_window
{
	char			**map;
	t_params		*par;
	t_ray			*ray;
	t_screen		*mlx;
	t_data			*data;
	t_data			*no;
	t_data			*so;
	t_data			*we;
	t_data			*ea;
	t_data			*sp;
	t_sprt			*sprt;
	char			**copy_map;
	int				sizex;
	int				sizey;
	int				sshot;
	double			wall[2];
	int				tex[2];
	double			step;
	double			texpos;
	double			*zbuf;
	int				key_press[6];
	float			ms[3];
	int				a_num[4];
	int				par_pars[9];
	int				exam;
	int				map_start;
}					t_window;

int					get_next_line(int fd, char **line, int buffers);
int					ft_cub_pars(char **argv, t_window *w);
int					ft_new_position(t_window *w);
t_window			*new_lstwindow(int argc);
int					ft_isspace(char c);
int					my_mlx_pixel_put(t_window *w);
int					ft_close(t_window *w);
int					ft_errors_memory(int sig);
int					ft_errors_cub(int sig);
int					ft_map_writer_and_i(t_window *w, int i, t_list *m_list);
char				**ft_map_write(t_list **start_list, t_params *par);
int					ft_map_valid(t_window *w);
int					ft_draw_main_screen(t_window *w);
void				ft_ch_tex(t_window *w, int *i);
int					ft_ch_color(t_window *w);
void				ft_correct_dir(t_window *w);
void				ft_wall_steper(t_window *w);
int					ft_sprite_search(t_window *w);
int					ft_write_sprite(t_window *w);
t_sprt				*ft_creat_sprt(t_window *w);
unsigned int		ft_color_creater(int *c);
void				ft_sprite_reader(t_window *w);
int					ft_start_ray(t_window *w);
void				ft_free_map(t_window *w);
void				ft_move_left(t_window *w);
void				ft_move_right(t_window *w);
int					ft_key_release(int keycode, t_window *w);
int					ft_key_press(int keycode, t_window *w);
int					ft_texture_parser(t_window *w, char *flag);
int					ft_texture_writer(t_window *w, char *flag, char *start);
int					ft_resolution_parser(t_window *w, char *flag);
int					ft_resolution_writer(t_window *w, char *flag, int i);
int					ft_check_after_res(t_window *w, char *flag);
int					ft_sprite_parser(t_window *w, char *flag);
int					ft_floor_parser(t_window *w, char *flag);
int					ft_cell_parser(t_window *w, char *flag);
int					ft_f_c_write(t_window *w, char *flag, int *arr, int i);
int					ft_true_end(char *str);
int					ft_is_valid_map(char c);
int					ft_draw_rays(t_window *w);
void				null_creater(t_window *w);
void				ft_bitmap_creater(t_window	*w);
int					ft_draw_sprite(t_window *w);
void				ft_shift_mark(int **arr, t_board *fb, int x, int y);
void				ft_check_down_side(int **arr, t_board *fb, int c);
void				ft_check_up_side(int **arr, t_board *fb, int c);
int					ft_check_spaces(char **map, t_params *par, int x, int y);
void				ft_first_image(t_window *w);
int					ft_check_copy_map(t_window *w);
int					ft_check_fild_map(t_window *w, int y, int x);
int					ft_check_corner(t_window *w, int y, int x);
int					ft_without_screen(t_window *w);
int					ft_with_screen(t_window *w);
int					ft_close_before(t_window *w);
int					ft_end_func(t_window *w, t_sprt *sort);
int					ft_screenshot_write(t_window *w);
int					ft_check_udlr(t_window *w, int y, int x);
int					ft_sum_par_pars(t_window *w);
int					ft_after_texture(t_window *w, char *flag);
int					ft_res_file(char *str);
void				ft_sort_sprites(t_window *w);
int					ft_ref_pars(t_window *w, char *flag);
int					ft_error_w_free(int sig, char **f);
int					ft_error_w_close(int *f);
int					ft_check_digits_fc(t_window *w, char *flag, int i);

#endif
