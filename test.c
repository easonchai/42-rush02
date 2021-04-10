/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echai <echai@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 16:45:48 by echai             #+#    #+#             */
/*   Updated: 2021/04/10 18:19:46 by echai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char *argv[])
{
	t_data *list;

	list = malloc(sizeof(t_data) * 42);
	list[41].key = NULL;

	list[0].key = "0";
	list[1].key = "1";
	list[2].key = "2";
	list[3].key = "3";
	list[4].key = "4";
	list[5].key = "5";
	list[6].key = "6";
	list[7].key = "7";
	list[8].key = "8";
	list[9].key = "9";
	list[10].key = "10";
	list[11].key = "11";
	list[12].key = "12";
	list[13].key = "13";
	list[14].key = "14";
	list[15].key = "15";
	list[16].key = "16";
	list[17].key = "17";
	list[18].key = "18";
	list[19].key = "19";
	list[20].key = "20";
	list[21].key = "30";
	list[22].key = "40";
	list[23].key = "50";
	list[24].key = "60";
	list[25].key = "70";
	list[26].key = "80";
	list[27].key = "90";
	list[28].key = "100";
	list[29].key = "1000";
	list[30].key = "1000000";
	list[31].key = "1000000000";
	list[32].key = "1000000000000";
	list[33].key = "1000000000000000";
	list[34].key = "1000000000000000000";
	list[35].key = "1000000000000000000000";
	list[36].key = "1000000000000000000000000";
	list[37].key = "1000000000000000000000000000";
	list[38].key = "1000000000000000000000000000000";
	list[39].key = "1000000000000000000000000000000000";
	list[40].key = "1000000000000000000000000000000000000";

	if (argc == 2)
	{
		printf("%s\n", argv[1]);
	}
}

char	*get_pv(t_data *list, char *str)
{
	(void)list;
	return (str);
}

char	*get_head(char *str)
{

}
