/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvinnako <rvinnako@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 18:27:48 by rvinnako          #+#    #+#             */
/*   Updated: 2018/01/24 17:22:04 by rvinnako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int		in_mandelbrot(t_env *env, int x, int y)
{
	int				i;
	t_mandelbrot	*brot;

	brot = init_mandelbrot();
	env->scale = (env->winx / (brot->max_x - brot->min_x));
	brot->u = (((float)(x) - (env->winx / 2)) / (env->scale * env->xzoom));
	brot->v = (((env->winy / 2) - (float)(y)) / (env->scale * env->yzoom));
	brot->ju = brot->u;
	brot->jv = brot->v;
	while (brot->iter < brot->max_iter && fabs(brot->u2) + fabs(brot->v2) <=
			brot->bound)
	{
		brot->u2 = (brot->u * brot->u) - (brot->v * brot->v);
		brot->v2 = 2 * brot->u * brot->v;
		brot->u = brot->u2 + brot->ju;
		brot->v = brot->v2 + brot->jv;
		(brot->iter)++;
	}
	if (brot->iter < brot->max_iter)
	{
		i = brot->iter;
		free(brot);
		return (i * 0xD3D3D3 * env->color);
	}
	free(brot);
	return (0xFFFFFF);
}

void	set_mandelbrot(t_env *env)
{
	int		i;
	int		j;
	int		x;
	int		y;

	i = 0;
	while (i < env->winy)
	{
		j = 0;
		while (j < env->winx)
		{
			x = j + env->xoff;
			y = i + env->yoff;
			env->pixels[j + i * env->winx] = in_mandelbrot(env, x, y);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(env->mlx_ptr, env->win_ptr, env->img_ptr, 0, 0);
}

void	draw_mandelbrot(void)
{
	t_env	*env;

	env = init_env();
	env->input = "mandelbrot";
	env->mlx_ptr = mlx_init();
	env->win_ptr = mlx_new_window(env->mlx_ptr, env->winx, env->winy,
									"Mandelbrot");
	env->img_ptr = mlx_new_image(env->mlx_ptr, env->winx, env->winy);
	env->pixels = (int*)mlx_get_data_addr(env->img_ptr, &(env->bpp),
					&(env->size_line), &(env->endian));
	set_mandelbrot(env);
	mlx_hook(env->win_ptr, 2, 0, my_key_funct, env);
	mlx_mouse_hook(env->win_ptr, my_mouse_funct, env);
	mlx_loop(env->mlx_ptr);
}
