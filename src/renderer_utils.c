/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaley <agaley@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 21:10:26 by agaley            #+#    #+#             */
/*   Updated: 2023/08/17 15:42:25 by agaley           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zoom_reset(t_env *env)
{
	env->zoom = env->w / 16;
	env->zoom_step = 100;
}

void	coords_init(t_env *env)
{
	env->xoff = env->w / 2;
	env->yoff = env->h / 2;
	zoom_reset(env);
	env->iter = 26;
	env->xmove = 0;
	env->ymove = 0;
	env->xmin = -(double)env->xoff / (env->w * env->zoom * COEFF);
	env->ymin = -(double)env->yoff / (env->h * env->zoom * COEFF);
	env->xmax = (double)env->xoff / (env->w * env->zoom * COEFF);
	env->ymax = (double)env->yoff / (env->h * env->zoom * COEFF);
	zoom_update_view(env->xoff, env->yoff, env);
}

void	palette_init(t_env *env)
{
	int		i;
	double	grad_step;

	i = 0;
	grad_step = (double)0xFFFFFF / PALETTE_SIZE;
	while (env->color == 0 && i++ < PALETTE_SIZE)
		env->palette[i] = (mlx_get_color_value(env->mlxptr, i) * grad_step);
	while (env->color == 1 && i++ < PALETTE_SIZE)
		env->palette[i] = (mlx_get_color_value(env->mlxptr, 2 * i) * grad_step);
}

double	ft_lerp(t_env *env, int mode, double frac)
{
	if (mode == 0)
		return ((1.0 - frac) * env->xmin + frac * env->xmax);
	else
		return ((1.0 - frac) * env->ymin + frac * env->ymax);
}

void	set_vec_zero(double z[2], double z2[2])
{
	z[0] = 0.0;
	z[1] = 0.0;
	z2[0] = 0.0;
	z2[1] = 0.0;
}
