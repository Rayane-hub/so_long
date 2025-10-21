/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rasamad <rasamad@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 14:43:38 by rasamad           #+#    #+#             */
/*   Updated: 2024/01/19 12:00:25 by rasamad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// Fonction		: Compte la len d'une string
// Parametre	: Chaine de caractere
// Retour		: Longueur de la chaine de type size_t 
size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 1;
	while (s[i] != '\n' && s[i])
		i++;
	return (i);
}

// Fonction		: Copie la chaine src dans dst en fonction de length
// Parametre	: Chaine destination, source, longueur a copier
// Retour		: Chaine destination
char	*ft_strncpy(char *dst, const char *src, size_t length)
{
	size_t	i;

	i = 0;
	while (i < length)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
	return (dst);
}

// Fonction : Libère la mémoire allouée pour char **tiles
// Paramètre : structure t_Map
void	free_map(t_Map *map)
{
	int	i;

	i = 0;
	while (i < map->height)
	{
		free(map->tiles[i]);
		i++;
	}
	free(map->tiles);
}

// Fonction		: Permet de recuperer la largeur et la hauteur du fichier.ber
// Paramètre 	: nom du fichier.ber, structure t_Map
// Retour 		: un entier --> 1(Succès) ou 0(Échec)
int	ft_dimension(const char *filename, t_Map *map)
{
	char	*line;
	int		fd;

	map->height = 0;
	fd = open(filename, O_RDONLY);
	if (!fd)
		return (0);
	line = get_next_line(fd);
	if (!line)
		return (0);
	map->width = ft_strlen(line);
	while (line)
	{
		if (((int)ft_strlen(line) != map->width))
			return (free(line), (0));
		free(line);
		map->height++;
		line = get_next_line(fd);
	}
	return (close(fd), 1);
}

// Fonction 	: Rempli char **tiles avec les élements du fichier.ber
// Paramètre 	: nom du fichier.ber, structure t_Map
// Retour 		: un entier --> 1(Succès) ou 0(Échec)
int	ft_init_map(const char *filename, t_Map *map)
{
	char	*line;
	int		i;
	int		fd;

	i = 0;
	if (ft_dimension(filename, map) == 0)
		return (0);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);
	map->tiles = (char **)malloc(map->height * sizeof(char *));
	if (map->tiles == NULL)
		return (close(fd), 0);
	line = get_next_line(fd);
	while (line)
	{
		map->tiles[i] = (char *)malloc((map->width + 1) * sizeof(char));
		if (map->tiles[i] == NULL)
			return (free_map(map), free(line), close(fd), 0);
		ft_strncpy(map->tiles[i], line, map->width);
		free(line);
		i++;
		line = get_next_line(fd);
	}
	return (close(fd), 1);
}
