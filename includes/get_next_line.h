/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rasamad <rasamad@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 15:31:08 by rasamad           #+#    #+#             */
/*   Updated: 2024/01/16 17:50:03 by rasamad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>

char	*ft_strdup(char *s);
char	*check_input_and_init_line(int fd);
void	ft_bzero(void *s, size_t n);
size_t	ft_strlen_line(char *s);
void	ft_memcpy(char *dst, char *src);
char	*ft_strjoin(char *s1, char *s2);
int		ft_check_buff(char *buff, int choice);
char	*get_next_line(int fd);
void	*ft_read_error(char *buff, char *line);
char	*print_line(char *line, char *buff, int *check_buff, int fd);

#endif