/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echai <echai@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 15:20:01 by echai             #+#    #+#             */
/*   Updated: 2021/04/10 18:44:41 by wng              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		is_space(char c)
{
	if (c != ' ' && c != '\t' && c != '\r' && c != '\f' && c != '\v')
		return (0);
	return (1);
}

int		is_alpha(char c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	return (0);
}

int		is_num(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int		is_alphanum(char c)
{
	if (is_alpha(c) || is_num(c))
		return (1);
	return (0);
}

int		is_printable(char c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}
