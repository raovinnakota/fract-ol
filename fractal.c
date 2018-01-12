/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvinnako <rvinnako@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 13:32:09 by rvinnako          #+#    #+#             */
/*   Updated: 2018/01/11 17:40:21 by rvinnako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

t_square	*inner_square(int x1, int y1, int length)
{
	t_square	*inner_square;

	inner_square = init_square();
	inner_square->x1 = (x1 + (length / 3));
	inner_square->y1 = (y1 + (length / 3));
	inner_square->width = (length / 3);
	printf("%d\n", inner_square->width);
	return (inner_square);
}

void		draw_square(t_square *square, t_env *env)
{
	int		i;
	int		j;

	i = square->y1;
	while (i < (square->width + square->y1))
	{
		j = square->x1;
		while (j < (square->width + square->x1))
		{
			mlx_pixel_put(env->mlx_ptr, env->win_ptr, j, i, 0x00FF00);
			j++;
		}
		i++;
	}
}

int		main(void)
{
	t_env	*env;
	t_square *square;

	env = init_env();
	env->mlx_ptr = mlx_init();
	env->win_ptr = mlx_new_window(env->mlx_ptr, env->winx, env->winy, "Serpienski");
	square = inner_square(0, 0, env->winx);
	draw_square(square, env);
	mlx_loop(env->mlx_ptr);
}
