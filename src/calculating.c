/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculating.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afomenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 15:39:47 by afomenko          #+#    #+#             */
/*   Updated: 2017/10/29 15:53:55 by afomenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf.h"

void	init_ray(t_wf *wf, int x)
{
	wf->rayposx = wf->posx;
	wf->rayposy = wf->posy;
	wf->mapx = (int)wf->rayposx;
	wf->mapy = (int)wf->rayposy;
	wf->camera = 2 * x / (double)(WIDTH) - 1;
	wf->raydirx = wf->dirx + wf->planex * wf->camera;
	wf->raydiry = wf->diry + wf->planey * wf->camera;
	wf->deltadistx = sqrt(1 + (wf->raydiry * wf->raydiry)
			/ (wf->raydirx * wf->raydirx));
	wf->deltadisty = sqrt(1 + (wf->raydirx * wf->raydirx)
			/ (wf->raydiry * wf->raydiry));
	wf->hit = 0;
	wf->perpwalldist = -1;
	wf->side = -1;
}

void	get_dir_ray(t_wf *wf)
{
	if (wf->raydirx < 0)
	{
		wf->stepx = -1;
		wf->sidedistx = (wf->rayposx - wf->mapx) * wf->deltadistx;
	}
	else
	{
		wf->stepx = 1;
		wf->sidedistx = (wf->mapx + 1 - wf->rayposx) * wf->deltadistx;
	}
	if (wf->raydiry < 0)
	{
		wf->stepy = -1;
		wf->sidedisty = (wf->rayposy - wf->mapy) * wf->deltadisty;
	}
	else
	{
		wf->stepy = 1;
		wf->sidedisty = (wf->mapy + 1 - wf->rayposy) * wf->deltadisty;
	}
}

void	check_hit_ray(t_wf *wf)
{
	while (wf->hit == 0)
	{
		if (wf->sidedistx < wf->sidedisty)
		{
			wf->sidedistx += wf->deltadistx;
			wf->mapx += wf->stepx;
			wf->side = 0;
		}
		else
		{
			wf->sidedisty += wf->deltadisty;
			wf->mapy += wf->stepy;
			wf->side = 1;
		}
		if (wf->map[wf->mapx][wf->mapy] > 0)
		{
			wf->hit = 1;
			if (wf->side == 0)
				wf->perpwalldist = (wf->mapx - wf->rayposx
						+ (1 - wf->stepx) / 2) / wf->raydirx;
			else
				wf->perpwalldist = (wf->mapy - wf->rayposy
						+ (1 - wf->stepy) / 2) / wf->raydiry;
		}
	}
}

void	get_ray_size(t_wf *wf)
{
	wf->lineheight = (int)(HEIGHT / wf->perpwalldist);
	wf->drawstart = -wf->lineheight / 2 + HEIGHT / 2;
	if (wf->drawstart < 0)
		wf->drawstart = 0;
	wf->drawend = wf->lineheight / 2 + HEIGHT / 2;
	if (wf->drawend >= HEIGHT)
		wf->drawend = HEIGHT - 1;
}
