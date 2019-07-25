/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarx <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 09:27:31 by tmarx             #+#    #+#             */
/*   Updated: 2019/07/04 11:40:06 by tmarx            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_char_is_alphnum(char c)
{
	if (c >= 65 && c <= 90)
		return (1);
	if (c >= 97 && c <= 122)
		return (2);
	if (c >= 48 && c <= 57)
		return (3);
	return (0);
}

void	ft_char_upper(char *c)
{
	if (ft_char_is_alphnum(*c) == 2)
		*c -= 32;
}

void	ft_char_lower(char *c)
{
	if (ft_char_is_alphnum(*c) == 1)
		*c += 32;
}

char	*ft_strcapitalize(char *str)
{
	char	b;
	int		type_b;
	int		type;
	int		i;

	ft_char_upper(str);
	i = 1;
	while (*(str + i))
	{
		b = *(str + i - 1);
		type_b = ft_char_is_alphnum(b);
		type = ft_char_is_alphnum(*(str + i));
		if (type_b == 0)
		{
			ft_char_upper(str + i);
		}
		else
		{
			ft_char_lower(str + i);
		}
		i++;
	}
	return (str);
}
