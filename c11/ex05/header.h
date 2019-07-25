/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarx <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 12:42:05 by tmarx             #+#    #+#             */
/*   Updated: 2019/07/17 14:55:04 by tmarx            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H
# include <unistd.h>

int		ft_atoi(char *str);
void	ft_putnbr(int a);
void	process(int a, int b, void (*f)(int, int));
void	add(int a, int b);
void	mult(int a, int b);
void	div(int a, int b);
void	mod(int a, int b);
#endif
