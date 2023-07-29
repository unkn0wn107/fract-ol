/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaley <agaley@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 18:22:46 by agaley            #+#    #+#             */
/*   Updated: 2023/07/27 04:12:29 by agaley           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	handle_zoom(int key, t_env *env)
{
	int	r;

	r = mlx_mouse_get_pos(env->mlxptr, env->winptr, &env->xm, &env->ym);
	if (r == 0 && env->xm == 0 && env->ym == 0)
		return ;
	env->xf = env->xm;
	env->yf = env->ym;
	if (key == MOUSE_UP && env->zoom <= MAX_ZOOM)
		env->zoom += env->zoom_step;
	else if (key == MOUSE_DOWN && env->zoom > env->zoom_step)
		env->zoom -= env->zoom_step;
	render_fractal(env);
}

void	create_image(t_env *env)
{
	if (env->image)
		mlx_destroy_image(env->mlxptr, env->image);
	env->image = mlx_new_image(env->mlxptr, env->w, env->h);
}

void	refresh_image(t_env *env)
{
	mlx_put_image_to_window(env->mlxptr, env->winptr, env->image, 0, 0);
}
