/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setters.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echai <echai@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 10:30:15 by echai             #+#    #+#             */
/*   Updated: 2021/04/11 11:23:34 by echai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

int     get_no_space_len(char *str)
{
	int		index;
	int		len;

	len = 0;
	index = 0;
	while (str[index] && is_space(str[index]))
		index++;
	while (str[index])
	{
		while (str[index] && !is_space(str[index]))
		{
			index++;
			len++;
		}
		if (is_space(str[index]))
		{
			len++;
			while (str[index] && is_space(str[index]))
				index++;
		}
	}
	return (len);
}

char    *remove_space(char *str)
{
	int		index;
	char	*final;
	int		len;
	int		offset;
	
	index = 0;
	offset = 0;
	len = get_no_space_len(str);
	final = malloc(sizeof(char) * len);
	while (str[index] && is_space(str[index]))
		index++;
	while (str[index])
	{
		while (str[index] && !is_space(str[index]))
			final[offset++] = str[index++];
		if (is_space(str[index]))
		{
			final[offset++] = ' ';
			while (str[index] && is_space(str[index]))
				index++;
		}
	}
	final[len] = '\0';
	return (final);
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
}