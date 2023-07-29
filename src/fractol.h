/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaley <agaley@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 22:51:50 by agaley            #+#    #+#             */
/*   Updated: 2023/06/28 18:05:15 by agaley           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libft/libft.h"
# include "../libmlx/mlx.h"
# include <math.h>
# include <complex.h>

# define PALETTE_SIZE 256
# define MAX_ZOOM 10000

# define FRACT_JULIA 1
# define FRACT_MANDELBROT 2
# define FRACT_BURNINGSHIP 3

# define MOUSE_LEFT 1
# define MOUSE_MIDDLE 2
# define MOUSE_RIGHT 3
# define MOUSE_UP 4
# define MOUSE_DOWN 5

# define KEY_ESC 65307
# define KEY_LEFT 65361
# define KEY_UP 65362
# define KEY_RIGHT 65363
# define KEY_DOWN 65364

// Integer stack definition
typedef struct s_env
{
	void	*mlxptr;
	void	*winptr;
	int		w;
	int		h;
	int		zoom;
	int		fract;
	int		xf;
	int		yf;
	size_t	iter;
	void	*image;
	int		xm;
	int		ym;
	int		palette[PALETTE_SIZE];
}t_env;

// Parser
void	parse_args(char **argv, t_env *env);

// Error handlers
void	handle_exit(int error, t_env *env);

// Renderer
void	render_fractal(t_env *env);

// Window
void	handle_zoom(int key, t_env *env);

// Control
int		handle_keys(int key, void *env);
int		handle_mouse(int key, void *env);

// Matrix
double	**create_2d_array(ssize_t width, ssize_t height);

#endif
