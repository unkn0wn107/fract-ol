/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaley <agaley@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 18:22:46 by agaley            #+#    #+#             */
/*   Updated: 2023/08/15 04:53:08 by agaley           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	handle_zoom(int key, int x, int y, t_env *env)
{
	if (x == 0 && y == 0)
		return ;
	env->xm = x;
	env->ym = y;
	env->xf = env->xm;
	env->yf = env->ym;
	if (key == MOUSE_UP && env->zoom <= MAX_ZOOM)
		env->zoom += env->zoom_step;
	else if (key == MOUSE_DOWN)
	{
		if (env->zoom > env->zoom_step)
			env->zoom -= env->zoom_step;
		else if (env->zoom > 0)
			env->zoom = 0;
		else
			return;
	}
	render_fractal(env);
}

void	create_image(t_env *env)
{
	if (env->image)
		mlx_destroy_image(env->mlxptr, env->image);
	env->image = mlx_new_image(env->mlxptr, env->w, env->h);
	env->img_data = mlx_get_data_addr(env->image, &env->bpp, &env->sl, &env->e);
}

void	refresh_image(t_env *env)
{
	if (env->image)
		mlx_put_image_to_window(env->mlxptr, env->winptr, env->image, 0, 0);
}
