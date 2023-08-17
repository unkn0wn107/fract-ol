/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaley <agaley@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 00:50:17 by agaley            #+#    #+#             */
/*   Updated: 2023/08/17 17:32:57 by agaley           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	handle_exit(int error, const char *msg, t_env *env)
{
	if (env)
	{
		if (env->hstr)
			free(env->hstr);
		if (env->wstr)
			free(env->wstr);
		if (env->xstr)
			free(env->xstr);
		if (env->ystr)
			free(env->ystr);
		if (env->img)
			mlx_destroy_image(env->mlxptr, env->img);
		if (env->winptr)
			mlx_destroy_window(env->mlxptr, env->winptr);
		if (env->mlxptr)
		{
			mlx_destroy_display(env->mlxptr);
			free(env->mlxptr);
		}
	}
	if (error == 0)
		exit(0);
	else
		ft_printf(msg);
	exit(1);
}
