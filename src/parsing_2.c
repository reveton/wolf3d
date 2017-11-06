/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afomenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 16:16:37 by afomenko          #+#    #+#             */
/*   Updated: 2017/10/29 16:18:28 by afomenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf.h"

void	push_other_cords(t_wf **wf, int *cords)
{
	t_wf	*tmp;
	int		**arr;
	int		i;
	int		size;

	size = 1;
	tmp = *wf;
	arr = (int **)malloc(sizeof(int*) * tmp->z_len + size);
	i = 0;
	while (i < tmp->z_len)
	{
		arr[i] = tmp->map[i];
		i++;
	}
	i = 0;
	while (i < size)
	{
		arr[i + tmp->z_len] = cords;
		i++;
	}
	tmp->z_len += size;
	if (tmp->map)
		free(tmp->map);
	tmp->map = arr;
}

int		check_cord(const char *line)
{
	int	i;
	int	len;

	i = 0;
	len = (int)ft_strlen(line);
	if (len != 1)
		ft_put_error();
	while (line[i])
	{
		if (line[i] != '1' && line[i] != '0')
			return (0);
		i++;
	}
	return (1);
}

void	new_cord_z(t_wf *cord, char *arr)
{
	int		*cords;
	char	**str;
	int		i;

	str = ft_strsplit(arr, ' ');
	i = 0;
	if (str[0][0] == '0')
		ft_put_error();
	cords = (int *)malloc(sizeof(int) * cord->count_x);
	while (str[i])
	{
		if (check_cord(str[i]))
			cords[i] = (int)ft_atoi(str[i]);
		else
			ft_put_error();
		i++;
	}
	if (cord->count_x != i)
		ft_put_error();
	if (str[i - 1][0] == '0')
		ft_put_error();
	push_other_cords(&cord, cords);
	free_str(str);
}
