/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarx <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 18:33:27 by tmarx             #+#    #+#             */
/*   Updated: 2019/07/18 15:57:18 by tmarx            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H
# include <unistd.h>
# include <libgen.h>
# include <errno.h>
# include <strings.h>

void	ft_putstr(char *str);
void	ft_putnbr_base(int nbr, char *base);
char	*ft_strstr(char *str, char *to_find);
int		ft_get_hex_length(int nb);
int		ft_char_is_printable(char c);
char	ft_abs(char c);
int		is_buffer_empty(char buffer[16]);
void	handle_buffer(char buffer[16], int is_option_c, int max_n, int addr);
void	ft_print_address(int addr, int is_option_c);
void	ft_print_memory_block(char buffer[16], int is_option_c, int max_n);
void	ft_print_ascii(char buffer[16], int max_n);
void	ft(char buffer[16], int is_option_c, int data[3]);
void	ft_read_stdin(int is_option_c);
void	copy_buffer(char dest[16], char src[16]);
int		buffer_cmp(char b1[16], char b2[16]);
#endif
