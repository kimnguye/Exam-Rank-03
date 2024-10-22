#include "get_next_line.h"

char	*ft_strdup(char * str)
{
	char	*dup;
	int		len = 0;

	while (str[len])
		len++;
	dup = malloc(len + 1);
	dup[len--] = '\0';
	while (len >= 0)
	{
		dup[len] = str[len];
		len--;
	}
	return (dup);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE];
	static int	buff_read;
	static int	buff_pos;
	int			i = 0;
	char		line[70000];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (1)
	{
		if (buff_pos >= buff_read)
		{
			buff_read = read(fd, buffer, BUFFER_SIZE);
			if (buff_read <= 0)
				break;
			buff_pos = 0;
		}
		line[i++] = buffer[buff_pos++];
		if (line[i - 1] == '\n')
			break;
	}
	line[i] = '\0';
	if (i == 0)
		return (NULL);
	return (ft_strdup(line));
}

int	main(void)
{
	int	fd = open("get_next_line.c", O_RDONLY);
	int	nb;

	while (1)
	{
		nb = printf("%s", get_next_line(fd));
		if ( nb == -1 || nb == 6)
			return (0);
	}
	return(0);
}
