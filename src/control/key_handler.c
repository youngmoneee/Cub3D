/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngpar <youngpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 17:16:30 by youngpar          #+#    #+#             */
/*   Updated: 2022/08/23 17:16:32 by youngpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int key_press(int code, t_cub *cub)
{
    t_key   *key;

    key = &cub->key;
    if (code == KEY_W)
        key->w = true;
    if (code == KEY_S)
        key->s = true;
    if (code == KEY_A)
        key->a = true;
    if (code == KEY_D)
        key->d = true;
    if (code == KEY_LEFT)
        key->larw = true;
    if (code == KEY_RIGHT)
        key->rarw = true;
    printf("%x\n", code);
    return (0);
}

int key_release(int code, t_cub *cub)
{
    t_key   *key;

    key = &cub->key;
    if (code == KEY_W)
        key->w = false;
    if (code == KEY_S)
        key->s = false;
    if (code == KEY_A)
        key->a = false;
    if (code == KEY_D)
        key->d = false;
    if (code == KEY_LEFT)
        key->larw = false;
    if (code == KEY_RIGHT)
        key->rarw = false;
    return (0);
}
