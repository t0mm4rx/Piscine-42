/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stdin.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarx <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 23:02:14 by tmarx             #+#    #+#             */
/*   Updated: 2019/07/17 23:41:41 by tmarx            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_display_stdin(int char_count)
{
	int		n;
	char	buffer[32000];
	int		i;

	i = 0;
	n = read(0, buffer, 32000);
	while (i < n)
	{
		if (i >= n - char_count)
			write(1, &buffer[i], 1);
		i++;
	}
}
