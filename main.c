#include "get_next_line.h"
#include "get_next_line_bonus.h"

// int main(void)
// {
// 	char *line;
// 	char *line1;
// 	char *line2;
// 	int fd;
// 	int fd1;
// 	int fd2;

// 	fd = open("test", O_RDONLY);
// 	fd1 = open("test1", O_RDONLY);
// 	fd2 = open("test2", O_RDONLY);
// 	while ((line = get_next_line(fd))) // avec double parenthese!
// 	{
// 		printf("%s", line);
// 		free(line);
// 		line1 = get_next_line(fd1);
// 		printf("%s", line1);
// 		free(line1);
// 		line2 = get_next_line(fd2);
// 		printf("%s", line2);
// 		free(line2);
// 	}
// 	close(fd);
// 	close(fd1);
// 	close(fd2);
// 	return (0);
// }

// int main(void)
// {
// 	char *line;
// 	int fd;

// 	fd = open("test", O_RDONLY);
// 	while ((line = get_next_line(fd))) // avec double parenthese!
// 	{
// 		printf("%s", line);
// 		free(line);
// 	}
// 	close(fd);
// 	return (0);
// }


int main ()
{
	int fd;
	int	i;
	char *line;

	fd = open("test1", O_RDONLY | O_CREAT); // remplacer "test" par av[1] par exemple
	if (fd == -1)
	{
		printf("open command failed\n");
		return (1);
	}

	printf("fd : [%d]\n", fd);
	i = 1;
	while (i < 5)
	{
		line = get_next_line(fd);
		printf("line%i : %s\n", i, line);
		free(line);
		i++;
	}

	if (close(fd) == -1) // en checkant si = -1, ça execute la commande "close"
	{
		printf("close command failed\n");
		return (1);
	}

	return 0;
}
