/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afomenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 16:07:00 by afomenko          #+#    #+#             */
/*   Updated: 2017/10/29 16:07:43 by afomenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf.h"

int	main(int ac, char **av)
{
	t_wf	*wf;
	int		fd;

	fd = open(av[1], O_RDONLY);
	init_struct(&wf);
	check_arg_err(ac);
	if (parse_coords(fd, wf, 0) == 0)
		ft_put_error();
	wf->win = mlx_new_window(wf->mlx, WIDTH, HEIGHT, "wolf3d");
	mlx_do_key_autorepeatoff(wf->mlx);
	mlx_hook(wf->win, 17, 1L << 17, exit_x, wf);
	mlx_loop_hook(wf->mlx, loop_hook, wf);
	mlx_hook(wf->win, KEY_PRESS, KEY_PRESS_MASK, key_press, wf);
	mlx_key_hook(wf->win, key_hook, wf);
	mlx_loop(wf->mlx);
	return (0);
}
