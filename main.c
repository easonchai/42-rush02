/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echai <echai@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 15:50:10 by echai             #+#    #+#             */
/*   Updated: 2021/04/10 23:02:20 by echai            ###   ########.fr       */
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

// void	get_multiple(t_data *list, char *str, int len)
// {
// 	char	*temp;
// 	int		index;

// 	index = 1;
// 	temp = malloc(sizeof(char) * (len + 1));
// 	temp[len] = '\0';
// 	ft_strncpy(temp, str, len);
// 	while (index < len)
// 		temp[index++] = '0';
// 	printf("%s ", get_value(list, temp));
// }

// void	get_first(t_data *list, char *head)
// {
// 	char	*first;
// 	char	*ans;
// 	int		index;

// 	index = 1;
// 	first = malloc(sizeof(char) * 4);
// 	first[index] = '\0';
// 	ft_strncpy(first, head, 1);
// 	ans = get_value(list, first);
// 	printf("%s ", ans);
// 	first[0] = '1';
// 	while (index < 3)
// 		first[index++] = '0';
// 	first[index] = '\0';
// 	ans = get_value(list, first);
// 	printf("%s ", ans);
// }

// void	get_back(t_data *list, char *head)
// {
// 	char	*ans;

// 	if (ft_strlen(head) == 2)
// 	{
// 		if (head[0] == '1')
// 		{
// 			ans = get_value(list, head);
// 			printf("%s ", ans);
// 		}
// 		else
// 		{
// 			get_multiple(list, head, 2);
// 			printf("%s ", get_value(list, head + 1));
// 		}
// 	}
// 	else
// 	{
// 		printf("lol\n");
// 	}
// }

// void	find_multiple(t_data *list, char *str, int len)
// {
// 	char	*temp;
// 	char	*ans;
// 	int		index;

// 	ans = get_value(list, str);
// 	index = 1;
// 	temp = malloc(sizeof(char) * len + 1);
// 	ft_strncpy(temp, str, len);
// 	while (index < len)
// 		temp[index++] = '0';
// 	ans = get_value(list, temp);
// 	if (ans == NULL)
// 	{
// 		temp[0] = '1';
// 		ans = get_value(list, temp);
// 	}
// 	ft_putstr(ans);
// }

// void	solve_ones(t_data *list, char *str)
// {
// 	char	*ans;
// 	char	*temp;

// 	temp = malloc(sizeof(char) * 2);
// 	temp[0] = str[0];
// 	temp[1] = '\0';
// 	ans = get_value(list, temp);
// 	ft_putstr(ans);
// }

// void	find_mid(t_data *list, char *str)
// {
// 	char	*ans;

// 	if (str[0] == '1')
// 	{
// 		ans = get_value(list, str);
// 		ft_putstr(ans);
// 	}
// 	else
// 	{
// 		find_multiple(list, str, 2);
// 		if (str[1] != '0')
// 		{
// 			ft_putstr(" ");
// 			solve_ones(list, str + 1);
// 		}
// 	}
// }

// void	solve_hundreths(t_data *list, char *str)
// {
// 	if (ft_strlen(str) == 3)
// 	{
// 		solve_ones(list, str);
// 		ft_putstr(" ");
// 		find_multiple(list, str, 3);
// 	}
// }

void	get_digit(t_data *list, char *str)
{
	char	*ans;
	char	*temp;

	temp = malloc(sizeof(char) * 2);
	temp[0] = str[0];
	temp[1] = '\0';
	ans = get_value(list, temp);
	ft_putstr(ans);
}

void	get_terms(t_data *list, char *str)
{
	int		len;
	char	*temp;
	int		index;
	char	*ans;

	index = 1;
	len = ft_strlen(str);
	temp = malloc(sizeof(char) * (len + 2));
	temp[len + 1] = '\0';
	temp[0] = '1';
	while (index < len + 1)
	{
		temp[index] = '0';
	}
	ans = get_value(list, temp);
	ft_putstr(ans);
}

void	solve_hundreths(t_data *list, char *str)
{
	get_digit(list, str);
	get_terms(list, str);
}

void	solve_tens(t_data *list, char *str)
{
	char	*ans;

	if (ft_strlen(str) == 2)
	{
		if (str[0] == '1')
		{
			ans = get_value(list, str);
			ft_putstr(ans);
		}
		else
		{
			find_multiple(list, str, 2);
			if (str[1] != '0')
			{
				ft_putstr(" ");
				solve_ones(list, str + 1);
			}
		}
	}
}

void	print_text(t_data *list, char *str)
{
	int		len;

	len = ft_strlen(str);
	solve_hundreths(list, str);
	solve_tens(list, str);
	// if ((len != 1 && str[len - 1] != '0' && str[len - 2] != '1') || len == 1 )
	// 	solve_ones(list, str);
	// ft_putstr("\n");
	get_digit(list, str);
	get_terms(list, str);
	if (len > 1)
		print_text(list, str + 1);
// 	int		len;

// 	len = ft_strlen(str);
// 	if (len == 2 && str[0] != '0')
// 		find_mid(list, str);
// 	else if (len == 1 && str[0] != '0')
// 		solve_ones(list, str);
// 	if (len == 3 && str[0] != '0')
// 	{
// 		solve_ones(list, (str + 3 - len));
// 		ft_putstr(" ");
// 		find_multiple(list, str, len);
// 		print_text(list, str + 1);
// 	}
// //	if (len != 1)
// //	{
// //		if (len == 2 && str[0] == '1')
// //			return ;
// //		print_text(list, str + 1);
// //	}
// 	if (len == 1)
// 		ft_putstr("\n");
}

int		main(int argc, char *argv[])
{
	t_data	*list;
	char	*head;

	list = get_arr();
	head = get_head(argv[1]);
	if (argc == 2)
	{
		//get_first(list, head);
		//get_back(list, head + 1);
		print_text(list, head);
	}
}
