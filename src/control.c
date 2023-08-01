/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaley <agaley@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 18:25:14 by agaley            #+#    #+#             */
/*   Updated: 2023/07/29 02:10:15 by agaley           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/**
 * Hook called by mlx_key_hook
 *
 * @param key key code which triggered this hook.
 * @param env Environment variables.
 *
 * @returns None
 */
int	handle_keys(int key, void *env)
{
	if (key == KEY_ESC)
		handle_exit(0, MSG_BYE, env);
	if (key == KEY_COLOR)
		change_color(env);
	if (key == KEY_PGUP || key == KEY_PGDOWN)
		change_zoom_step(key, env);
	render_fractal(env);
	ft_printf("%d - appuyée\n", key);
	return (0);
}

/**
 * Hook called by mlx_mouse_hook
 *
 * @param key key code which triggered this hook.
 * @param env Environment variables.
 *
 * @returns None
 */
int	handle_mouse(int key, void *param)
{
	t_env	*env;

	env = (t_env *)param;
	printf("env pointer in handle_mouse: %p - %d\n", env, env->h);
	if (key == MOUSE_UP || key == MOUSE_DOWN)
		handle_zoom(key, env);
	ft_printf("%d - souris\n", key);
	return (0);
}
