/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoon <kyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 21:28:22 by kyoon             #+#    #+#             */
/*   Updated: 2022/09/05 21:33:08 by kyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HANDLER_H
# define HANDLER_H

# include "structure.h"

int		key_press(int code, t_cub *cub);
int		key_release(int code, t_cub *cub);
void	move(t_cub *cub);
void	rotate(t_cub *cub);

#endif
