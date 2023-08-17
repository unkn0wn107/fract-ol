/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer_funcs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaley <agaley@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 15:36:22 by agaley            #+#    #+#             */
/*   Updated: 2023/08/17 15:38:56 by agaley           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	render_mandelbrot(t_env *env, int x, int y)
{
	size_t			i;
	double			z[2];
	double			z2[2];
	double			coord[2];
	double			tmp;

	i = 0;
	set_vec_zero(z, z2);
	coord[0] = ft_lerp(env, 0, (double)x / (double)env->w) + env->xmove;
	coord[1] = ft_lerp(env, 1, (double)y / (double)env->w) + env->ymove;
	while (i < env->iter && z2[0] + z2[1] <= 4)
	{
		z2[0] = z[0] * z[0];
		z2[1] = z[1] * z[1];
		tmp = z2[0] - z2[1] + coord[0];
		z[1] = 2 * z[0] * z[1] + coord[1];
		z[0] = tmp;
		i++;
	}
	if (i == env->iter)
		plot(env, x, y, 0);
	else
		plot(env, x, y, env->palette[env->iter / i % PALETTE_SIZE]);
}

void	render_julia(t_env *env, int x, int y)
{
	size_t			i;
	double			z[2];
	double			z2[2];
	double			tmp;

	i = 0;
	z[0] = ft_lerp(env, 0, (double)x / (double)env->w) + env->xmove;
	z[1] = ft_lerp(env, 1, (double)y / (double)env->h)
		+ env->ymove;
	z2[0] = 0.0;
	z2[1] = 0.0;
	while (i < env->iter && z2[0] + z2[1] <= 4)
	{
		z2[0] = z[0] * z[0];
		z2[1] = z[1] * z[1];
		tmp = z2[0] - z2[1] + 0.285;
		z[1] = 2 * z[0] * z[1] + 0.01;
		z[0] = tmp;
		i++;
	}
	if (i == env->iter)
		plot(env, x, y, 0);
	else
		plot(env, x, y, env->palette[env->iter / i % PALETTE_SIZE]);
}

void	render_burningship(t_env *env, int x, int y)
{
	size_t			i;
	double			z[2];
	double			z2[2];
	double			coord[2];
	double			tmp;

	i = 0;
	set_vec_zero(z, z2);
	coord[0] = ft_lerp(env, 0, (double)x / (double)env->w) + env->xmove;
	coord[1] = ft_lerp(env, 1, (double)y / (double)env->w) + env->ymove;
	while (i < env->iter && z2[0] + z2[1] <= 1)
	{
		z2[0] = z[0] * z[0];
		z2[1] = z[1] * z[1];
		tmp = fabs(z2[0] - z2[1]) + coord[0];
		z[1] = fabs(2 * z[0] * z[1]) + coord[1];
		z[0] = tmp;
		i++;
	}
	if (i == env->iter)
		plot(env, x, y, 0);
	else
		plot(env, x, y, env->palette[env->iter / i % PALETTE_SIZE]);
}
