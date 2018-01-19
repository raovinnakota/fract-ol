/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvinnako <rvinnako@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 18:27:48 by rvinnako          #+#    #+#             */
/*   Updated: 2018/01/18 18:38:09 by rvinnako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	set_mandelbrot(t_env *env)
{
	int		i;
	int		j;
	float	x;
	float	y;

	i = 0;
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
}
