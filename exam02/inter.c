/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junekim <june1171@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 23:14:54 by junekim           #+#    #+#             */
/*   Updated: 2022/08/25 00:05:04 by junekim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char** argv)
{
	int arg[255] = {0};
	int j = 0;

	if (argc != 3)
	{
		write(1, "\n", 1);
		return (0);
	}
	j = 0;
	while(argv[2][j])
	{
		arg[(unsigned char)argv[2][j]] = 1;
		j++;
	}
	j = 0;
	while(argv[1][j])
	{
		if (arg[(unsigned char)argv[1][j]] == 1)
		{
			arg[(unsigned char)argv[1][j]] = 2;
			write(1, &argv[1][j], 1);
		}
		j++;
	}
	write(1, "\n", 1);
}
