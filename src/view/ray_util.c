/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_util.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoon <kyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 22:07:50 by kyoon             #+#    #+#             */
/*   Updated: 2022/09/05 23:02:40 by kyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"
#include "../../inc/util.h"
#include <math.h>

double	dist_btwen(double x1, double x2, double y1, double y2)
{
	return (sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));
}

bool	is_down(double angle)
{
	return (angle > 0 && angle < M_PI);
}

bool	is_up(double angle)
{
	return (!is_down(angle));
}

bool	is_left(double angle)
{
	return (angle > 0.5 * M_PI && angle < 1.5 * M_PI);
}

bool	is_right(double angle)
{
	return (!is_left(angle));
}
