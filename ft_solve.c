/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echai <echai@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 09:34:37 by echai             #+#    #+#             */
/*   Updated: 2021/04/11 09:42:49 by echai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	solve_hundreds(t_data *list, char *str)
{
	int		len;
	char	*temp;
	int		index;
	char	*ans;

	index = 1;
	len = ft_strlen(str);
	temp = malloc(sizeof(char) * (len + 2));
	temp[len + 1] = '\0';
	temp[0] = '1';
	while (index < len)
		temp[index++] = '0';
	ans = get_value(list, temp);
	ft_putstr(ans);
}

void	solve_tens(t_data *list, char *str)
{
	char	*ans;
	int		temp;

	if (str[0] != '0')
	{
		ans = get_value(list, str);
		if (ans == NULL)
		{
			temp = (str[0] - '0') * 10;
			ans = get_value_by_int(list, temp);
		}
		ft_putstr(ans);
	}
	else
		ft_putstr("and");
}

void	solve_ones(t_data *list, char *str)
{
	char	*ans;
	char	*temp;

	temp = malloc(sizeof(char) * 2);
	temp[0] = str[0];
	temp[1] = '\0';
	ans = get_value(list, temp);
	ft_putstr(ans);
}
