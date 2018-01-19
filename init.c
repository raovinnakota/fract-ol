/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvinnako <rvinnako@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 17:05:45 by rvinnako          #+#    #+#             */
/*   Updated: 2018/01/18 18:38:07 by rvinnako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

t_env		*init_env(void)
{
	t_env	*env;

	env = (t_env*)malloc(sizeof(t_env));
	env->winx = 700;
	env->winy = 700;
	env->limit = 5;
	env->bpp = 0;
	env->size_line = 0;
	env->endian = 0;
	env->xzoom = 1;
	env->yzoom = 1;
	env->xoff = 0;
	env->yoff = 0;
	env->input = NULL;
	env->pixels = NULL;
	env->mlx_ptr = NULL;
	env->win_ptr = NULL;
	env->img_ptr = NULL;
	return (env);
}
