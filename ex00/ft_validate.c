/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echai <echai@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 10:27:54 by echai             #+#    #+#             */
/*   Updated: 2021/04/11 20:32:21 by echai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		validate_inputs(char *str)
{
	int	index;

	index = 0;
	while (str[index])
		if (!is_num(str[index++]))
			return (0);
	return (1);
}

void	print_error(void)
{
	ft_putstr("\033[0;31mError\033[0m\n");
}

void	print_dict_error(void)
{
	ft_putstr("\033[0;31mDict Error\033[0m\n");
}
