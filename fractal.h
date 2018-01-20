/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvinnako <rvinnako@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 13:28:59 by rvinnako          #+#    #+#             */
/*   Updated: 2018/01/19 17:02:45 by rvinnako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTAL_H
# define FRACTAL_H
# include "libft/libft.h"
# include "minilibx_macos/mlx.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>

typedef struct		s_env
{
	int				winx;
	int				winy;
	int				limit;
	int				bpp;
	int				size_line;
	int				endian;
	float			xzoom;
	float			yzoom;
	int				xoff;
	int				yoff;
	char			*input;
	int				*pixels;
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
}					t_env;

typedef struct		s_mandelbrot
{
	float			cx;
	float			cy;
	float			u;
	float			u2;
	float			v;
	float			v2;
	int				pix_y;
	int				pix_x;
	int				iter;
	int				max_iter;
	int				bound;
}					t_mandelbrot;

t_env				*init_env(void);

t_mandelbrot		*init_mandelbrot(void);

int					my_key_funct(int keycode, t_env *env);
int					in_serpienski(int x, int y);
int					my_mouse_funct(int keycode, int x, int y, t_env *env);

void				set_serpienski(t_env *env);
void				draw_serpienski(void);
void				draw_mandelbrot(void);

#endif
