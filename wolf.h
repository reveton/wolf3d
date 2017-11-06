/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afomenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 16:22:27 by afomenko          #+#    #+#             */
/*   Updated: 2017/11/06 16:33:19 by afomenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_WOLF_H
# define WOLF3D_WOLF_H
# include <mlx.h>
# include <fcntl.h>
# include "libft/libft.h"
# include <time.h>
# include <math.h>
# define HEIGHT 1080
# define WIDTH 1920
# define KEY_UP 126
# define KEY_DOWN 125
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define W 13
# define A 0
# define S 1
# define D 2
# define KEY_ESC 53
# define KEY_PRESS_MASK (1L<<0)
# define KEY_PRESS 2

typedef struct		s_wf
{
	void			*win;
	void			*mlx;
	void			*img;
	char			*pxl;
	int				bpp;
	int				s_line;
	int				ed;
	int				count_y;
	int				count_x;
	double			posx;
	double			posy;
	double			dirx;
	double			diry;
	double			planex;
	double			planey;
	double			rayposx;
	double			rayposy;
	double			raydirx;
	double			raydiry;
	double			camera;
	int				mapx;
	int				mapy;
	double			sidedistx;
	double			sidedisty;
	double			deltadistx;
	double			deltadisty;
	int				hit;
	int				stepx;
	int				stepy;
	double			perpwalldist;
	int				side;
	int				lineheight;
	int				drawstart;
	int				drawend;
	int				**map;
	int				z_len;
	unsigned int	color_1;
	unsigned int	color_2;
	unsigned int	color_3;
	unsigned int	color_4;
	unsigned int	color_sky;
	clock_t			last_frame;
	clock_t			next_frame;
	double			movespeed;
	double			rotspeed;
	unsigned int	color_ground;
	double			olddirx;
	char			moveup;
	char			movedown;
	char			moveright;
	char			moveleft;
}					t_wf;

void				new_cord_z(t_wf *cord, char *arr);
int					exit_x(void *par);
void				init_struct(t_wf **wf);
void				draw_wolf(t_wf *wf);
void				init_ray(t_wf *wf, int x);
void				get_dir_ray(t_wf *wf);
void				ft_put_error(void);
void				check_hit_ray(t_wf *wf);
void				get_ray_size(t_wf *wf);
void				free_str(char **str);
int					count_coord_x(char *line);
int					parse_coords(int fd, t_wf *wf, char *line);
int					loop_hook(t_wf *wf);
void				move_up(t_wf *wf);
void				move_left(t_wf *wf);
void				move_down(t_wf *wf);
void				move_right(t_wf *wf);
int					key_hook(int keycode, t_wf *wf);
void				key_move(int k, t_wf *wf);
int					key_press(int k, t_wf *wf);
void				put_info(t_wf *wf);
void				put_pxl(t_wf *e, int x, int y, unsigned int c);
void				check_arg_err(int ac);
#endif
