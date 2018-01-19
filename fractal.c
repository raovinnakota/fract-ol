/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvinnako <rvinnako@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 16:05:36 by rvinnako          #+#    #+#             */
/*   Updated: 2018/01/18 18:33:34 by rvinnako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int		my_key_funct(int keycode, t_env *env)
{
	if (keycode == 53)
		exit(0);
	if (keycode == 123)
	{
		env->xoff += -7;
		if (ft_strcmp(env->input, "serpienski") == 0)
			set_serpienski(env);
	}
	if (keycode == 125)
	{
		env->yoff += 7;
		if (ft_strcmp(env->input, "serpienski") == 0)
			set_serpienski(env);
	}
	if (keycode == 124)
	{
		env->xoff += 7;
		if (ft_strcmp(env->input, "serpienski") == 0)
			set_serpienski(env);
	}
	if (keycode == 126)
	{
		env->yoff += -7;
		if (ft_strcmp(env->input, "serpienski") == 0)
			set_serpienski(env);
	}
	return (0);
}

int		my_mouse_funct(int keycode, int x, int y, t_env *env)
{
	if (!x || !y)
		exit(0);
	//env->xoff += x;
	//env->yoff += y;
	if (keycode == 4)
	{
		env->xzoom *= 1.05;
		env->yzoom *= 1.05;
		if (ft_strcmp(env->input, "serpienski") == 0)
			set_serpienski(env);
	}
	if (keycode == 5)
	{
		env->xzoom /= 1.05;
		env->yzoom /= 1.05;
		if (ft_strcmp(env->input, "serpienski") == 0)
			set_serpienski(env);
	}
	return (0);
}


int		main(int ac, char **av)
{
	if (ac < 2 || ac > 2)
	{
		ft_putstr("[Usage] ./fractal <fractal> \nAvailable fractals:\n-->serpienski\n");
		return (0);
	}
	if (ft_strcmp(av[1],"serpienski") == 0 || ft_strcmp(av[1], "Serpienski") == 0)
		draw_serpienski();

	/*if (ft_strcmp(av[1], "Mandelbrot") == 0 || ft_strcmp(av[1], "mandelbrot") == 0)
		draw_mandelbrot();*/
	return (0);
}
