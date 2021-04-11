/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echai <echai@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 09:42:16 by echai             #+#    #+#             */
/*   Updated: 2021/04/11 20:04:12 by echai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "libft.h"

int		get_file_length(char *path, int line)
{
	int		file;
	int		len;
	int		last;
	char	buf;

	file = open(path, O_RDONLY);
	len = 0;
	last = 0;
	while (read(file, &buf, 1))
	{
		if (!line)
			len++;
		else if (buf == '\n')
		{
			len++;
			last = 1;
		}
		else
			last = 0;
	}
	if (line && !last)
		len++;
	close(file);
	return (len);
}

char	*read_input(char *path, int len)
{
	int		file;
	char	*file_buf;

	file = open(path, O_RDONLY);
	file_buf = malloc(len + 1);
	read(file, file_buf, len);
	close(file);
	file_buf[len] = 0;
	return (file_buf);
}

char	*get_line(char *str, char end, int pos, int len)
{
	int		i;
	char	*line;

	i = 0;
	line = malloc(len);
	while (str[pos] != end)
	{
		line[i++] = str[pos++];
	}
	line[i] = '\0';
	return (line);
}

t_data	*split_lines(char *str, int str_len, int size)
{
	t_data	*t_data_arr;
	char	*line;
	int		len;
	int		i;
	int		s;

	i = -1;
	s = 0;
	t_data_arr = malloc((size + 1) * sizeof(t_data));
	while (++i <= str_len)
	{
		if (str[i] == '\n' || str[i] == '\0')
		{
			line = get_line(str, str[i], i - len, len + 1);
			t_data_arr[s++] = get_data(line);
			free(line);
			len = -1;
		}
		len++;
	}
	t_data_arr[s - 1].key = NULL;
	return (t_data_arr);
}

t_data	*get_arr(char *path)
{
	int		len;
	int		size;
	char	*file_str;
	t_data	*t_data_arr;

	len = get_file_length(path, 0);
	size = get_file_length(path, 1);
	file_str = read_input(path, len);
	t_data_arr = split_lines(file_str, len, size);
	free(file_str);
	return (t_data_arr);
}
