/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getters.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echai <echai@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 19:11:55 by echai             #+#    #+#             */
/*   Updated: 2021/04/11 09:44:36 by echai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

int		get_num_len(int nbr)
{
	int		len;

	len = 0;
	while (nbr > 0)
	{
		nbr = nbr / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int nbr)
{
	char	*str;
	long	n;
	int		i;

	n = nbr;
	i = get_num_len(n);
	if (!(str = (char*)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	str[i--] = '\0';
	while (n > 0)
	{
		str[i] = '0' + (n % 10);
		n = n / 10;
		i--;
	}
	return (str);
}

char	*get_value(t_data *list, char *key)
{
	int index;

	index = 0;
	while (list[index].key)
	{
		if (ft_match(list[index].key, key))
			return (list[index].value);
		index++;
	}
	return (0);
}

char	*get_value_by_int(t_data *list, int key)
{
	char	*alpha_key;

	alpha_key = ft_itoa(key);
	return (get_value(list, alpha_key));
}
