#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdio.h>
#include "../../libft/libft.h"

char	*gnl(int fd, int idx)
{
	char	*ret;
	char	buf;
	int		is_read;

	is_read = read(fd, &buf, 1);
	if (is_read == 0 || buf == '\n')
	{
		ret = (char *) malloc(sizeof(char) * (idx + 1));
		buf = 0;
	}
	else
		ret = gnl(fd, idx + 1);
	ret[idx] = buf;
	return (ret);
}

void	exit_msg(const char *msg)
{
	perror(msg);
	exit(1);
}