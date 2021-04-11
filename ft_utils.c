/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echai <echai@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 10:20:43 by echai             #+#    #+#             */
/*   Updated: 2021/04/11 17:09:01 by echai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

char	*ft_strclean(char *str)
{
	int		i;
	int		j;
	char	*clean_str;

	i = 0;
	j = 0;
	clean_str = malloc((ft_strlen(str) + 1) * sizeof(char));
	while (is_space(str[i]))
		i++;
	while (str[i] >= '0' && str[i] <= '9')
		clean_str[j++] = str[i++];
	return (clean_str);
}

int		ft_strlen(char *str)
{
	int count;

	count = 0;
	while (str[count] && str[count] != '\n')
		count++;
	return (count);
}

char	*ft_strncpy(char *dest, char *src, int len)
{
	int index;

	index = 0;
	while (src[index] && index < len && src[index])
	{
		dest[index] = src[index];
		index++;
	}
	dest[index] = '\0';
	return (dest);
}

int		ft_match(char *s1, char *s2)
{
	int index;

	index = 0;
	while (s1[index] || s2[index])
	{
		if (s1[index] != s2[index])
			return (0);
		index++;
	}
	return (1);
}

t_data	get_data(char *str)
{
	int		len;
	char	*key;
	char	*value;
	int		j;
	t_data	data;

	len = 0;
	str = remove_space(str);
	while (str[len] && str[len] != ':' && !is_space(str[len]))
		len++;
	key = malloc(sizeof(char) * (len + 1));
	ft_strncpy(key, str, len);
	while (str[len] && (is_space(str[len]) || str[len] == ':'))
		len++;
	j = 0;
	while (is_printable(str[len + j]) && str[len + j] != '\n' &&
	j < ft_strlen(str) - len)
		j++;
	value = malloc(sizeof(char) * (len + 1));
	ft_strncpy(value, str + len, j);
	data.key = key;
	data.value = value;
	return (data);
}
