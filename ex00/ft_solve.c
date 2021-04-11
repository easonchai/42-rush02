/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echai <echai@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 09:34:37 by echai             #+#    #+#             */
/*   Updated: 2021/04/11 19:41:31 by echai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	solve_hundreds(t_data *list, char *str, int len)
{
	int		str_len;
	char	*temp;
	int		index;
	char	*ans;

	if (str[0] != '0')
	{
		index = 1;
		str_len = ft_strlen(str);
		temp = malloc(sizeof(char) * (str_len + 2));
		temp[str_len + 1] = '\0';
		temp[0] = '1';
		while (index < str_len)
			temp[index++] = '0';
		ans = get_value(list, temp);
		ft_putstr(ans);
		if (len != 1)
			ft_putstr(" ");
	}
}

void	solve_tens(t_data *list, char *str, int len)
{
	char	*ans;
	int		temp;

	if (str[0] != '0')
	{
		if (str[0] == '1')
			ans = get_value(list, str);
		else
		{
			temp = (str[0] - '0') * 10;
			ans = get_value_by_int(list, temp);
		}
		ft_putstr(ans);
		if (len != 2)
			ft_putstr(" ");
	}
	else
		ft_putstr("and ");
}

void	solve_ones(t_data *list, char *str, int len)
{
	char	*ans;
	char	*temp;

	temp = malloc(sizeof(char) * 2);
	temp[0] = str[0];
	temp[1] = '\0';
	str--;
	if (*str >= '1' && *str <= '9' && len == 1)
		ft_putstr(" ");
	ans = get_value(list, temp);
	ft_putstr(ans);
	if (len != 1)
		ft_putstr(" ");
}
