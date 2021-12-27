/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junekim <junekim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 15:38:09 by junekim           #+#    #+#             */
/*   Updated: 2021/09/23 13:07:33 by junekim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	putstr_non_printable(unsigned char *str, int num)
{
	int		i;

	i = 0;
	while (str[i] && i < num)
	{
		if (str[i] >= 32 && str[i] <= 126)
			write(1, &str[i], 1);
		else
		{
			write(1, ".", 1);
		}
		i++;
	}
}

void	putstr_hex(unsigned char *str, int num, char *hex)
{
	int		i;
	int		two;

	i = 0;
	two = 0;
	while (str[i] && i < num)
	{
		write(1, &hex[str[i] / 16], 1);
		write(1, &hex[str[i] % 16], 1);
		if (++two == 2)
		{
			write(1, " ", 1);
			two = 0;
		}
		i++;
	}
	while (i++ < 16)
	{
		write(1, "  ", 2);
		if (++two == 2)
		{
			write(1, " ", 1);
			two = 0;
		}
	}
}

void	print_addr(long long ptr, char *hex)
{
	char		addr[16];
	int			i;
	int			j;
	long long	count;

	count = ptr;
	i = 0;
	j = 15;
	while (i < 16)
	{
		addr[i] = '0';
		i++;
	}
	while (ptr > 16)
	{
		addr[j] = hex[ptr % 16];
		ptr /= 16;
		j--;
	}
	addr[j] = hex[ptr];
	write(1, addr, 16);
	write(1, ": ", 2);
}

void	ft_print(unsigned char *addr, int num)
{
	char	*hex;

	hex = "0123456789abcdef";
	print_addr((long long)addr, hex);
	putstr_hex(addr, num, hex);
	putstr_non_printable(addr, num);
	write(1, "\n", 1);
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	i;
	unsigned int	count;
	unsigned char	*ptr;

	i = 0;
	count = 0;
	ptr = (unsigned char *)addr;
	if (size <= 0)
		return (addr);
	while (ptr[i] && size > i)
	{
		if (count == 15)
		{
			ft_print(&ptr[i - count], 16);
		}
		i++;
		if (count++ == 15)
			count = 0;
	}
	ft_print(&ptr[i - count], count);
	return (addr);
}
