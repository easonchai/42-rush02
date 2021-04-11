/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echai <echai@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 15:50:10 by echai             #+#    #+#             */
/*   Updated: 2021/04/11 18:39:06 by echai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "libft.h"

int		main(int argc, char *argv[])
{
	t_data	*list;
	t_data	*new_list;

	new_list = NULL;
	list = get_arr("numbers.dict");
	if (!list)
	{
		print_dict_error();
		return (1);
	}
	if (argc > 3 || argc < 2)
	{
		ft_putstr("\033[0;31mError, invalid number of arguments!\033[0m\n");
		return (1);
	}
	if (argc == 2)
		magic(list, argv[1]);
	else
	{
		new_list = get_arr(argv[1]);
		magic(new_list, argv[2]);
		free_list(new_list);
	}
	free_list(list);
	return (0);
}
