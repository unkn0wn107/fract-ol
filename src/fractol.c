/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaley <agaley@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 01:41:58 by agaley            #+#    #+#             */
/*   Updated: 2023/06/28 17:57:35 by agaley           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	handle_keys(int key, void *params)
{
	if (key == KEY_ESC)
		handle_exit(0, params);
	ft_printf("%d - appuyée\n", key);
	return (0);
}

void	handle_zoom(int key, t_env *env)
{
	int	r;

	r = mlx_mouse_get_pos(env->mlxptr, env->winptr, &env->xm, &env->ym);
	if (r == 0 && env->xm == 0 && env->ym == 0)
		return ;
	env->xf = env->xm;
	env->yf = env->ym;
	if (key == MOUSE_UP && env->zoom <= MAX_ZOOM)
		env->zoom += 1;
	else if (key == MOUSE_DOWN && env->zoom >= 0)
		env->zoom -= 1;
	render_fractal(env);
}

int	handle_mouse(int key, void *params)
{
	if (key == MOUSE_UP || key == MOUSE_DOWN)
		handle_zoom(key, params);
	ft_printf("%d - souris\n", key);
	return (0);
}

int	main(int argc, char **argv)
{
	t_env	env;

	if (argc < 2)
		handle_exit(20, NULL);
	parse_args(argv, &env);
	env.mlxptr = mlx_init();
	env.winptr = mlx_new_window(env.mlxptr, 500, 500, "fract-ol");
	mlx_key_hook(env.winptr, handle_keys, &env);
	mlx_mouse_hook(env.winptr, handle_mouse, &env);
	mlx_loop(env.mlxptr);
	exit (0);
}
