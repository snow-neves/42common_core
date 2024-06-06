#include "get_next_line.h"

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t	i;

	i = 0;
	while ((str2[i] != '\0' || str1[i] != '\0') && (i < n))
	{
		if (str1[i] != str2[i])
		{
			printf("%c", str1[i]);
			return ((unsigned char)str1[i] - (unsigned char)str2[i]);
		}
		i++;
	}
	return (0);
}


int	main(void)
{
	char	*p;
	int		fd;
	int		nr_of_lines;

	nr_of_lines = 1;

/* 	fd = open("testing.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("ERROR");
		return (1);
	}
	while ((p = get_next_line(fd)))
	{
		printf("line nr:%d\n%s", nr_of_lines, p);
		nr_of_lines++;
		free(p);
	}
	if (close(fd) == -1)
	{
		printf("Error closing file");
		return (1);
	} */

		fd = open("testing.txt", O_RDONLY);

		p = get_next_line(fd);
		//printf("line nr:%d\n%s", nr_of_lines, p);
		printf("%i", ft_strncmp(p, "01234567890123456789012345678901234567890", 10000));
		free(p);
	return (0);
}

