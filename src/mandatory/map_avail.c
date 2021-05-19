/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_avail.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyospark <hyospark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 22:01:47 by hyospark          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2021/05/19 22:28:25 by hyospark         ###   ########.fr       */
=======
/*   Updated: 2021/05/07 04:50:10 by hyospark         ###   ########.fr       */
>>>>>>> 8c5d03cbc10d46b391996af9be5dcc938d6a15e4
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		check_map_char(t_map *map, int i, int count)
{
	t_map *tem;
	int max;

	tem = map;
	max = 0;
	while (tem->next_map_line != NULL)
	{
		i = 0;
		while (tem->map[i])
		{
			if (tem->map[i] == 'N')
					count++;
<<<<<<< HEAD
			if (!ft_strchr("012N ",tem->map_line[i]))
				map_error_exit("WRONG_MAP_CAHR", map);
=======
			if (!ft_strchr("012N ",tem->map[i]))
			{
				ft_lstclear_map(map);
				free_error_exit(map,"WRONG_MAP_CAHR");
			}
>>>>>>> 8c5d03cbc10d46b391996af9be5dcc938d6a15e4
			i++;
			if (max < i)
				max = i;
		}
		tem = map->next_map_line;
	}
	if (count != 1)
		map_error_exit("MAP_POS_ERROR", map);
	return (max);
}

void	*set_map(void *ptr, int val, size_t s)
{
	while (s != 0)
	{
		*((int *)ptr + s - 1) = val;
		s--;
	}
	return (ptr);
}

void	make_worldMap(t_config *config, int i, int h, int w)
{
	int		arr[config->mapHeight][config->mapWidth];
	t_map	*tem;

	while (i < config->mapHeight)
		set_map(arr[i++], -1, config->mapWidth);
	tem = config->map;
	while (tem->next_map_line != NULL)
	{
		i = 0;
		while (tem->map[i])
		{
			w = 0;
			if (tem->map[i] == '0' || tem->map[i] == '1' || tem->map[i] == '2')
				arr[h][w] = tem->map[i] - '0';
			else if (tem->map[i] == 'N')
			{
<<<<<<< HEAD
				config->player.x = h;
				config->player.y = w;
=======
				config->player_x = h;
				config->player_y = w;
>>>>>>> 8c5d03cbc10d46b391996af9be5dcc938d6a15e4
				arr[h][w] = 3;
			}
			i++;
		}
		h++;
		tem = config->map->next_map_line;
	}
	config->worldMap = arr;
}

void		dfs_map(t_config *t, int **map, int x, int y)
{
	if (x == 0 || x == t->mapHeight - 1 || y == 0 | y == t->mapWidth - 1)
		free_error_exit(t->map, "INVAILED_MAP");
	if (map[x][y] == 0 || map[x][y] == 3)
		map[x][y] = -2;
	if (map[x][y] == -1)
		free_error_exit(t->map, "INVAILED_MAP");
	if (x < t->mapHeight - 1 && map[x + 1][y] == 0)
		dfs_map(t, map, x + 1, y);
	if (x > 0 && map[x - 1][y] == 0)
		dfs_map(t, map, x - 1, y);
	if (y < t->mapWidth - 1 && map[x][y + 1] == 0)
		dfs_map(t, map, x, y + 1);
	if (y > 0 && map[x][y - 1] == 0)
		dfs_map(t, map, x, y - 1);
}

<<<<<<< HEAD
void	dfs_map_check(t_config *config)
=======
void	dfs_map_check(t_config *config, int player_x, int player_y)
>>>>>>> 8c5d03cbc10d46b391996af9be5dcc938d6a15e4
{
	int **map;

	map = config->worldMap;
<<<<<<< HEAD
	dfs_map(config, map, config->player.x, config->player.y);
=======
	dfs_map(config, map, player_x, player_y);
>>>>>>> 8c5d03cbc10d46b391996af9be5dcc938d6a15e4
}

int		map_avail(t_config *config)
{
	config->mapWidth = check_map_char(config->map, 0, 0);
	config->mapHeight = ft_lstsize_map(config->map);
<<<<<<< HEAD
	dfs_map_check(config);
=======
>>>>>>> 8c5d03cbc10d46b391996af9be5dcc938d6a15e4
	make_worldMap(config, 0, 0, 0);
	dfs_map_check(config, config->player_x, config->player_y);
	return (SUCCESS);
}
