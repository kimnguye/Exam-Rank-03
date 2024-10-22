#ifndef GET_NEXT_LINE_H
#define	GET_NEXT_LINE_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

#ifndef BUFFER_SIZE
#define	BUFFER_SIZE 42
#endif

char	*get_next_line(int fd);

#endif
