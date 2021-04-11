/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checks2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echai <echai@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 09:36:43 by echai             #+#    #+#             */
/*   Updated: 2021/04/11 19:57:40 by echai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int		is_zeros(char *str)
{
	int		index;

	index = 0;
	while (str[index])
		if (str[index++] != '0')
			return (0);
	return (1);
}

int		only_colon(char *str)
{
	int	i;
	int	colon;

	i = 0;
	colon = 0;
	while (str[i])
	{
		if (str[i++] == ':')
		{
			if (colon)
				return (0);
			colon = 1;
		}
	}
	return (1);
}

int		valid_dict(t_data *list2, t_data *list)
{
	int check;
	int i;
	int j;

	i = 0;
	while (list[i].key)
	{
		check = 0;
		j = 0;
		while (list2[j].key)
		{
			if (ft_match(list[i].key, list2[j].key))
				check = 1;
			j++;
		}
		if (check == 0)
			return (0);
		i++;
	}
	return (1);
}
