/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afomenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 16:07:55 by afomenko          #+#    #+#             */
/*   Updated: 2017/10/29 16:09:18 by afomenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf.h"

void	move_up(t_wf *wf)
{
	if (wf->map[(int)(wf->posx + wf->dirx * wf->movespeed)]
			[(int)wf->posy] == 0)
		wf->posx += wf->dirx * wf->movespeed;
	if (wf->map[(int)wf->posx][(int)(wf->posy + wf->diry * wf->movespeed)] == 0)
		wf->posy += wf->diry * wf->movespeed;
}

void	move_down(t_wf *wf)
{
	if (wf->map[(int)(wf->posx - wf->dirx * wf->movespeed)]
			[(int)wf->posy] == 0)
		wf->posx -= wf->dirx * wf->movespeed;
	if (wf->map[(int)wf->posx][(int)(wf->posy - wf->diry * wf->movespeed)] == 0)
		wf->posy -= wf->diry * wf->movespeed;
}

void	move_right(t_wf *wf)
{
	wf->olddirx = wf->dirx;
	wf->dirx = wf->dirx * cos(-wf->rotspeed) - wf->diry * sin(-wf->rotspeed);
	wf->diry = wf->olddirx * sin(-wf->rotspeed) + wf->diry * cos(-wf->rotspeed);
	wf->olddirx = wf->planex;
	wf->planex = wf->planex * cos(-wf->rotspeed)
		- wf->planey * sin(-wf->rotspeed);
	wf->planey = wf->olddirx * sin(-wf->rotspeed)
		+ wf->planey * cos(-wf->rotspeed);
}

void	move_left(t_wf *wf)
{
	wf->olddirx = wf->dirx;
	wf->dirx = wf->dirx * cos(wf->rotspeed) - wf->diry * sin(wf->rotspeed);
	wf->diry = wf->olddirx * sin(wf->rotspeed) + wf->diry * cos(wf->rotspeed);
	wf->olddirx = wf->planex;
	wf->planex = wf->planex * cos(wf->rotspeed)
		- wf->planey * sin(wf->rotspeed);
	wf->planey = wf->olddirx * sin(wf->rotspeed)
		+ wf->planey * cos(wf->rotspeed);
}
