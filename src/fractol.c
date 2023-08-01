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

static void	init_env(t_env *env)
{
	env->w = WIN_WIDTH;
	env->h = WIN_HEIGHT;
	env->image = NULL;
	env->iter = 5;
	env->x0f = 0;
	env->y0f = 0;
	env->zoom = 1;
	palette_init(env);
}

int	main(int argc, char **argv)
{
	t_env	env;

	if (argc < 2)
		handle_exit(1, MSG_ERR_ARGS, NULL);
	init_env(&env);
	parse_args(argv, &env);
	env.mlxptr = mlx_init();
	if (!env.mlxptr)
		handle_exit(1, MSG_ERR_MLX_INIT, &env);
	env.winptr = mlx_new_window(env.mlxptr, env.w, env.h, (char *)"fract-ol");
	if (!env.winptr)
		handle_exit(1, MSG_ERR_WIN_INIT, &env);
	mlx_key_hook(env.winptr, handle_keys, &env);
	mlx_mouse_hook(env.winptr, handle_mouse, &env);
	mlx_loop(env.mlxptr);
	exit (0);
}
