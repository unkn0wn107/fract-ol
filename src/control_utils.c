/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaley <agaley@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 01:07:14 by agaley            #+#    #+#             */
/*   Updated: 2023/08/17 06:14:48 by agaley           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	palette_change_color(t_env *env)
{
	if (env->color < MAX_COLOR_SETS)
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

void	zoom_increment(int key, t_env *env)
{
	if (key == MOUSE_UP && env->zoom <= MAX_ZOOM)
		env->zoom += env->zoom_step;
	else if (key == MOUSE_DOWN)
	{
		if (env->zoom > env->zoom_step)
			env->zoom -= env->zoom_step;
		else
			coords_init(env);
	}
}

void	move_increment(int key, t_env *env)
{
	if (key == KEY_A)
		env->xmove = env->xmove - 5.0 / env->zoom;
	if (key == KEY_D)
		env->xmove = env->xmove + 5.0 / env->zoom;
	if (key == KEY_W)
		env->ymove = env->ymove - 5.0 / env->zoom;
	if (key == KEY_S)
		env->ymove = env->ymove + 5.0 / env->zoom;
}
