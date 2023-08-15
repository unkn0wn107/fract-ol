/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaley <agaley@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 21:10:26 by agaley            #+#    #+#             */
/*   Updated: 2023/08/16 01:25:13 by agaley           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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
	env->x0 = (env->x0 + x - env->w) / env->wzoom;
	env->y0 = (env->y0 + y - env->h) / env->hzoom;
	env->wzoom = env->w * env->zoom * COEFF / env->h;
	env->hzoom = env->h * env->zoom * COEFF / env->w;
}
