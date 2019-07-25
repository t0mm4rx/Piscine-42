/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarx <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 23:45:30 by tmarx             #+#    #+#             */
/*   Updated: 2019/07/16 12:15:45 by tmarx            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		ft_strlen2(char **strs, int size)
{
	int i;
	int res;

	i = 0;
	res = 0;
	if (size == 0)
		return (0);
	while (i < size)
	{
		res += ft_strlen(strs[i++]);
	}
	return (res);
}

char	*ft_strcat(char *dest, char *src)
{
	int i;

	i = 0;
	while (dest[i])
		i++;
	while (*src)
		dest[i++] = *src++;
	dest[i] = '\0';
	return (dest);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*res;
	int		len;
	int		i;

	if (size <= 0 || !sep || !strs)
	{
		res = malloc(sizeof(char));
		res[0] = '\0';
		return (res);
	}
	len = ft_strlen(sep) * (size - 1) + ft_strlen2(strs, size) + 1;
	res = malloc(sizeof(char) * len);
	if (!res)
		return (0);
	res[0] = 0;
	i = 0;
	while (i < size)
	{
		ft_strcat(res, strs[i++]);
		if (i < size)
			ft_strcat(res, sep);
	}
	res[len - 1] = '\0';
	return (res);
}
