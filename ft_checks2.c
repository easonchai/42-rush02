/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checks2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echai <echai@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 09:36:43 by echai             #+#    #+#             */
/*   Updated: 2021/04/11 14:51:24 by hyun-zhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
