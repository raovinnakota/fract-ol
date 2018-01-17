/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvinnako <rvinnako@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 13:28:59 by rvinnako          #+#    #+#             */
/*   Updated: 2018/01/16 16:10:23 by rvinnako         ###   ########.fr       */
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
	int				*pixels;
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
}					t_env;

typedef struct		s_square
{
	int				x1;
	int				y1;
	int				width;
}					t_square;

t_env		*init_env(void);
t_square	*init_square(void);
t_square	set_square(int x1, int y1, int len);
t_square	*square_list(t_square *outer_square);
t_square	*inner_square(int x1, int y1, int length);
void		draw_square(t_square *square, t_env *env);
void		serpienski(t_square *square, t_env *env, int limit);
void		draw_serpienski(void);

#endif
