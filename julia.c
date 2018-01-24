/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvinnako <rvinnako@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 12:13:43 by rvinnako          #+#    #+#             */
/*   Updated: 2018/01/23 18:08:39 by rvinnako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int		in_julia(t_env *env, int x, int y)
{
	t_mandelbrot	*julia;

	julia = init_mandelbrot();
	env->scale = (env->winx / (julia->max_x - julia->min_x));
	julia->u = (((float)(x) - (env->winx / 2)) / (env->scale * env->xzoom));
	julia->v = (((env->winy / 2) - (float)(y)) / (env->scale * env->yzoom));
	julia->ju = env->u0;
	julia->jv = env->v0;
	julia->iter = 0;
	while (julia->iter < julia->max_iter && julia->u + julia->v <= julia->bound)
	{
		julia->u2 = (julia->u * julia->u) - (julia->v * julia->v);
		julia->v2 = (2 * julia->u * julia->v);
		julia->u = julia->u2 + julia->ju;
		julia->v = julia->v2 + julia->jv;
		(julia->iter)++;
	}
	if (julia->iter < julia->max_iter)
		return (julia->iter * 0xD3D3D3);
	return (0xFFFFFF);
}

void	set_julia(t_env *env)
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
			env->pixels[j + i * env->winx] = in_julia(env, abs(x), abs(y));
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(env->mlx_ptr, env->win_ptr, env->img_ptr, 0, 0);
}

void	draw_julia(void)
{
	t_env	*env;

	env = init_env();
	env->input = "julia";
	env->mlx_ptr = mlx_init();
	env->win_ptr = mlx_new_window(env->mlx_ptr, env->winx, env->winy,
									"Mandelbrot");
	env->img_ptr = mlx_new_image(env->mlx_ptr, env->winx, env->winy);
	env->pixels = (int*)mlx_get_data_addr(env->img_ptr, &(env->bpp),
											&(env->size_line), &(env->endian));
	set_julia(env);
	mlx_hook(env->win_ptr, 2, 0, my_key_funct, env);
	mlx_mouse_hook(env->win_ptr, my_mouse_funct, env);
	mlx_hook(env->win_ptr, 6, 0, my_mouse_motion, env);
	mlx_loop(env->mlx_ptr);
}
