/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jajoo <jajoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 17:01:26 by jajoo             #+#    #+#             */
/*   Updated: 2021/09/26 17:05:49 by jajoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

void	ft_print_value(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	write(1, str, len);
}

int	ft_is_whitespace(char c)
{
	if (c == ' ' | c == '\n' | c == '\t' | c == '\r' | c == '\v' | c == '\f')
		return (1);
	else
		return (0);
}

int	ft_is_operator(char c)
{
	if (c == '+' | c == '-')
		return (1);
	else
		return (0);
}

int	ft_is_number(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}
