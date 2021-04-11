/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echai <echai@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 15:13:29 by echai             #+#    #+#             */
/*   Updated: 2021/04/11 18:33:42 by echai            ###   ########.fr       */
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
char			*get_value(t_data *list, char *key);
void			ft_putstr(char *str);
char			*get_value_by_int(t_data *list, int key);
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
int				valid_dict(t_data *list2, t_data *list);
void			print_dict_error(void);
void			free_list(t_data *list);
int				magic(t_data *list, char *nbr);
void			magic2(t_data *list, int pos_len[2], char *input, char *head);
char			*magic3(t_data *list, int pos_len[2], char *input, char *head);
char			*get_head(char *str);
int				get_hundreds(t_data *list, char *str, int len);
int				get_tens(t_data *list, char *str, int len);
void			print_text(t_data *list, char *str, int len);
char			*print_place(t_data *list, int length);

#endif
