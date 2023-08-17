/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaley <agaley@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 18:25:14 by agaley            #+#    #+#             */
/*   Updated: 2023/08/17 05:57:13 by agaley           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/**
 * Hook called by mlx_key_hook
 *
 * @param key key code which triggered this hook.
 * @param param Environment variables passed has void* by mlx
 *
 * @returns None
 */
int	handle_keys(int key, void *param)
{
	t_env	*env;

	env = (t_env *)param;
	if (key == KEY_ESC)
		handle_exit(0, MSG_BYE, env);
	if (key == KEY_C)
		palette_change_color(env);
	if (key == KEY_ITER_INC)
		env->iter = env->iter + ITER_STEP;
	if (key == KEY_ITER_DEC && env->iter > ITER_STEP)
		env->iter = env->iter - ITER_STEP;
	if (key == KEY_A || key == KEY_W || key == KEY_D || key == KEY_S)
		move_increment(key, env);
	if (key == KEY_PGUP || key == KEY_PGDOWN)
		zoom_change_step(key, env);
	else
	{
		zoom_update_view(env->xoff, env->yoff, env);
		render_fractal(env);
	}
	ft_printf("%d - appuyée\n", key);
	return (0);
}

/**
 * Hook called by mlx_mouse_hook
 *
 * @param key key code which triggered this hook.
 * @param x mouse x coordinate
 * @param y mouse y coordinate
 * @param param Environment variables passed has void* by mlx
 *
 * @returns None
 */
int	handle_mouse(int key, int x, int y, void *param)
{
	t_env	*env;

	env = (t_env *)param;
	if (key == MOUSE_UP || key == MOUSE_DOWN)
		handle_zoom(key, x, y, env);
	return (0);
}

/**
 * Zoom handler
 *
 * @param key key code which triggered this hook.
 * @param x mouse x coordinate
 * @param y mouse y coordinate
 * @param env Environment variables.
 *
 * @returns None
 */
void	handle_zoom(int key, int x, int y, t_env *env)
{
	if (x == 0 && y == 0)
		return ;
	zoom_increment(key, env);
	zoom_update_view(x, y, env);
	render_fractal(env);
}
