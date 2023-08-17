/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaley <agaley@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 18:22:46 by agaley            #+#    #+#             */
/*   Updated: 2023/08/17 17:32:20 by agaley           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	image_init(t_env *env)
{
	env->img = NULL;
	env->img_data = NULL;
}

void	image_create(t_env *env)
{
	if (env->img)
	{
		mlx_destroy_image(env->mlxptr, env->img);
		env->img = NULL;
	}
	env->img = mlx_new_image(env->mlxptr, env->w, env->h);
	if (!env->img)
		handle_exit(1, MSG_ERR_MEMORY, env);
	env->img_data = mlx_get_data_addr(env->img, &env->bpp, &env->sl, &env->e);
}

void	image_refresh(t_env *env)
{
	mlx_put_image_to_window(env->mlxptr, env->winptr, env->img, 0, 0);
}

void	plot(t_env *env, int x, int y, int color)
{
	int	pixel;

	pixel = y * env->sl + 4 * x;
	if (env->e == 1)
	{
		env->img_data[pixel + 0] = (color >> 24);
		env->img_data[pixel + 1] = (color >> 16) & 0xFF;
		env->img_data[pixel + 2] = (color >> 8) & 0xFF;
		env->img_data[pixel + 3] = (color) & 0xFF;
	}
	else if (env->e == 0)
	{
		env->img_data[pixel + 0] = (color) & 0xFF;
		env->img_data[pixel + 1] = (color >> 8) & 0xFF;
		env->img_data[pixel + 2] = (color >> 16) & 0xFF;
		env->img_data[pixel + 3] = (color >> 24);
	}
}
