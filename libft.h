/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echai <echai@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 15:13:29 by echai             #+#    #+#             */
/*   Updated: 2021/04/10 16:49:56 by wng              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

typedef	struct	s_data
{
	char	*key;
	char	*value;
}				t_data;

int				ft_atoi(char *str);
int				ft_strlen(char *str);
char			*ft_strncpy(char *dest, char *src, int len);
int				ft_strcmp(char *s1, char *s2);
char			**ft_split(char *str, char delim);
t_data			get_data(char *str);
int				ft_strcmp(char *s1, char *s2);
char			*ft_strncpy(char *dest, char *src, int len);
int				ft_atoi(char *str);
int				ft_strlen(char *str);
int				is_space(char c);
int				is_alpha(char c);
int				is_num(char c);
int				is_alphanum(char c);
int				is_printable(char c);

#endif
