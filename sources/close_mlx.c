/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rasamad <rasamad@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 11:45:57 by rasamad           #+#    #+#             */
/*   Updated: 2024/01/17 22:50:11 by rasamad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	close_window(void *param)
{
	t_Map	*map;

	map = (t_Map *)param;
	mlx_destroy_window(map->init_mlx, map->win_mlx);
	mlx_destroy_display(map->init_mlx);
	mlx_loop_end(map->init_mlx);
	free(map->init_mlx);
	free_map(map);
	exit(0);
}
