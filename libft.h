/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echai <echai@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 15:13:29 by echai             #+#    #+#             */
/*   Updated: 2021/04/11 14:56:41 by echai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

typedef	struct	s_data
{
	char	*key;
	char	*value;
}				t_data;

int				ft_strlen(char *str);
char			*ft_strncpy(char *dest, char *src, int len);
char			**ft_split(char *str, char delim);
t_data			get_data(char *str);
int				ft_match(char *s1, char *s2);
int				is_space(char c);
int				is_alpha(char c);
int				is_num(char c);
int				is_alphanum(char c);
int				is_printable(char c);
t_data			*get_arr(char *filename);
char		    *get_value(t_data *list, char *key);
void			ft_putstr(char *str);
char		    *get_value_by_int(t_data *list, int key);
void			solve_hundreds(t_data *list, char *str, int len);
void			solve_tens(t_data *list, char *str, int len);
void			solve_ones(t_data *list, char *str, int len);
int				is_zeros(char *str);
void			set_value(t_data *list, char *key, char *value);
int				validate_inputs(char *str);
void			print_error(void);
char			*remove_space(char *str);
int				only_colon(char *str);
char			*ft_strclean(char *str);

#endif
