/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarx <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 22:33:50 by tmarx             #+#    #+#             */
/*   Updated: 2019/07/13 23:52:43 by tmarx            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		is_pattern(char c, char *pattern)
{
	int i;

	i = 0;
	while (pattern[i])
	{
		if (pattern[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int		is_pattern_at(char *src, char *pattern, int i)
{
	if (src[i - 1] && src[i + 1] &&
			!is_pattern(src[i + 1], pattern) && is_pattern(src[i], pattern))
		return (1);
	return (0);
}

int		count_splits(char *src, char *pattern)
{
	int i;
	int res;

	i = 0;
	res = 0;
	while (is_pattern(src[i], pattern))
		i++;
	if (!src[i])
		return (0);
	while (src[i])
	{
		if (is_pattern_at(src, pattern, i++))
			res++;
	}
	return (res + 1);
}

int		len(char *str, char *charset, int j)
{
	int x;

	x = 0;
	while (!is_pattern_at(str, charset, j + x) && str[j + x])
		x++;
	return (x);
}

char	**ft_split(char *str, char *charset)
{
	int		i;
	int		j;
	int		k;
	char	**res;

	res = malloc(sizeof(char*) * (count_splits(str, charset) + 1));
	i = 0;
	j = 0;
	while (i < count_splits(str, charset))
	{
		k = 0;
		while (is_pattern(str[j], charset))
			j++;
		res[i] = malloc(sizeof(char) * (len(str, charset, j) + 1));
		while (!is_pattern_at(str, charset, j) && str[j])
		{
			if (!is_pattern(str[j], charset))
				res[i][k++] = str[j];
			j++;
		}
		j += 1;
		res[i++][k] = '\0';
	}
	res[i] = 0;
	return (res);
}
