/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoon <kyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 21:45:01 by kyoon             #+#    #+#             */
/*   Updated: 2022/09/05 21:45:26 by kyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTIL_H
# define UTIL_H

# include "../libft/libft.h"
# include "structure.h"

double	normalize(double angle);
char	*gnl(int fd, int idx);
void	exit_msg(const char *msg);

int		mapcheck(t_map map);
#endif
