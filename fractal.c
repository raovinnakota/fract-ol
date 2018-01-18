/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvinnako <rvinnako@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 16:05:36 by rvinnako          #+#    #+#             */
/*   Updated: 2018/01/17 16:29:15 by rvinnako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int		my_key_funct(int keycode, void *param)
{
	if (keycode == 53)
		exit(0);
	if ((int)param == 0)
		return (0);
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
