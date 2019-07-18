/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stdin.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarx <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 23:02:14 by tmarx             #+#    #+#             */
/*   Updated: 2019/07/18 21:43:37 by tmarx            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_display_stdin(int char_count)
{
	int		n;
	char	buffer2[1];
	char	buffer[900000];
	int		i;
	int		j;

	i = 0;
	j = 0;
	while ((n = read(0, buffer2, 1)) > 0)
		buffer[j++] = buffer2[0];
	while (i < j)
	{
		if (i >= j - char_count)
			write(1, &buffer[i], 1);
		i++;
	}
}
