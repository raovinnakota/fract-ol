/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvinnako <rvinnako@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 16:05:36 by rvinnako          #+#    #+#             */
/*   Updated: 2018/01/23 18:33:41 by rvinnako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int		my_key_funct(int keycode, t_env *env)
{
	if (keycode == 53)
		exit(0);
	if (keycode == 123)
		env->xoff += -5;
	if (keycode == 125)
		env->yoff += 5;
	if (keycode == 124)
		env->xoff += 5;
	if (keycode == 126)
		env->yoff += -5;
	if (keycode == 0 && env->color < 9999999)
		env->color *= 1.05;
	if (keycode == 1 && env->color > 1.5)
		env->color /= 1.05;
	if (keycode == 2)
		reset_env(env);
	if (ft_strcmp(env->input, "serpienski") == 0)
		set_serpienski(env);
	if (ft_strcmp(env->input, "mandelbrot") == 0)
		set_mandelbrot(env);
	if (ft_strcmp(env->input, "julia") == 0)
		set_julia(env);
	return (0);
}

int		my_mouse_funct(int keycode, int x, int y, t_env *env)
{
	if (!x || !y)
		exit(0);
	if (keycode == 4)
	{
		env->xzoom *= 1.05;
		env->yzoom *= 1.05;
	}
	if (keycode == 5)
	{
		env->xzoom /= 1.05;
		env->yzoom /= 1.05;
	}
	if (ft_strcmp(env->input, "serpienski") == 0)
		set_serpienski(env);
	if (ft_strcmp(env->input, "mandelbrot") == 0)
		set_mandelbrot(env);
	if (ft_strcmp(env->input, "julia") == 0)
		set_julia(env);
	return (0);
}

int		my_mouse_motion(int x, int y, t_env *env)
{
	if ((x == env->u0) && (y == env->v0))
		return (0);
	if ((x < 0) || (x > env->winx) || (y < 0) || (y > env->winy))
		return (0);
	env->u0 = ((((double)x - env->winx) / (env->winx / 2)) + 1);
	env->v0 = ((((double)y - env->winy) / (env->winy / 2)) + 1);
	if (ft_strcmp(env->input, "julia") == 0)
		set_julia(env);
	return (0);
}

int		main(int ac, char **av)
{
	if (ac < 2 || ac > 2)
	{
		ft_putstr("[Usage] ./fractal <fractal>\n");
		ft_putstr("Available fractals:\nserpienski\nmandelbrot\njulia\n");
		return (0);
	}
	ft_putstr("To toggle color, use 'a'/'s'\n");
	ft_putstr("Use the arrow keys to move around\n");
	ft_putstr("To reset image to initial state, use 'd'");
	if (ft_strcmp(av[1], "serpienski") == 0)
		draw_serpienski();
	if (ft_strcmp(av[1], "mandelbrot") == 0)
		draw_mandelbrot();
	if (ft_strcmp(av[1], "julia") == 0)
		draw_julia();
	return (0);
}
