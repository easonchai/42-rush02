/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echai <echai@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 10:20:43 by echai             #+#    #+#             */
/*   Updated: 2021/04/10 18:49:11 by wng              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int		ft_atoi(char *str)
{
	int	multiplier;
	int	value;
	int	i;

	value = 0;
	i = 0;
	multiplier = 1;
	while (is_space(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			multiplier = -1;
		i++;
	}
	while (str[i] >= '0' || str[i] <= '9')
		value = value * 10 + (str[i++] - '0');
	return (value * multiplier);
}

int		ft_strlen(char *str)
{
	int count;

	count = 0;
	while (str[count])
		count++;
	return (count);
}

char	*ft_strncpy(char *dest, char *src, int len)
{
	int index;

	index = 0;
	while (src[index] && index < len)
	{
		dest[index] = src[index];
		index++;
	}
	dest[index] = '\0';
	return (dest);
}

int		ft_strcmp(char *s1, char *s2)
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
	while (str[len] && str[len] != ':' && !is_space(str[len]))
		len++;
	key = malloc(sizeof(char) * (len + 1));
	ft_strncpy(key, str, len);
	while (is_space(str[len]) || str[len] == ':')
		len++;
	j = 0;
	while (is_printable(str[len + j]))
		j++;
	value = malloc(sizeof(char) * (len + 1));
	ft_strncpy(value, str + len, j);
	data.key = key;
	data.value = value;
	return (data);
}
