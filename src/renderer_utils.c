/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaley <agaley@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 21:10:26 by agaley            #+#    #+#             */
/*   Updated: 2023/08/02 01:42:36 by agaley           ###   ########lyon.fr   */
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

void	palette_change_color(t_env *env)
{
	if (env->color >= MIN_COLOR_SETS && env->color <= MAX_COLOR_SETS)
		env->color++;
	else
		env->color = MIN_COLOR_SETS;
	palette_init(env);
	render_fractal(env);
}

void	zoom_change_step(int key, t_env *env)
{
	if (key == KEY_PGUP && env->zoom_step < MAX_ZOOM)
		env->zoom_step += 10;
	else if (key == KEY_PGDOWN && env->zoom_step > 10)
		env->zoom_step -= 10;
}
