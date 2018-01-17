/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvinnako <rvinnako@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 17:05:45 by rvinnako          #+#    #+#             */
/*   Updated: 2018/01/17 14:37:03 by rvinnako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

t_env		*init_env(void)
{
	t_env	*env;

	env = (t_env*)malloc(sizeof(t_env));
	env->winx = 600;
	env->winy = 600;
	env->limit = 9;
	env->bpp = 0;
	env->size_line = 0;
	env->endian = 0;
	env->pixels = NULL;
	env->pixels = NULL;
	env->mlx_ptr = NULL;
	env->win_ptr = NULL;
	env->img_ptr = NULL;
	return (env);
}

t_square	*init_square(void)
{
	t_square	*square;

	square = (t_square*)malloc(sizeof(t_square));
	square->x1 = 0;
	square->y1 = 0;
	square->width = 0;
	return (square);
}
