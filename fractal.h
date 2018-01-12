/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvinnako <rvinnako@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 13:28:59 by rvinnako          #+#    #+#             */
/*   Updated: 2018/01/11 17:28:12 by rvinnako         ###   ########.fr       */
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
#endif
