/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afomenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 16:18:37 by afomenko          #+#    #+#             */
/*   Updated: 2017/10/29 16:21:00 by afomenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf.h"

void			put_pxl(t_wf *e, int x, int y, unsigned int c)
{
	int	i;

	i = (x * 4) + (y * e->s_line);
	e->pxl[i] = (char)c;
	e->pxl[++i] = (char)(c >> 8);
	e->pxl[++i] = (char)(c >> 16);
}

unsigned int	get_color(t_wf *e)
{
	if (e->side == 1)
	{
		if ((e->stepx == -1 && e->stepy == -1)
				|| (e->stepx == 1 && e->stepy == -1))
			return (e->color_1);
		if ((e->stepx == -1 && e->stepy == 1)
				|| (e->stepx == 1 && e->stepy == 1))
			return (e->color_2);
	}
	if ((e->stepx == -1 && e->stepy == -1)
			|| (e->stepx == -1 && e->stepy == 1))
		return (e->color_3);
	return (e->color_4);
}

void			draw_line(t_wf *e, int x, int start, int end)
{
	int				i;
	unsigned int	c;

	c = get_color(e);
	i = -1;
	while (++i < start)
		put_pxl(e, x, i, e->color_sky);
	i--;
	while (++i <= end && i < HEIGHT)
		put_pxl(e, x, i, c);
	i--;
	while (++i < HEIGHT)
		put_pxl(e, x, i, e->color_ground);
}

void			draw_wolf(t_wf *wf)
{
	int x;

	x = 0;
	if (wf->map[(int)wf->posx][(int)wf->posy] == 1)
		ft_put_error();
	while (x < WIDTH)
	{
		init_ray(wf, x);
		get_dir_ray(wf);
		check_hit_ray(wf);
		get_ray_size(wf);
		draw_line(wf, x, wf->drawstart, wf->drawend);
		x++;
	}
}
