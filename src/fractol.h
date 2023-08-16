/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaley <agaley@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 22:51:50 by agaley            #+#    #+#             */
/*   Updated: 2023/08/16 01:23:19 by agaley           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libft/libft.h"
# include "../libmlx/mlx.h"
# include <math.h>
# include <complex.h>
# include <limits.h>

# define PALETTE_SIZE 25
# define MAX_ZOOM INT_MAX
# define WIN_WIDTH 1918
# define WIN_HEIGHT 1024

# define COEFF 0.1

# define MIN_COLOR_SETS 0
# define MAX_COLOR_SETS 1

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
# define KEY_COLOR 99
# define KEY_PGUP 65365
# define KEY_PGDOWN 65366

# define MSG_ERR_ARGS "Args error\n"
# define MSG_ERR_MLX_INIT "MLX initialization error\n"
# define MSG_ERR_WIN_INIT "Window initialization error\n"
# define MSG_ERR_MEMORY "Memory allocation error\n"
# define MSG_ERR_ARRAY_NOT_ZERO "Array value is not zero\n"
# define MSG_BYE "Bye!\n"

// Environment env definition
typedef struct s_env
{
	void			*mlxptr;
	void			*winptr;
	int				e;
	int				sl;
	int				bpp;
	int				w;
	int				h;
	char			*hstr;
	char			*wstr;
	size_t			zoom;
	size_t			zoom_step;
	int				fract;
	double			x0f;
	double			y0f;
	double			x0;
	double			y0;
	size_t			iter;
	void			*image;
	char			*img_data;
	int				xm;
	int				ym;
	unsigned int	palette[PALETTE_SIZE];
	int				color;
}t_env;

void	init_env(t_env *env);

// Parser
void	parse_args(char **argv, t_env *env);

// Error handlers
void	handle_exit(int error, const char *msg, t_env *env);

// Renderer
void	render_fractal(t_env *env);

// Renderer utils
void	coords_reset(t_env *env);
void	zoom_reset(t_env *env);
void	coords_init(t_env *env);
void	palette_init(t_env *env);
void	zoom_update_view(int x, int y, t_env *env);

// Window
void	handle_zoom(int key, int x, int y, t_env *env);
void	create_image(t_env *env);
void	refresh_image(t_env *env);

// Control
int		handle_keys(int key, void *env);
int		handle_mouse(int key, int x, int y, void *env);

// Control utils
void	palette_change_color(t_env *env);
void	zoom_change_step(int key, t_env *env);
void	zoom_increment(int key, t_env *env);

// Matrix
double	**create_zoom_matrix(size_t width, size_t height, t_env *env);

#endif
