/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echai <echai@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 15:50:10 by echai             #+#    #+#             */
/*   Updated: 2021/04/11 09:40:19 by echai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

char	*get_head(char *str)
{
	int		len;
	int		until;
	char	*head;
	int		index;

	index = 0;
	len = ft_strlen(str);
	if (len <= 3)
		until = 0;
	else if (len > 3 && (len - 1) % 3 == 2)
		until = ((len - 1) / 3) * 3;
	else
		until = (len / 3) * 3;
	head = malloc(sizeof(char) * 4);
	while (index < len - until)
	{
		head[index] = str[index];
		index++;
	}
	head[index] = '\0';
	return (head);
}

int		get_hundreds(t_data *list, char *str)
{
	solve_ones(list, str);
	ft_putstr(" ");
	solve_hundreds(list, str);
	if (!is_zeros(str + 1))
		ft_putstr(" ");
	else
	{
		ft_putstr("\n");
		return (0);
	}
	return (1);
}

int		get_tens(t_data *list, char *str)
{
	solve_tens(list, str);
	if (str[0] != '1' && !is_zeros(str + 1))
		ft_putstr(" ");
	else
	{
		ft_putstr("\n");
		return (0);
	}
	return (1);
}

void	print_text(t_data *list, char *str)
{
	int		len;

	len = ft_strlen(str);
	if (len == 3)
		if (!get_hundreds(list, str))
			return ;
	if (len == 2)
		if (!get_tens(list, str))
			return ;
	if (len == 1)
	{
		solve_ones(list, str);
		ft_putstr("\n");
	}
	else
		print_text(list, str + 1);
}

int		main(int argc, char *argv[])
{
	t_data	*list;
	char	*head;

	list = get_arr();
	head = get_head(argv[1]);
	if (argc == 2)
	{
		print_text(list, head);
	}
}
