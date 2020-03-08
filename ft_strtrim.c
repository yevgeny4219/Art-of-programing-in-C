/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yepeliuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 21:19:35 by yepeliuk          #+#    #+#             */
/*   Updated: 2020/03/07 21:13:32 by yepeliuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_isprint_mod(int c)
{
	if (c > 32 && c < 127)
		return (1);
	return (0);
}

static int				ft_obstr(char const *s)
{
	int i;
	int index;

	i = 0;
	index = 0;
	while (s[i] != '\0')
	{
		if (ft_isprint_mod(s[i]) == 1)
			index = i;
		i++;
	}
	return (index);
}

static int				ft_size(char const *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
	{
		if (ft_isprint_mod(s[i]) == 1)
			break ;
		i++;
	}
	return (i);
}

char			*ft_strtrim(char const *s)
{
	int		i;
	int		size;
	int		count;
	char	*ptr;

	size = (ft_obstr(s) - ft_size(s)) + 2;
	if (size <= 0)
		size = 1;
	ptr = (char *)malloc(size * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	i = ft_size(s);
	count = 0;
	if (size > 1)
	{
		size = (size + i) - 1;
		while (i < size)
		{
			ptr[count] = s[i];
			count++;
			i++;
		}
	}
	ptr[count] = '\0';
	return (ptr);
}
