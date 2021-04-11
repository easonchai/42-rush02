/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echai <echai@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 15:50:10 by echai             #+#    #+#             */
/*   Updated: 2021/04/11 15:00:06 by echai            ###   ########.fr       */
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

int		get_hundreds(t_data *list, char *str, int len)
{
	if (str[0] != '0')
		solve_ones(list, str, len);
	solve_hundreds(list, str, len);
	if (!is_zeros(str + 1))
		return (1);
	else
	{
		return (0);
	}
}

int		get_tens(t_data *list, char *str, int len)
{
	solve_tens(list, str, len);
	if (str[0] != '1' && !is_zeros(str + 1))
		return (1);
	else
		return (0);
}

void	print_text(t_data *list, char *str, int len)
{
	int		str_len;

	str_len = ft_strlen(str);
	if (str_len == 3)
		if (!get_hundreds(list, str, len))
			return ;
	if (str_len == 2)
		if (!get_tens(list, str, len))
			return ;
	if (str_len == 1)
	{
		solve_ones(list, str, len);
	}
	else
		print_text(list, str + 1, len - 1);
}

char	*print_place(t_data *list, int length)
{
	char *str;
	int i;

	if (length == 0)
		return ("");
	i = 1;
	str = malloc(sizeof(char) * (length + 2));
	str[0] = '1';
	while (i <= length)
	{
		str[i] = '0';
		i++;
	}
	str[length + 1] = 0;
	return(get_value(list, str));
	
}

int		main(int argc, char *argv[])
{
	t_data	*list;
	char	*head;
	int		length;
	int		trackpos;

	length = ft_strlen(argv[1]);
	list = get_arr("numbers.dict");
	head = get_head(argv[1]);
	trackpos = 0;
	if (argc > 3 || argc < 2)
	{
		ft_putstr("Error, invalid number of arguments!");
		return (1);
	}
	if (argc == 2)
	{
		if (!validate_inputs(argv[1]))
		{
			print_error();
			return (1);
		}
		if (length % 3 != 0)
		{
			print_text(list, head, length);
			head = get_head(argv[1] + (length % 3));
			trackpos += (length % 3);
			length -= (length % 3);
			ft_putstr(print_place(list, length));
			if (length != 0)
				ft_putstr(" ");
		}
		while (length != 0)
		{
			if (argv[1][trackpos] == '0' && argv[1][trackpos + 1] == '0' && argv[1][trackpos + 2] == '0')
			{
				trackpos += 3;
				length -= 3;
				head = get_head(argv[1] + trackpos);
			}
			else
			{
				print_text(list, head, length);
				trackpos += 3;
				length -= 3;
				head = get_head(argv[1] + trackpos);
				ft_putstr(print_place(list, length));
				if (length != 0)
					ft_putstr(" ");
			}
		}
		ft_putstr("\n");
	}
	else
	{
		// Get new one
	}
}
