/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echai <echai@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 15:50:10 by echai             #+#    #+#             */
/*   Updated: 2021/04/10 18:54:24 by echai            ###   ########.fr       */
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

int		main(int argc, char *argv[])
{
	t_data	data;
	char	*head;

	data = get_data("  20  :     twenty");
	printf("%s\n", data.key);
	printf("%s\n", data.value);
	head = get_head(argv[1]);
	if (argc == 2)
	{
		printf("Head: %s\n", head);
	}
}
