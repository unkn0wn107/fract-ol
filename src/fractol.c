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

int	main(int argc, char **argv)
{
	t_env	env;

	if (argc < 2)
		handle_exit(1, NULL);
	env.w = 1918;
	env.h = 1024;
	parse_args(argv, &env);
	env.mlxptr = mlx_init();
	if (!env.mlxptr)
		handle_exit(1, &env);
	env.winptr = mlx_new_window(env.mlxptr, env.w, env.h, "fract-ol");
	if (!env.winptr)
		handle_exit(1, &env);
	mlx_key_hook(env.winptr, handle_keys, &env);
	mlx_mouse_hook(env.winptr, handle_mouse, &env);
	mlx_loop(env.mlxptr);
	exit (0);
}
