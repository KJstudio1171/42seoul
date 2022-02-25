#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

char	*get_next_line(int fd);

int main()
{
	int fd = open("test.txt", O_RDONLY);
	int i = 1;
	char * line;
	while(i < 8)
	{
		line = get_next_line(fd);
		i++;
		printf("%s", line);
	}
	close(fd);
}