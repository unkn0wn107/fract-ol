/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaley <agaley@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 01:07:14 by agaley            #+#    #+#             */
/*   Updated: 2023/08/16 01:49:45 by agaley           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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

void	zoom_increment(int key, t_env *env)
{
	if (key == MOUSE_UP && env->zoom <= MAX_ZOOM)
		env->zoom += env->zoom_step;
	else if (key == MOUSE_DOWN)
	{
		ft_printf("%d\n", env->zoom);
		if (env->zoom > env->zoom_step)
			env->zoom -= env->zoom_step;
		else
			coords_init(env);
	}
}
