/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvinnako <rvinnako@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 16:05:36 by rvinnako          #+#    #+#             */
/*   Updated: 2018/01/18 16:51:35 by rvinnako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int		my_key_funct(int keycode, t_env *env)
{
	if (keycode == 53)
		exit(0);
	if (keycode == 0)
	{
		//env->xzoom = env->xzoom * 1.01;
		//env->yzoom = env->yzoom * 1.01;
		env->xoff += -5;
		if (ft_strcmp(env->input, "serpienski") == 0)
			set_serpienski(env);
	}
	if (keycode == 1)
	{
		env->yoff += 5;
		if (ft_strcmp(env->input, "serpienski") == 0)
			set_serpienski(env);
	}
	if (keycode == 2)
	{
		//env->xzoom = env->xzoom / 1.01;
		//env->yzoom = env->yzoom / 1.01;
		env->xoff += 5;
		if (ft_strcmp(env->input, "serpienski") == 0)
			set_serpienski(env);
	}
	if (keycode == 13)
	{
		env->yoff += -5;
		if (ft_strcmp(env->input, "serpienski") == 0)
			set_serpienski(env);
	}
	//if (keycode == )
	return (0);
}



int		main(int ac, char **av)
{
	if (ac < 2 || ac > 2)
	{
		ft_putstr("[Usage] ./fractal <fractal> \nAvailable fractals:\n-->serpienski\n");
		return (0);
	}
	if (ft_strcmp(av[1],"serpienski") || ft_strcmp(av[1], "Serpienski"))
		draw_serpienski();
	return (0);
}
