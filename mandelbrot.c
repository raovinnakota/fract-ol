/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvinnako <rvinnako@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 18:27:48 by rvinnako          #+#    #+#             */
/*   Updated: 2018/01/19 17:55:52 by rvinnako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	mandelbrot(t_env *env)
{
	t_mandelbrot	*brot;

	brot = init_mandelbrot();
	while (brot->pix_y < env->winy)
	{
		brot->cy = env->winy - (brot->pix_y * env->yzoom);
		brot->pix_x = 0;
		while (brot->pix_x < env->winx)
		{
			brot->u = 0.0;
			brot->v = 0.0;
			brot->u2 = (brot->u * brot->u);
			brot->v2 = (brot->v * brot->v);
			brot->cx = 0 + (brot->pix_x * env->xzoom);
			brot->iter = 1;
			while (brot->iter < brot->max_iter && brot->u2 + brot->v2 < brot->bound)
			{
				//env->pixels[(int)brot->u + (int)brot->v * env->winx] = 0xFFFFFF;
				brot->v = 2 * brot->u * brot->v + brot->cy;
				brot->u = brot->u2 - brot->v2 + brot->cx;
				brot->u2 = brot->u * brot->u;
				brot->v2 = brot->v * brot->v;
				brot->iter++;
				env->pixels[(int)brot->u2 + (int)brot->v2 * env->winx] = 0xFFFFFF;
			}
			//if (brot->iter >= brot->max_iter)
				//env->pixels[brot->pix_x + brot->pix_y * env->winx] = 0xFF00FF;
			(brot->pix_x)++;
		}
		(brot->pix_y)++;
	}
	mlx_put_image_to_window(env->mlx_ptr, env->win_ptr, env->img_ptr, 0, 0);
}

void	draw_mandelbrot(void)
{
	t_env	*env;

	env = init_env();
	env->input = "mandelbrot";
	env->mlx_ptr = mlx_init();
	env->win_ptr = mlx_new_window(env->mlx_ptr, env->winx, env->winy, "Mandelbrot");
	env->img_ptr = mlx_new_image(env->mlx_ptr, env->winx, env->winy);
	env->pixels = (int*)mlx_get_data_addr(env->img_ptr, &(env->bpp), &(env->size_line), &(env->endian));
	mandelbrot(env);
	mlx_key_hook(env->win_ptr, my_key_funct, env);
	mlx_mouse_hook(env->win_ptr, my_mouse_funct, env);
	mlx_loop(env->mlx_ptr);
}
/*void	set_mandelbrot(t_env *env)
{
	int		i;
	int		j;
	float	x;
	float	y;

	i = 0;
	x = 0;
	y = 0;
	while (i < env->winy)
	{
		j = 0;
		while (j < env->winx)
		{
			j++;
		}
		i++;
	}
}

void	draw_mandelbrot(void)
{
	t_env	*env;

	env = init_env();
	env->input = "mandelbrot";
	env->mlx_ptr = mlx_init();
	env->win_ptr = mlx_new_window(env->mlx_ptr, env->winx, env->winy, "Mandelbrot");
	env->img_ptr = mlx_new_image(env->mlx_ptr, env->winx, env->winy);
	env->pixels = (int*)mlx_get_data_addr(env->img_ptr, &(env->bpp), &(env->size_line), &(env->endian));
	set_mandelbrot(env);
}*/
