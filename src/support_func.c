/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   support_func.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afomenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 16:21:08 by afomenko          #+#    #+#             */
/*   Updated: 2017/10/29 16:22:04 by afomenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf.h"

int		exit_x(void *par)
{
	par = NULL;
	exit(0);
	return (0);
}

void	ft_put_error(void)
{
	ft_printf("\033[31mInvalid map\n\033[31m");
	exit(0);
}

void	free_str(char **str)
{
	int i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	check_arg_err(int ac)
{
	if (ac < 2)
	{
		ft_printf("\033[32mUsage: ./wolf3d <map>\n\033[32m");
		exit(0);
	}
	else if (ac >= 3)
	{
		ft_printf("\033[32mPlease use only one map\n\033[32m");
		exit(0);
	}
}
