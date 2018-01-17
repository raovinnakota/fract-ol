/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serpienski.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvinnako <rvinnako@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 13:32:09 by rvinnako          #+#    #+#             */
/*   Updated: 2018/01/16 16:19:45 by rvinnako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void		serpienski(t_square *square, t_env *env, int limit)
{
	int			i;
	t_square	*inner;
	t_square	*list;

	if (limit == 0)
		return ;
	i = 0;
	inner = inner_square(square->x1, square->y1, square->width);
	draw_square(inner, env);
	list = square_list(inner);

	while (i < 8)
	{
		serpienski(&list[i], env, limit - 1);
		i++;
	}
	(env->limit)--;
}

t_square	set_square(int x1, int y1, int len)
{
	t_square	square;

	square.x1 = x1;
	square.y1 = y1;
	square.width = len;
	return (square);
}

t_square	*square_list(t_square *outer_square)
{
	int			x1;
	int			y1;
	int			len;
	t_square	*list;

	x1 = outer_square->x1;
	y1 = outer_square->y1;
	len = outer_square->width;
	list = (t_square*)malloc(sizeof(t_square) * sizeof(int) * 24);
	list[0] = set_square(x1 - len, y1 - len, len);
	list[1] = set_square(x1, y1 - len, len);
	list[2] = set_square(x1 + len, y1 - len, len);
	list[3] = set_square(x1 - len, y1, len);
	list[4] = set_square(x1 + len, y1, len);
	list[5] = set_square(x1 - len, y1 + len, len);
	list[6] = set_square(x1, y1 + len, len);
	list[7] = set_square(x1 + len, y1 + len, len);
	return (list);
}


t_square	*inner_square(int x1, int y1, int length)
{
	t_square	*inner_square;

	inner_square = init_square();
	inner_square->x1 = (x1 + (length / 3));
	inner_square->y1 = (y1 + (length / 3));
	inner_square->width = (length / 3);
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

void	draw_serpienski(void)
{
	t_env		*env;
	t_square	*outer;
	t_square	*list;

	env = init_env();
	env->mlx_ptr = mlx_init();
	env->win_ptr = mlx_new_window(env->mlx_ptr, env->winx, env->winy, "Serpienski");
	outer = init_square();
	outer->x1 = 0;
	outer->y1 = 0;
	outer->width = env->winx;
	serpienski(outer, env, env->limit);
	mlx_loop(env->mlx_ptr);
}
