/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tail.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarx <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 07:56:22 by tmarx             #+#    #+#             */
/*   Updated: 2019/07/19 08:02:10 by tmarx            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TAIL_H
# define TAIL_H
# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include <errno.h>
# include <libgen.h>
# include <stdlib.h>
# include <stdio.h>

int		ft_strlen(char *str);
int		ft_is_numeric(char c);
int		ft_atoi(char *str, int j);
void	ft_puterror(char *str);
void	ft_putstr(char *str);
int		ft_error(int fd, char **argv, int i);
void	ft_banner(char **argv, int argc, int i);
void	ft_putfinal(int i, int argc);
char	*ft_write(char **argv, int argc, int option);
int		ft_count(char **argv, int i);
int		ft_init(char **argv);
void	ft_disp_stdin(void);
int		ft_flag(int flag, char **argv, int argc, int i);
void	ft_illegal_offset(char **argv);
char	*get_stdin(int option);
char	*stdin_memory(int size, char *res, char buffer);
char	*ft_res(char *membuff, int option, int size);
char	*ft_output(char *str, int option);
void	ft_display(int c_f[2], char *str, int fd);

#endif
