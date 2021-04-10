#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "libft.h"

int		get_file_length(char *str)
{
	int		file;
	int		len;
	char	*buf;

	file = open(str, O_RDONLY);
	len = 0;
	while (read(file, &buf, 1) != 0)
	{
		len++;
	}
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

char	*get_line(char *str, int pos, int len)
{
	int		i;
	char	*line;

	i = 0;
	line = malloc(len);
	while (str[pos] != '\n')
		line[i++] = str[pos++];
	return (line);
}

t_data	*split_lines(char *str, int size)
{
	t_data	*t_data_arr;
	char	*line;
	int		len;
	int		i;
	int		s;

	i = -1;
	s = 0;
	t_data_arr = malloc((size + 1) * sizeof(t_data));
	while (str[++i])
	{
		if (str[i] == '\n')
		{
			line = get_line(str, i - len, len + 1);
			t_data_arr[s++] = get_data(line);
			len = -1;
		}
		len++;
	}
	t_data_arr[s].key = 0;
	return (t_data_arr);
}

int		main(void)
{
	int		len;
	char	*file_str;
	t_data	*t_data_arr;

	len = get_file_length("numbers.dict");
	file_str = read_input("numbers.dict", len);
	t_data_arr = split_lines(file_str, len);
	while (t_data_arr->key)
	{
		printf("%s\n", t_data_arr->key);
		printf("%s\n", t_data_arr->value);
		t_data_arr++;
	}
}
