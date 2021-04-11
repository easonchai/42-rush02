/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echai <echai@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 17:45:12 by echai             #+#    #+#             */
/*   Updated: 2021/04/11 18:31:45 by echai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

void	free_list(t_data *list)
{
	int index;

	index = 0;
	while (list[index].key != NULL)
	{
		free(list[index].key);
		free(list[index].value);
		index++;
	}
	free(list[index].key);
	free(list[index].value);
	free(list);
}
