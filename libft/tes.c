#include "libft.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	char** s = ft_split("!!!lorem!!!ipsum!dolor!!!!!sit!amet,!consectetur!!!adipiscing!elit.!Sed!non!risus.!Suspendisse!!!",'!');
	while(*s)
		printf("%s\n", *s++);
}