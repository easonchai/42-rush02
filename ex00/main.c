/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echai <echai@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 15:50:10 by echai             #+#    #+#             */
/*   Updated: 2021/04/11 20:14:43 by echai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "libft.h"

int		valid_action(char *filename, char *nbr, t_data *ori)
{
	t_data	*new_list;

	new_list = get_arr(filename);
	if (!valid_dict(new_list, ori))
	{
		free_list(new_list);
		print_dict_error();
		return (0);
	}
	magic(new_list, nbr);
	free_list(new_list);
	return (1);
}

int		main(int argc, char *argv[])
{
	t_data	*list;

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
		valid_action(argv[1], argv[2], list);
	free_list(list);
	return (0);
}
