/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarx <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 18:33:27 by tmarx             #+#    #+#             */
/*   Updated: 2019/07/17 13:14:13 by tmarx            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H
# include <unistd.h>

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
#endif