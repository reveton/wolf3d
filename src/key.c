/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afomenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 16:00:29 by afomenko          #+#    #+#             */
/*   Updated: 2017/10/29 16:01:23 by afomenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf.h"

void	key_move(int k, t_wf *wf)
{
	if (k == KEY_UP || k == W)
		wf->moveup = !wf->moveup;
	if (k == KEY_DOWN || k == S)
		wf->movedown = !wf->movedown;
	if (k == KEY_LEFT || k == A)
		wf->moveleft = !wf->moveleft;
	if (k == KEY_RIGHT || k == D)
		wf->moveright = !wf->moveright;
	if (k == KEY_ESC)
	{
		mlx_destroy_window(wf->mlx, wf->win);
		exit(0);
	}
}

void	raise_speed(int k, t_wf *wf)
{
	if (k == 69)
		wf->movespeed += 0.050000000000000003;
	if (wf->movespeed > 0.050000000000000003)
		if (k == 78)
			wf->movespeed -= 0.050000000000000003;
	if (k == 67)
		wf->rotspeed += 0.050000000000000003;
	if (wf->rotspeed > 0.050000000000000003)
		if (k == 75)
			wf->rotspeed -= 0.050000000000000003;
}

int		key_press(int k, t_wf *wf)
{
	key_move(k, wf);
	return (0);
}

int		key_hook(int k, t_wf *wf)
{
	key_move(k, wf);
	raise_speed(k, wf);
	return (0);
}
