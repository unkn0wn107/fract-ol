/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaley <agaley@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 21:10:26 by agaley            #+#    #+#             */
/*   Updated: 2023/08/16 12:38:57 by agaley           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	coords_reset(t_env *env)
{
	env->xoff = env->w / 2;
	env->yoff = env->h / 2;
	env->x0 = env->xoff;
	env->y0 = env->yoff;
}

void	zoom_reset(t_env *env)
{
	env->zoom = env->x0 / 2;
	env->zoom_step = env->x0 / 2;
}

void	coords_init(t_env *env)
{
	env->iter = 25;
	coords_reset(env);
	zoom_reset(env);
}

void	palette_init(t_env *env)
{
	int		i;
	double	gradient_step;

	i = 0;
	gradient_step = (double)0xFFFFFF / PALETTE_SIZE;
	while (i++ < PALETTE_SIZE)
		env->palette[i] = (unsigned int)(i * gradient_step);
}

void	zoom_update_view(int x, int y, t_env *env)
{
	env->xmin = (double)(x - env->xoff) / env->zoom;
	env->ymin = (double)(y - env->yoff) / env->zoom;
	env->xmax = (double)(x + env->xoff) / env->zoom;
	env->ymax = (double)(y + env->yoff) / env->zoom;
	env->xmult = (env->xmax - env->xmin) / fabs(env->xmax + env->xmin);
	env->ymult = (env->ymax - env->ymin) / fabs(env->ymax + env->ymin);
	env->x0 = (env->xmax + env->xmin) / 2;
	env->y0 = (env->ymax + env->ymin) / 2;
}
