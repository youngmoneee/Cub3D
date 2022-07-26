/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngpar <youngpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 21:27:33 by youngpar          #+#    #+#             */
/*   Updated: 2022/07/26 22:09:47 by youngpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/structure.h"

char	*gnl(t_parse *parse, int idx)
{
	char	*ret;
	char	buf;
	int		is_read;

	is_read = read(parse->fd, &buf, 1);
	if (!is_read)
}
