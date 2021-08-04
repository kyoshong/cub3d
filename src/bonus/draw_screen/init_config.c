/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_config.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyospark <hyospark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 21:31:55 by hyospark          #+#    #+#             */
/*   Updated: 2021/08/04 20:27:59 by hyospark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	set_config(t_config *config, t_info *info)
{
	if ((info->mlx = mlx_init()) == NULL)
		free_map_error_exit(config->map, "MLX_INIT_ERROR");
	info->width = 640;
	info->height = 480;
	info->posX = config->player.x;
	info->posY = config->player.y;
	info->dirX = -1.0;
	info->dirY = 0.0;
	info->planeX = 0.0;
	info->planeY = 0.66;
	info->key_a = 0;
	info->key_w = 0;
	info->key_s = 0;
	info->key_d = 0;
	info->key_esc = 0;
	info->moveSpeed = 0.05;
	info->rotSpeed = 0.05;
	info->config = config;
}

void	set_buf(t_info *info)
{
	int i;
	int j;

	i = 0;
	info->buf = (int **)malloc(sizeof(int*) * info->height);
	while (i < info->height)
	{
		j = 0;
		info->buf[i] = (int *)malloc(sizeof(int) * info->width);
		while (j < info->width)
		{
			info->buf[i][j] = 0;
			j++;
		}
		i++;
	}
}

void	set_texture(t_info *info, int i, int j)
{
	if (!(info->texture = (int **)malloc(sizeof(int *) * 11)))
		return ;
	while (i < 10)
	{
		if (!(info->texture[i] = (int *)malloc(sizeof(int) * (textHeight * textWidth))))
			return ;
		i++;
	}
	if (!(info->texture[i] = (int *)malloc(sizeof(int) * (600 * 400))))
			return ;
	i = 0;
	while (i < 11)
	{
		j = 0;
		while (j < textHeight * textWidth)
		{
			info->texture[i][j] = 0;
			j++;
		}
		i++;
	}
}