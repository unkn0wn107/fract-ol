/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaley <agaley@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 18:25:14 by agaley            #+#    #+#             */
/*   Updated: 2023/08/15 04:33:52 by agaley           ###   ########lyon.fr   */
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
		palette_change_color(env);
	if (key == KEY_PGUP || key == KEY_PGDOWN)
		zoom_change_step(key, env);
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
int	handle_mouse(int key, int x, int y, void *param)
{
	t_env	*env;

	env = (t_env *)param;
	if (key == MOUSE_UP || key == MOUSE_DOWN)
		handle_zoom(key, x, y, env);
	return (0);
}
