/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaley <agaley@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 18:25:14 by agaley            #+#    #+#             */
/*   Updated: 2023/07/19 19:05:08 by agaley           ###   ########lyon.fr   */
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
		handle_exit(0, env);
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
int	handle_mouse(int key, void *env)
{
	if (key == MOUSE_UP || key == MOUSE_DOWN)
		handle_zoom(key, env);
	ft_printf("%d - souris\n", key);
	return (0);
}
