/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setters.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echai <echai@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 10:30:15 by echai             #+#    #+#             */
/*   Updated: 2021/04/11 17:10:42 by echai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int		get_no_space_len(char *str)
{
	int		index;
	int		len;

	len = 0;
	index = 0;
	while (str[index] && is_space(str[index]))
		index++;
	while (str[index])
	{
		while (str[index] && !is_space(str[index]) && str[index] != '\n')
		{
			index++;
			len++;
		}
		if (str[index] && is_space(str[index]))
		{
			len++;
			while (str[index] && is_space(str[index]) && str[index] != '\n')
				index++;
		}
	}
	return (len);
}

char	*remove_space(char *str)
{
	int		i;
	char	*final;
	int		len;
	int		offset;

	i = 0;
	offset = 0;
	len = get_no_space_len(str);
	final = malloc(sizeof(char) * len + 1);
	while (str[i] && is_space(str[i]))
		i++;
	while (str[i])
	{
		while (str[i] && !is_space(str[i]) && str[i] != '\n')
			final[offset++] = str[i++];
		if (str[i] && is_space(str[i]))
		{
			final[offset++] = ' ';
			while (str[i] && is_space(str[i]) &&
			str[i] != '\n')
				i++;
		}
	}
	final[len] = '\0';
	return (final);
}

void	write_file(t_data *list)
{
	int	file;
	int	index;
	int temp;

	index = 0;
	file = open("numbers.dict", O_WRONLY | O_CREAT | O_TRUNC, 644);
	while (list[index].key)
	{
		temp = ft_strlen(list[index].key);
		write(file, list[index].key, temp);
		write(file, ": ", 2);
		temp = ft_strlen(list[index].value);
		write(file, list[index].value, temp);
		write(file, "\n", 1);
		index++;
	}
}

void	set_value(t_data *list, char *key, char *value)
{
	char	*parsed_key;
	char	*parsed_value;
	int		index;

	index = 0;
	parsed_key = remove_space(key);
	parsed_value = remove_space(value);
	while (list[index].key)
	{
		if (ft_match(list[index].key, parsed_key))
			list[index].value = parsed_value;
		index++;
	}
	write_file(list);
}
