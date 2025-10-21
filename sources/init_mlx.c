/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rasamad <rasamad@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 13:22:06 by rasamad           #+#    #+#             */
/*   Updated: 2024/01/17 23:03:44 by rasamad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	init_window(t_Map *map)
{
	int	w;
	int	h;

	w = map->width * 100;
	h = map->height * 100;
	ft_check_collectible(map);
	map->count_move = 0;
	map->init_mlx = mlx_init();
	if (!map->init_mlx)
		return ;
	map->win_mlx = mlx_new_window(map->init_mlx, w, h, "So_long");
	update_display(map);
	mlx_hook(map->win_mlx, 17, 0, close_window, map);
	mlx_key_hook(map->win_mlx, key_pressed, map);
	mlx_loop(map->init_mlx);
}

void	update_display(t_Map *map)
{
	int	i;
	int	j;

	i = 0;
	printf("Move : %d\n", map->count_move);
	map->count_move++;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			draw_element(map, map->tiles[i][j], j, i);
			j++;
		}
		i++;
	}
}

void	draw_element(t_Map *map, char element, int x, int y)
{
	char	*image_path;
	int		w;
	int		h;
	void	*img_ptr;

	w = 100;
	h = 100;
	if (element == '1')
		image_path = "img/wall.xpm";
	else if (element == '0')
		image_path = "img/ground.xpm";
	else if (element == 'P')
		image_path = "img/player.xpm";
	else if (element == 'C')
		image_path = "img/collectible.xpm";
	else if (element == 'E')
		image_path = "img/exit.xpm";
	else
		return ;
	img_ptr = mlx_xpm_file_to_image(map->init_mlx, image_path, &w, &h);
	mlx_put_image_to_window(map->init_mlx, \
	map->win_mlx, img_ptr, x * 100, y * 100);
	mlx_destroy_image(map->init_mlx, img_ptr);
}

int	key_pressed(int keycode, void *param)
{
	t_Map	*map;
	int		new_x;
	int		new_y;

	map = (t_Map *)param;
	new_x = map->x;
	new_y = map->y;
	if (keycode == 65307)
		close_window(map);
	else if (keycode == 119)
		new_y--;
	else if (keycode == 97)
		new_x--;
	else if (keycode == 115)
		new_y++;
	else if (keycode == 100)
		new_x++;
	ft_swap_element(map, &new_x, &new_y);
	return (0);
}

void	ft_swap_element(t_Map *map, int *new_x, int *new_y)
{
	if (map->tiles[*new_y][*new_x] == '1')
		return ;
	else if (map->tiles[*new_y][*new_x] == '0')
	{
		map->tiles[*new_y][*new_x] = 'P';
		map->tiles[map->y][map->x] = '0';
		update_display(map);
	}
	else if (map->tiles[*new_y][*new_x] == 'C')
	{
		map->tiles[*new_y][*new_x] = 'P';
		map->tiles[map->y][map->x] = '0';
		map->nb_collectible--;
		update_display(map);
	}
	else if (map->tiles[*new_y][*new_x] == 'E')
	{
		if (map->nb_collectible == 0)
			close_window(map);
		else
			return ;
	}
	map->x = *new_x;
	map->y = *new_y;
}
