/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaley <agaley@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 20:36:11 by agaley            #+#    #+#             */
/*   Updated: 2023/07/29 02:16:11 by agaley           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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

static void	render_mandelbrot(t_env *env, int x, int y)
{
	double complex	c;
	double complex	z;
	size_t			iter;

	c = (x - env->x0f) * 4 / env->w + ((y - env->y0f) * 4 / env->h) * I;
	z = 0;
	iter = 0;
	while (cabs(z) < 2 && iter < env->iter)
	{
		z = z * z + c;
		iter++;
	}
	((int *)env->image)[x * y] = env->palette[iter % PALETTE_SIZE];
}

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

void	render_fractal(t_env *env)
{
	void	(*fun)(t_env*, int, int);
	int		x;
	int		y;

	if (env->fract == FRACT_JULIA)
		fun = render_julia;
	else if (env->fract == FRACT_MANDELBROT)
		fun = render_mandelbrot;
	else if (env->fract == FRACT_BURNINGSHIP)
		fun = render_burningship;
	if (!fun)
		handle_exit(1, MSG_ERR_ARGS, NULL);
	create_image(env);
	env->x0f = env->w / 2;
	env->y0f = env->h / 2;
	x = 0;
	y = 0;
	while (y++ <= env->h)
		while (x++ <= env->w)
			fun(env, x, y);
	refresh_image(env);
}
