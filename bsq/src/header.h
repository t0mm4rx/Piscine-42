/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoldman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 11:32:16 by vgoldman          #+#    #+#             */
/*   Updated: 2019/07/24 22:38:06 by tmarx            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H
# include <stdlib.h>
# include <fcntl.h>
# include <errno.h>
# include <unistd.h>
# define FIRST_LINE_BUFFER 200
# define PRINT_LINE_NB 10
# define X_BUFFER 50000

typedef struct	s_map
{
	int		x;
	int		y;
	int		**grid;
	int		**grid_copy;
	char	empty;
	char	obst;
	char	full;
}				t_map;
int				ft_atoi(char *str);
t_map			*map_parse(char *file);
void			create_grid(int x, int y, int ***grid, int is_aux);
int				check_lines(char *file, t_map *map);
int				min(int a, int b, int c);
void			compute_auxiliary(t_map *map);
void			biggest_square(t_map *map, int *top_i, int *left_i, int *size);
void			fill_grid_square(int ***grid, int x, int y, int size);
int				parse_grid(int fd, t_map *map);
t_map			*map_parse_stdin(void);
void			free_grid(t_map *map);
void			process_map(t_map *map);
void			handle_map(t_map *map);
void			ft_putstr(int channel, char *str);
#endif
