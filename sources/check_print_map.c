/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_print_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rasamad <rasamad@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 15:05:09 by rasamad           #+#    #+#             */
/*   Updated: 2024/01/17 23:02:47 by rasamad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// Fonction	: Verifier l'extension du fichier.ber
// Paramètre : nom du fichier.ber
// Retour : un entier --> 1(Succès) ou 0(Échec)
int	ft_check_name_map(const char *filename)
{
	int	len;

	len = ft_strlen((char *)filename);
	if (len < 5)
		return (0);
	len--;
	if (filename[len] != 'r')
		return (0);
	if (filename[len - 1] != 'e')
		return (0);
	if (filename[len - 2] != 'b')
		return (0);
	if (filename[len - 3] != '.')
		return (0);
	return (1);
}

// Fonction	: Innonde les possibiliter dacces du player par des 'V'
// Parametre : char **tiles, int pos_x_player, int pos_y_player
void	check_way(char **copy, int x, int y)
{
	if (copy[y][x] == '1' || copy[y][x] == 'V')
		return ;
	if (copy[y][x] == '0' || copy[y][x] == 'C' || copy[y][x] == 'E')
		copy[y][x] = 'V';
	check_way(copy, x + 1, y);
	check_way(copy, x - 1, y);
	check_way(copy, x, y + 1);
	check_way(copy, x, y - 1);
	return ;
}

// Fonction	: Fait le lien entre les ft d'init et de check
// Parametre 	: nom de la map, structure map
// Retour		: 1 (Succes), 0 (Erreur)
int	check_all(char *filename, t_Map *map)
{
	if (!ft_init_map(filename, map))
	{
		ft_printf("Error\nInitialisation de la map");
		return (0);
	}
	if (!ft_check_map(map))
	{
		ft_printf("Error\nAnalyse de la map");
		return (free_map(map), (0));
	}
	check_way(map->tiles, map->x, map->y);
	if (ft_check_collectible(map))
	{
		ft_printf("Error\nChemin inaccessible vers collectible");
		return (free_map(map), (0));
	}
	if (ft_check_exit(map))
	{
		ft_printf("Error\nChemin inaccessible vers sortie\n");
		return (free_map(map), (0));
	}
	free_map(map);
	if (!ft_init_map(filename, map))
		return (0);
	return (1);
}

// Fonction	: Affiche la map contenu dans char **tiles
// Paramètre	: structure t_Map
void	ft_print_map(t_Map *map)
{
	int	i;

	i = 0;
	ft_printf("Map ok :\n");
	while (i < map->height)
	{
		ft_printf("%s\n", map->tiles[i]);
		i++;
	}
}
