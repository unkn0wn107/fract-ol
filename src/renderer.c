/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaley <agaley@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 20:36:11 by agaley            #+#    #+#             */
/*   Updated: 2023/08/17 15:40:11 by agaley           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	ft_noop(t_env *env, int i, int j)
{
	(void)env;
	(void)i;
	(void)j;
}

static void	render_iter(t_env *env, int x, int y, void (*fun)(t_env*, int, int))
{
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
	image_create(env);
	x = 0;
	y = 0;
	render_iter(env, x, y, fun);
	image_refresh(env);
}

void	zoom_update_view(int x, int y, t_env *env)
{
	double	xcoeff;
	double	ycoeff;

	env->xm = x;
	env->ym = y;
	env->x0_prev = (env->xmax + env->xmin) / 2;
	env->y0_prev = (env->ymax + env->ymin) / 2;
	xcoeff = env->xmax - env->xmin;
	ycoeff = env->ymax - env->ymin;
	env->xmin = (double)(x - env->xoff - env->w)
		/ (double)(env->w * env->zoom * COEFF);
	env->ymin = (double)(y - env->yoff - env->h)
		/ (double)(env->h * env->zoom * COEFF);
	env->xmax = (double)(x - env->xoff + env->w)
		/ (double)(env->w * env->zoom * COEFF);
	env->ymax = (double)(y - env->yoff + env->h)
		/ (double)(env->h * env->zoom * COEFF);
	env->x0 = (env->xmax + env->xmin) / 2;
	env->y0 = (env->ymax + env->ymin) / 2;
	env->xmove += xcoeff / (env->xmax - env->xmin) * env->x0_prev - env->x0;
	env->ymove += ycoeff / (env->ymax - env->ymin) * env->y0_prev - env->y0;
}
