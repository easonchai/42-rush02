/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_magic.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echai <echai@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 18:03:54 by wng               #+#    #+#             */
/*   Updated: 2021/04/11 19:29:35 by echai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "libft.h"

char		*magic3(t_data *list, int pos_len[2], char *input, char *head)
{
	if (input[pos_len[0] - 3] == '0' && input[pos_len[0] - 2] == '0'
			&& input[pos_len[0] - 1] == '0')
		head = get_head(input + pos_len[0]);
	else
	{
		print_text(list, head, pos_len[1] + 3);
		head = get_head(input + pos_len[0]);
		ft_putstr(print_place(list, pos_len[1]));
		if (pos_len[1] != 0)
			ft_putstr(" ");
	}
	return (head);
}

void		magic2(t_data *list, int pos_len[2], char *input, char *head)
{
	if (pos_len[1] % 3 != 0)
	{
		print_text(list, head, pos_len[1]);
		head = get_head(input + (pos_len[1] % 3));
		pos_len[0] += (pos_len[1] % 3);
		pos_len[1] -= (pos_len[1] % 3);
		ft_putstr(print_place(list, pos_len[1]));
		free(head);
		if (pos_len[1] != 0)
			ft_putstr(" ");
	}
	while (pos_len[1] != 0)
	{
		pos_len[0] += 3;
		pos_len[1] -= 3;
		head = magic3(list, pos_len, input, head);
		free(head);
	}
}

int			magic(t_data *list, char *nbr)
{
	int		pos_len[2];
	char	*input;
	char	*head;

	if (!validate_inputs(nbr))
	{
		print_error();
		return (1);
	}
	input = ft_strclean(nbr);
	pos_len[1] = ft_strlen(input);
	pos_len[0] = 0;
	head = get_head(input);
	if (pos_len[1] >= 40)
	{
		print_dict_error();
		return (1);
	}
	magic2(list, pos_len, input, head);
	ft_putstr("\n");
	free(input);
	free(head);
	return (1);
}
