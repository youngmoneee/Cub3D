/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngpar <youngpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 17:17:27 by youngpar          #+#    #+#             */
/*   Updated: 2022/09/20 18:47:56 by kyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdio.h>
#include "../../libft/libft.h"
#include <math.h>

double	normalize(double angle)
{
	angle = remainder(angle, M_PI * 2);
	if (angle < 0)
		return (M_PI * 2 + angle);
	else
		return (angle);
}

char	*gnl(int fd, int idx)
{
	char	*ret;
	char	buf;
	int		is_read;

	is_read = read(fd, &buf, 1);
	if (buf == '\n' && idx == 0)
		ret = ft_calloc(sizeof(char), 2);
	else if (is_read == 0 || buf == '\n')
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
	write(2, msg, ft_strlen(msg));
	write(2, "\n", 1);
	exit(1);
}
