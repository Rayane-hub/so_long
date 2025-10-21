/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rasamad <rasamad@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 15:03:03 by rasamad           #+#    #+#             */
/*   Updated: 2024/01/19 11:25:03 by rasamad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// Fonction : Verifie que char**tiles est entourer de murs '1'
// Paramètre : structure t_Map
// Retour : un entier --> 1(Succès) ou 0(Échec)
int	ft_check_wall(t_Map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (i == 0 && map->tiles[i][j] != '1')
				return (0);
			if (i == (map->height - 1) && map->tiles[i][j] != '1')
				return (0);
			if (j == 0 && map->tiles[i][j] != '1')
				return (0);
			if (j == (map->width - 1) && map->tiles[i][j] != '1')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

// Fonction : Verifie la presence d'un player
// Paramètre : structure t_Map
// Retour : un entier positif nb_personnage == 1 --> (Succès) ou 0(Échec)
int	ft_check_personage(t_Map *map)
{
	int	count;
	int	i;
	int	j;

	count = 0;
	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (map->tiles[i][j] == 'P')
			{
				count++;
				map->x = j;
				map->y = i;
			}
			j++;
		}
		i++;
	}
	if (count != 1)
		return (0);
	return (count);
}

// Fonction : Verifie la presence d'un ou plusieurs collectible
// Paramètre : structure t_Map
// Retour : un entier positif nb_collectible --> (Succès) ou 0(Échec)
int	ft_check_collectible(t_Map *map)
{
	int	count;
	int	i;
	int	j;

	count = 0;
	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (map->tiles[i][j] == 'C')
				count++;
			j++;
		}
		i++;
	}
	map->nb_collectible = count;
	if (count < 1)
		return (0);
	return (count);
}

// Fonction : Verifie la presence d'une ou plusieurs sortie
// Paramètre : structure t_Map
// Retour : un entier positif nb_exit --> (Succès) ou 0(Échec)
int	ft_check_exit(t_Map *map)
{
	int	count;
	int	i;
	int	j;

	count = 0;
	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (map->tiles[i][j] == 'E')
				count++;
			j++;
		}
		i++;
	}
	if (count != 1)
		return (0);
	return (count);
}

// Fonction : apl les ft_check + reste des tiles soit des '0'
// Paramètre : structure t_Map
// Retour : un entier --> 1(Succès) ou 0(Échec)
int	ft_check_map(t_Map *map)
{
	int	i;
	int	j;

	i = 0;
	if (!ft_check_wall(map) || !ft_check_personage(map) \
	|| !ft_check_collectible(map) || !ft_check_exit(map))
		return (0);
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (map->tiles[i][j] != '1' && map->tiles[i][j] != 'P' \
			&& map->tiles[i][j] != 'C' && map->tiles[i][j] != 'E')
			{
				if (map->tiles[i][j] != '0')
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}
