/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaley <agaley@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 21:10:26 by agaley            #+#    #+#             */
/*   Updated: 2023/08/02 01:19:21 by agaley           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	palette_init(t_env *env)
{
	int	i;
	// int color;

	i = 0;
	while (i < PALETTE_SIZE)
	{
		env->palette[i] = i * (0xFFFFFF / PALETTE_SIZE); // Scale color to fit within palette size
		// env->palette[i] = mlx_get_color_value(env->mlxptr, color);
		i++;
	}
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
