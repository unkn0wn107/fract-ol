/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaley <agaley@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 18:22:46 by agaley            #+#    #+#             */
/*   Updated: 2023/08/16 01:08:53 by agaley           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	create_image(t_env *env)
{
	if (env->image)
		mlx_destroy_image(env->mlxptr, env->image);
	env->image = mlx_new_image(env->mlxptr, env->w, env->h);
	env->img_data = mlx_get_data_addr(env->image, &env->bpp, &env->sl, &env->e);
}

void	refresh_image(t_env *env)
{
	mlx_put_image_to_window(env->mlxptr, env->winptr, env->image, 0, 0);
}
