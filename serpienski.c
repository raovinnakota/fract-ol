/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serpienski.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvinnako <rvinnako@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 13:32:09 by rvinnako          #+#    #+#             */
/*   Updated: 2018/01/18 16:35:05 by rvinnako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int		in_serpienski(int x, int y)
{
	while (1)
	{
		if (x == 0 || y == 0)
			return (0);
		if (x % 3 == 1 && y % 3 == 1)
			return (0xFFFFFF);
		x = x / 3;
		y = y / 3;
	}
}

void	set_serpienski(t_env *env)
{
	int		i;
	int		j;
	float	x;
	float	y;

	i = 0;
	while (i < 700)
	{
		j = 0;
		while (j < 700)
		{
			x = (j * env->xzoom) + env->xoff;
			y = (i * env->yzoom) + env->yoff;
			env->pixels[j + (i * 700)] = in_serpienski(abs((int)x), abs((int)y));
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(env->mlx_ptr, env->win_ptr, env->img_ptr, 0, 0);
}

void	draw_serpienski(void)
{
	t_env		*env;

	env = init_env();
	env->input = "serpienski";
	env->mlx_ptr = mlx_init();
	env->win_ptr = mlx_new_window(env->mlx_ptr, env->winx, env->winy, "Serpienski");
	env->img_ptr = mlx_new_image(env->mlx_ptr, env->winx, env->winy);
	env->pixels = (int*)mlx_get_data_addr(env->img_ptr, &(env->bpp), &(env->size_line), &(env->endian));
	set_serpienski(env);
	//mlx_put_image_to_window(env->mlx_ptr, env->win_ptr, env->img_ptr, 0, 0);
	mlx_key_hook(env->win_ptr, my_key_funct, env);
	mlx_loop(env->mlx_ptr);
}
