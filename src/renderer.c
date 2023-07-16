/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaley <agaley@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 20:36:11 by agaley            #+#    #+#             */
/*   Updated: 2023/07/17 01:01:32 by agaley           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	render_mandelbrot(t_env *env)
{
	float complex	c;
	size_t			i;
	int				color;
	float			re2;
	float			im2;

	i = 0;
	c = 0 + 0 * I;
	re2 = sqrt(creal(c));
	im2 = sqrt(cimag(c));
	while (++i <= env->iter && re2 + im2 <= 4.0)
	{
		c = re2 - im2 + creal(c)
			+ 2 * (sqrt(creal(c) + cimag(c)) - re2 - im2) * I;
		re2 = sqrt(creal(c));
		im2 = sqrt(cimag(c));
	}
	color = env->palette[i / env->iter * PALETTE_SIZE];
	ft_printf("%d\n", color);
}
// plot(x, y, color);

static void	render_julia(t_env *env)
{
	(void)env;
}

static void	render_burningship(t_env *env)
{
	(void)env;
}

void	render_fractal(t_env *env)
{
	if (env->fract == FRACT_JULIA)
		render_julia(env);
	else if (env->fract == FRACT_MANDELBROT)
		render_mandelbrot(env);
	else if (env->fract == FRACT_BURNINGSHIP)
		render_burningship(env);
}
