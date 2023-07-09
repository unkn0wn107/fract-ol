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
	(void)params;
	ft_printf("%d - appuyée\n", key);
	return (0);
}

int	main(int argc, char **argv)
{
	char	*inputstr;
	int		noparam;
	t_env	env;

	if (argc < 2)
		exit_error(20, NULL, NULL);
	noparam = 1;
	while (argv && --argc)
	{
		if (argc > 0 && argv[argc] && ft_strlen(argv[argc]) > 0)
			noparam = 0;
	}
	if (noparam == 1)
		exit(0);
	inputstr = parse_args(argv);
	env.mlxptr = mlx_init();
	env.winptr = mlx_new_window(env.mlxptr, 500, 500, "fract-ol");
	mlx_key_hook(env.winptr, handle_keys, &env);
	mlx_loop(env.mlxptr);
	free(inputstr);
	exit (0);
}
