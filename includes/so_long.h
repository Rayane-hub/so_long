/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rasamad <rasamad@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 14:17:49 by rasamad           #+#    #+#             */
/*   Updated: 2024/01/18 12:37:31 by rasamad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include "get_next_line.h"
# include "../ft_printf/ft_printf.h"
# include "../minilibx-linux/mlx.h"

typedef struct game_map
{
	void	*init_mlx;
	void	*win_mlx;
	int		x;
	int		y;
	int		width;
	int		height;
	char	**tiles;
	int		nb_collectible;
	int		count_move;
}	t_Map;
size_t	ft_strlen(char *s);
char	*ft_strncpy(char *dst, const char *src, size_t length);
int		ft_check_name_map(const char *filename);
void	free_map(t_Map *map);
int		ft_dimension(const char *filename, t_Map *map);
int		ft_init_map(const char *filename, t_Map *map);
int		ft_check_wall(t_Map *map);
int		ft_check_personage(t_Map *map);
int		ft_check_collectible(t_Map *map);
int		ft_check_exit(t_Map *map);
int		ft_check_map(t_Map *map);
void	check_way(char **copy, int x, int y);
int		check_all(char *filename, t_Map *map);
void	ft_print_map(t_Map *map);
void	init_window(t_Map *map);
void	update_display(t_Map *map);
void	draw_element(t_Map *map, char element, int x, int y);
int		key_pressed(int keycode, void *param);
void	ft_swap_element(t_Map *map, int *new_x, int *new_y);
int		close_window(void *param);

#endif