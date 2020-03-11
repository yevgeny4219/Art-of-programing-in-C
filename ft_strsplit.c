/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yepeliuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 23:07:03 by yepeliuk          #+#    #+#             */
/*   Updated: 2020/02/24 16:33:51 by yepeliuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>


static int            ft_words(char const *str, char c)
{
    int i;
    int j;
    int count;

    i = 0;
    j = 0;
    count = 0;
    while (str[i] != '\0')
    {
      if (str[i] != c)
          j++;
      else if (str[i] == c && j > 0)
        {
          count++;
          j = 0;
        }
        i++;
    }
    if (j > 0)
        count++;
    return (count);
}

static int			*ft_letter(char const *str, char c)
{
	int j;
	int *arr;
	int size;
    int index;

    index = 0;
	size = ft_words(str, c) + 1;
	arr = (int *)malloc(size * sizeof(int));
	if (arr == NULL)
		return (NULL);
	j = 0;
	while (*str != '\0')
	{
		if (*str != c)
			j++;
		else if (*str == c && j > 0)
		{
			arr[index] = j + 1;
			index++;
			j = 0;
		}
		str++;
	}
    arr[index] = j + 1;
	arr[index + 1] = 1;
	return (arr);
}

static char        **ft_fill(char **ptr, char const *s, char c)
{
	int i;
	int j;

	i = 0;
	while (*s != '\0')
	{
		if (*s != c)
		{
			j = 0;
			while (*s != c && *s != '\0')
			{
				ptr[i][j] = *s;
				j++;
				s++;
			}
			ptr[i][j] = '\0';
			i++;
		}
		s++;
	}
	ptr[i][0] = '\0';
	return (ptr);
}

char		**ft_strsplit(char const *str, char c)
{
	int		i;
	int		row;
	int		index;
	int		*arr;
	char	**ptr;

	i = 0;
	index = 0;
	arr = ft_letter(str, c);
	row = ft_words(str, c) + 1;
	ptr = (char **)malloc((row) * sizeof(char *));
	if (ptr == NULL)
		return (NULL);
	while (i < row) 
	{
		ptr[i] = (char *)malloc((arr[index]) * sizeof(char));
		if (ptr[i] == NULL)
			return (NULL);
		index++;
		i++;
	}
	ptr = ft_fill(ptr, str, c);
	free(arr);
	return (ptr);
}

/*int		main()
{
    char *s;
   	char **res;
    int i;
    int j;
    int *arr;


    i = 0;
    s = "                olol";
    j = ft_words(s, ' ' );
    res = ft_strsplit(s, ' ');
    arr = ft_letter(s, ' ');

	//printf("%i", j);
	while (i <= j)
	{
		printf("%s\n", res[i]);
		i++;
	}
	return (0);
}*/