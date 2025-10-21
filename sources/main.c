/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rasamad <rasamad@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 13:45:08 by rasamad           #+#    #+#             */
/*   Updated: 2024/01/19 12:13:35 by rasamad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int ac, char **av)
{
	t_Map	game_map;

	if (ac != 2)
	{
		ft_printf("Error\nNombre d'argument incorrect.");
		return (0);
	}
	if (!ft_check_name_map(av[1]))
	{
		ft_printf("Error\nNom de map incorrect");
		return (0);
	}
	if (check_all(av[1], &game_map))
	{
		ft_print_map(&game_map);
		init_window(&game_map);
	}
	return (0);
}
