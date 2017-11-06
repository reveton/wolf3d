/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afomenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 16:00:29 by afomenko          #+#    #+#             */
/*   Updated: 2017/10/29 17:36:16 by afomenko         ###   ########.fr       */
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

int		key_press(int k, t_wf *wf)
{
	key_move(k, wf);
	return (0);
}

int		key_hook(int k, t_wf *wf)
{
	key_move(k, wf);
	return (0);
}
