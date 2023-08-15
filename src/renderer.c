/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaley <agaley@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 20:36:11 by agaley            #+#    #+#             */
/*   Updated: 2023/08/15 04:45:04 by agaley           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	render_mandelbrot(t_env *env, int x, int y)
{
	size_t			i;
	double			z[2];
	double			z2[2];
	double			tmp;

	i = 0;
	z[0] = 0.0;
	z[1] = 0.0;
	z2[0] = 0.0;
	z2[1] = 0.0;
	while (i < env->iter && z2[0] + z2[1] <= 4)
	{
		z2[0] = sqrt(z[0]);
		z2[1] = sqrt(z[1]);
		tmp = z2[0] - z2[1] + COEFF * (x + env->xm - env->x0) / env->zoom;
		z[1] = 2 * z[0] * z[1] + COEFF * (y + env->ym - env->y0) / env->zoom;
		z[0] = tmp;
		i++;
	}
	if (i == env->iter)
		mlx_pixel_put(env->mlxptr, env->winptr, x, y, 0);
	else
		mlx_pixel_put(env->mlxptr, env->winptr, x, y,
			env->palette[i % PALETTE_SIZE]);
}

// static void	render_mandelbrot(t_env *env, int x, int y)
// {
// 	float complex	c;
// 	size_t			i;
// 	int				color;
// 	float			re2;
// 	float			im2;

// 	i = 0;
// 	c = 0 + 0 * I;
// 	re2 = sqrt(creal(c));
// 	im2 = sqrt(cimag(c));
// 	while (++i <= env->iter && re2 + im2 <= 4.0)
// 	{
// 		c = re2 - im2 + creal(c)
// 			+ 2 * (sqrt(creal(c) + cimag(c)) - re2 - im2) * I;
// 		re2 = sqrt(creal(c));
// 		im2 = sqrt(cimag(c));
// 	}
// 	if (i == env->iter)
// 		color = 0;
// 	else
// 		((int *)env->image)[x * y] = env->palette[i / env->iter * PALETTE_SIZE];
// 	ft_printf("%d\n", color);
// }
// plot(x, y, collor);

// static void	render_mandelbrot(t_env *env, int x, int y)
// {
// 	double complex	c;
// 	double complex	z;
// 	size_t			iter;
// 	c = (x - env->x0f) * 4 / env->w + ((y - env->y0f) * 4 / env->h) * I;
// 	z = 0;
// 	iter = 0;
// 	while (cabs(z) < 2 && iter < env->iter)
// 	{
// 		z = z * z + c;
// 		iter++;
// 	}
// 	((int *)env->image)[x * y] = env->palette[iter % PALETTE_SIZE];
// }

// static void	render_mandelbrot(t_env *env, int x, int y)
// {
// 	size_t			i;
// 	double			z[2];
// 	double			z2[2];
// 	double			tmp;
// 	unsigned int	*image;

// 	i = 0;
// 	z[0] = 0.0;
// 	z[1] = 0.0;
// 	z2[0] = 0.0;
// 	z2[1] = 0.0;
// 	image = (unsigned int *)env->img_data;
// 	while (i < env->iter && z2[0] + z2[1] <= 4)
// 	{
// 		z2[0] = sqrt(z[0]);
// 		z2[1] = sqrt(z[1]);
// 		tmp = z2[0] - z2[1] + x / env->zoom + env->x0f;
// 		z[1] = 2 * z[0] * z[1] + y / env->zoom + env->y0f;
// 		z[0] = tmp;
// 		i++;
// 	}
// 	printf("(%d,%d), ", x, y);
// 	if (i == env->iter)
// 		image[y * env->w + x] = 0;
// 	else
// 		image[y * env->w + x] = env->palette[i % PALETTE_SIZE];
// }

static void	render_julia(t_env *env, int x, int y)
{
	(void)env;
	(void)x;
	(void)y;
}

static void	render_burningship(t_env *env, int x, int y)
{
	(void)env;
	(void)x;
	(void)y;
}

static void	ft_noop(t_env *env, int i, int j)
{
	(void)env;
	(void)i;
	(void)j;
}

void	render_fractal(t_env *env)
{
	void	(*fun)(t_env*, int, int);
	int		x;
	int		y;

	fun = ft_noop;
	if (env->fract == FRACT_JULIA)
		fun = render_julia;
	else if (env->fract == FRACT_MANDELBROT)
		fun = render_mandelbrot;
	else if (env->fract == FRACT_BURNINGSHIP)
		fun = render_burningship;
	else
		handle_exit(1, MSG_ERR_ARGS, NULL);
	refresh_image(env);
	create_image(env);
	env->x0 = env->w / 2;
	env->y0 = env->h / 2;
	y = 0;
	while (y < env->h)
	{
		x = 0;
		while (x < env->w)
		{
			fun(env, x, y);
			x++;
		}
		y++;
	}
}

			// m[row][col] = env->x0f - env->x0 + col * (2.0 * env->zoom) / width;
			// m[row][col] = env->y0f - env->y0 + row * (2.0 * env->zoom) / height;
