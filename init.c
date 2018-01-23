/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvinnako <rvinnako@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 17:05:45 by rvinnako          #+#    #+#             */
/*   Updated: 2018/01/22 18:54:21 by rvinnako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

t_env			*init_env(void)
{
	t_env	*env;

	env = (t_env*)malloc(sizeof(t_env));
	env->winx = 700;
	env->winy = 700;
	env->limit = 5;
	env->bpp = 0;
	env->size_line = 0;
	env->endian = 0;
	env->scale = 0;
	env->xzoom = 1;
	env->yzoom = 1;
	env->x0 = 0;
	env->y0 = 0;
	env->xoff = 0;
	env->yoff = 0;
	env->input = NULL;
	env->pixels = NULL;
	env->mlx_ptr = NULL;
	env->win_ptr = NULL;
	env->img_ptr = NULL;
	return (env);
}

t_mandelbrot	*init_mandelbrot(void)
{
	t_mandelbrot *mandelbrot;

	mandelbrot = (t_mandelbrot*)malloc(sizeof(t_mandelbrot));
	mandelbrot->ju = 0;
	mandelbrot->jv = 0;
	mandelbrot->u = 0;
	mandelbrot->u2 = 0;
	mandelbrot->v = 0;
	mandelbrot->v2 = 0;
	mandelbrot->min_x = -5;
	mandelbrot->min_y = -5;
	mandelbrot->max_x = 5;
	mandelbrot->max_y = 5;
	mandelbrot->pix_y = 0;
	mandelbrot->pix_x = 0;
	mandelbrot->iter = 0;
	mandelbrot->max_iter = 25;
	mandelbrot->bound = 16;

	return (mandelbrot);
}
