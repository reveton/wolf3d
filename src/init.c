/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afomenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 15:54:24 by afomenko          #+#    #+#             */
/*   Updated: 2017/10/29 16:00:23 by afomenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf.h"

void	init_player(t_wf *wf)
{
	wf->posx = 1.5;
	wf->posy = 1.5;
	wf->dirx = -1;
	wf->diry = 0;
	wf->planex = 0;
	wf->planey = 0.66;
	wf->movespeed = 0.05;
	wf->rotspeed = 0.05;
}

void	init_map(t_wf *wf)
{
	wf->color_1 = 0x0000CD;
	wf->color_2 = 0xD2691E;
	wf->color_3 = 0x4B0082;
	wf->color_4 = 0x8B008B;
	wf->color_sky = 0x00cdff;
	wf->color_ground = 0xA9A9A9;
}

void	init_struct(t_wf **wf)
{
	t_wf *tmp;

	tmp = (t_wf*)malloc(sizeof(t_wf));
	tmp->count_y = 0;
	tmp->count_x = 0;
	tmp->mlx = mlx_init();
	tmp->bpp = 0;
	tmp->s_line = 0;
	tmp->img = mlx_new_image(tmp->mlx, WIDTH, HEIGHT);
	tmp->pxl = mlx_get_data_addr(tmp->img,
			&(tmp->bpp), &(tmp->s_line), &(tmp->ed));
	tmp->next_frame = 0;
	tmp->last_frame = clock();
	tmp->z_len = 0;
	tmp->movedown = 0;
	tmp->moveleft = 0;
	tmp->moveright = 0;
	tmp->moveup = 0;
	tmp->deltadistx = 0;
	tmp->deltadisty = 0;
	init_player(tmp);
	init_map(tmp);
	*wf = tmp;
}
