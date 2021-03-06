/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afomenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 16:09:54 by afomenko          #+#    #+#             */
/*   Updated: 2017/11/06 15:38:09 by afomenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf.h"

void	parse_cord(t_wf *wf, char *line)
{
	wf->count_y++;
	new_cord_z(wf, line);
}

int		count_coord_x(char *line)
{
	char	**str;
	int		i;

	i = 0;
	str = ft_strsplit(line, ' ');
	while (str[i])
		i++;
	free_str(str);
	return (i);
}

int		check_line(const char *line)
{
	int i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '0')
			ft_put_error();
		i++;
	}
	return (1);
}

int		check_map(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (!check_line(line))
			return (0);
		i++;
	}
	return (1);
}

int		parse_coords(int fd, t_wf *wf, char *line)
{
	int i;

	i = 0;
	while (get_next_line(fd, &line) && line)
	{
		if (line[0] == '\0' || line[0] == '\n')
			ft_put_error();
		if (i == 0)
		{
			wf->count_x = count_coord_x(line);
			if (check_map(line))
				parse_cord(wf, line);
		}
		else
			parse_cord(wf, line);
		if (line[0] != '\n' && line[1] != '\n')
			free(line);
		i++;
	}
	if (wf->count_y < 3 || !check_map(line))
		ft_put_error();
	return (1);
}
