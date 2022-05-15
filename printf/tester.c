#include <unistd.h>
#include <stdio.h>

#include "ft_printf.h"


int main()
{
	printf("%p %p\n", (void *)-214748365, (void *)214748364);
	ft_printf("%p %p", (void *)-214748365, (void *)214748364);
}