/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junekim <june1171@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 23:04:25 by junekim           #+#    #+#             */
/*   Updated: 2021/09/25 23:38:18 by junekim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main()
{
	char number[691];
	int fp = open("./numbers.dict", O_RDONLY);
	int len = 0;
	int i = -1;
	while(read(fp,number,691))
		len++;
	while(i < 692)
	printf("%d", number[690]);
	if(close(fp) == -1)
		printf("error");
}
