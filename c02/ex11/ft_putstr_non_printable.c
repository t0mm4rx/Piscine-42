/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarx <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 12:15:20 by tmarx             #+#    #+#             */
/*   Updated: 2019/07/10 10:56:12 by tmarx            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_char_is_printable(char c)
{
	if (c >= 32 && c < 127)
		return (1);
	return (0);
}

void	ft_hex(char c, char *res)
{
	char	*charset;

	charset = "0123456789abcdef";
	res[1] = charset[(unsigned char)c % 16];
	res[0] = charset[((unsigned char)c / 16)];
}

void	ft_putstr_non_printable(char *str)
{
	char hex[2];

	while (*str)
	{
		if (ft_char_is_printable(*str))
		{
			write(1, str, 1);
		}
		else
		{
			write(1, "\\", 1);
			ft_hex(*str, hex);
			write(1, hex, 2);
		}
		str++;
	}
}
