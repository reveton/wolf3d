/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afomenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 16:01:42 by afomenko          #+#    #+#             */
/*   Updated: 2017/10/29 17:15:38 by afomenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf.h"

void	draw_cord_min(t_wf *e, int x, int y, int color)
{
	int	i;
	int	k;

	i = 0;
	while (i <= 5)
	{
		k = 0;
		while (k <= 5)
		{
			put_pxl(e, x + i, y + k, (unsigned int)color);
			k++;
		}
		i++;
	}
}

void	draw_minimap(t_wf *e)
{
	int	i;
	int	k;

	if (e->count_x * 5 > WIDTH / 2 || e->count_y * 5 > WIDTH / 2)
		return ;
	i = 0;
	while (i < e->count_x)
	{
		k = 0;
		while (k < e->count_y)
		{
			if (e->map[k][i] == 1)
				draw_cord_min(e, i + (5 * (i + 1)), k + (5 * (k + 1)),
						0x000000);
			else if ((int)e->posx == k && (int)e->posy == i)
				draw_cord_min(e, i + (5 * (i + 1)), k + (5 * (k + 1)),
						0xFF0000);
			else
				draw_cord_min(e, i + (5 * (i + 1)), k + (5 * (k + 1)),
						0xFFFFFF);
			k++;
		}
		i++;
	}
}

int		loop_hook(t_wf *wf)
{
	wf->last_frame = clock();
	if (wf->next_frame > wf->last_frame)
		return (0);
	wf->next_frame = wf->last_frame + (CLOCKS_PER_SEC / 100);
	if (wf->moveup)
		move_up(wf);
	if (wf->movedown)
		move_down(wf);
	if (wf->moveright)
		move_right(wf);
	if (wf->moveleft)
		move_left(wf);
	draw_wolf(wf);
	draw_minimap(wf);
	mlx_put_image_to_window(wf->mlx, wf->win, wf->img, 0, 0);
	put_info(wf);
	return (0);
}

void	put_info(t_wf *wf)
{
	mlx_string_put(wf->mlx, wf->win, WIDTH - 250, 10,
			0xFFFFFF, "- - -| HOT KEYS |- - -");
	mlx_string_put(wf->mlx, wf->win, WIDTH - 250,
			30, 0xFFFFFF, "MOVE: ARROWS OR W A S D ");
	mlx_string_put(wf->mlx, wf->win, WIDTH - 250, 90, 0xFFFFFF, "QUIT: ESC");
}
