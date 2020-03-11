/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yepeliuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 21:19:35 by yepeliuk          #+#    #+#             */
/*   Updated: 2020/02/22 22:41:42 by yepeliuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

int		ft_isprint_mod(int c)
{
	if (c > 32 && c < 127)
		return (1);
	return (0);
}

int     ft_len(char *s)
{
  int i;
  int  space;

  i = 0;
  space = 0;
  while (*s != '\0')
  {
    if (ft_isprint_mod(*s) == 1)
      i++;
      s++;
  }
  return (i);
}

int			ft_count_words(char *s)
{
	int i;
	int j;
	int count;

	i = 0;
	j = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (ft_isprint_mod(s[i]) == 0)
        j++;
		else if ((ft_isprint_mod(s[i]) == 1) && (j > 0))
		{
			count++;
			j = 0;
		}
		i++;
  }
	return (count);
}

char        *ft_strtrim(char *s)
{
    int     size;
    int     count;
    char    *ptr;
    int j;

    count = 0;
    j = 0;
    size = ft_len(s) + (ft_count_words(s) * 2);
    ptr = (char *)malloc(size * sizeof(char));
    if (ptr == NULL)
        return (NULL);
    while (*s != '\0')
    {
      if (ft_isprint_mod(*s) == 1)
          {
            *ptr = *s;
            count++;
          }
      else if (ft_isprint_mod(*s) == 0 && (count > 0))
        {
          *ptr = ' ';
          count = 0;
        }
        ptr++;
        s++;
    }
    *ptr = '\0';
    return (ptr);
}
